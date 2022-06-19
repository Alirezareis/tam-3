//                                                               //                   
//                                                               //                   
//                                                               //                   
//                                                               //                   
//                         TERM CLASS                            //                                 
//                         2022/06/04                            //                                
//                        ALIREZA REISI                          //                          
//                     AMIRHOSSEIN BAHRAMI                       //                             
//                                                               //                   
//                                                               //                   
//                                                               //                   
//                                                               //                   
//                                                               //
bool check_input(std::string input);
class Term // Term class for third tamrin
{
private:
    float c; // c(x^p)
    int p; // c(x^p)

public:
    Term(); //default constructor
    Term(float fl, int pow); 
    Term(float fl); //default float to Term convertor
    ~Term();
    float get_c();
    int get_p();
    void set_c(float input);
    void set_p(int input);
    Term operator+(Term input) const; 
    Term operator-(Term input) const;
    Term operator*(Term input) const;
    Term operator/(Term input) const;
    void operator=(Term input);
    void operator+=(Term input);
    void operator-=(Term input);
    void operator*=(Term input);
    void operator/=(Term input);
    bool operator>(Term input) const;
    bool operator<(Term input) const;
    bool operator>=(Term input) const;
    bool operator<=(Term input) const;
    bool operator==(Term input) const;
    bool operator!=(Term input) const;
    Term operator~() const;
    Term operator++();
    Term operator++(int);
    Term operator--();
    Term operator--(int);
    float operator()(float input);
    friend std::ostream &operator<<(std::ostream &out, Term input);
    friend std::istream &operator>>(std::istream &in, Term &input);
};

Term::Term()
{
    p = 0;
    c = 0;
}
Term::Term(float fl, int pow)
{
    p = pow;
    c = fl;
}
Term::Term(float fl)
{
    p = 0;
    c = fl;
}

Term::~Term()
{
}
Term Term::operator+(Term input) const
{
    Term result;
    if (p == input.get_p())
    {
        result.set_c(c + input.get_c());
        result.set_p(p);
    }
    else
    {
        throw "error:different powers";
    }
    return result;
}
Term Term::operator-(Term input) const
{
    Term result;
    if (p == input.get_p())
    {
        result.set_c(c - input.get_c());
        result.set_p(p);
    }
    else
    {
        throw "error:different powers";
    }
    return result;
}
Term Term::operator*(Term input) const
{
    Term result;
    result.set_c(c * input.get_c());
    result.set_p(p + input.get_p());
    return result;
}
Term Term::operator/(Term input) const
{
    Term result;
    if (input.get_c() != 0)
    {
        result.set_c(c / input.get_c());
        result.set_p(p - input.get_p());
    }
    else
    {
        throw "error:divided by 0";
    }
    return result;
}
void Term::operator=(Term input)
{
    c = input.get_c();
    p = input.get_p();
}
void Term::operator+=(Term input)
{
    Term::operator=(Term::operator+(input));
}
void Term::operator-=(Term input)
{
    Term::operator=(Term::operator-(input));
}
void Term::operator*=(Term input)
{
    Term::operator=(Term::operator*(input));
}
void Term::operator/=(Term input)
{
    Term::operator=(Term::operator/(input));
}
bool Term::operator>(Term input) const
{
    bool result = false;
    if ((p > input.get_p()&& ( c>0 || c > input.get_c() ) ) || (p == input.get_p() && c > input.get_c()))
    {
        result = true;
    }
    return result;
}
bool Term::operator<(Term input) const
{
    bool result = false;
    if (!(Term::operator>=(input)))
    {
        result = true;
    }
    return result;
}
bool Term::operator>=(Term input) const
{
    bool result = false;
    if (Term::operator>(input) || Term::operator==(input))
    {
        result = true;
    }
    return result;
}
bool Term::operator<=(Term input) const
{
    bool result = false;
    if (!(Term::operator>(input)))
    {
        result = true;
    }
    return result;
}
bool Term::operator==(Term input) const
{
    bool result = false;
    if (c == input.get_c() && p == input.get_p())
    {
        result = true;
    }
    return result;
}
bool Term::operator!=(Term input) const
{
    bool result = !(Term::operator==(input));
    return result;
}
Term Term::operator~() const
{
    Term result;
    result.set_c(c * p);
    result.set_p(p - 1);
    return result;
}
Term Term::operator++()
{
    Term result = Term::operator+(1);
    Term::operator=(result);
    return result;
}
Term Term::operator++(int)
{
    Term result = Term::operator*(1);
    Term::operator=(Term::operator+(1));
    return result;
}
Term Term::operator--()
{
    Term result = Term::operator-(1);
    Term::operator=(result);
    return result;
}
Term Term::operator--(int)
{
    Term result = Term::operator*(1);
    Term::operator=(Term::operator-(1));
    return result;
}
float Term::operator()(float input)
{
    int power;
    float result = 1;
    if (p < 0)
    {
        power = -p;
    }
    else
    {
        power = p;
    }

    for (int i = 0; i < power; i++)
    {
        if (p >= 0)
        {
            result *= input;
        }
        else
        {
            result /= input;
        }
    }
    result *= c;
    return result;
}
std::ostream &operator<<(std::ostream &out, Term input)
{
    if (input.get_c() != 1 || input.get_p() == 0)
    {
        if (input.get_c() == -1 && input.get_p()!=0)
        {
            out << "-";
        }
        else
        {
            out << input.get_c();
        }
    }
    if (input.get_p() != 0 && input.get_c() != 0)
    {
        out << "x";
    }
    if (input.get_p() != 1 && input.get_p() != 0 && input.get_c() != 0)
    {
        out << "^" << input.get_p();
    }
    return out;
}
std::istream &operator>>(std::istream & in, Term &input)
{
    std::string temp, part1, part2;
        in >> temp;
        if (!check_input(temp))
        {
            throw "error:invalid input";
        }
    int i, x = -1;
    for (i = 0; i < temp.size(); i++)
    {
        if (temp[i] == 'x')
        {
            x = i;
        }
    }
    if (x == -1)
    {
        input.set_c(std::stoi(temp));
        input.set_p(0);
    }
    else if (x == 0 || temp[x - 1] == '+')
    {
        input.set_c(1);
    }
    if (x == temp.size() - 1)
    {
        input.set_p(1);
    }
    if (temp[x - 1] == '-')
    {
        input.set_c(-1);
    }

    if (x == temp.size() - 1 && x != 0 && temp[x - 1] != '-' && temp[x - 1] != '+')
    {
        for (i = 0; i < x; i++)
        {
            part1 += temp[i];
        }
        input.set_c(std::stoi(part1));
    }
    if (x == 0 && x != temp.size() - 1)
    {
        for (i = x + 2; i < temp.size(); i++)
        {
            part2 += temp[i];
        }
        input.set_p(std::stoi(part2));
    }
    if (x != 0 && x != temp.size() - 1 && x != -1)
    {
        if (temp[x - 1] != '-' && temp[x - 1] != '+')
        {
            for (i = 0; i < x; i++)
            {
                part1 += temp[i];
            }
            input.set_c(std::stoi(part1));
        }

        for (i = x + 2; i < temp.size(); i++)
        {
            part2 += temp[i];
        }
        input.set_p(std::stoi(part2));
    }
    return in;
}
bool check_input(std::string input) //checking if input is equal to a term
{
    bool result = true;
    int x = -1, power = -1, countx = 0, countp = 0;

    for (size_t i = 0; i < input.size(); i++)
    {
        if (!((input[i] >= '0' && input[i] <= '9') || input[i] == '+' || input[i] == '-' || input[i] == 'x' || input[i] == '^'))
        {
            result = false;
        }
    }
    for (size_t i = 0; i < input.size(); i++)
    {
        if (input[i] == 'x')
        {
            x = i;
            countx++;
        }
    }
    for (size_t i = 0; i < input.size(); i++)
    {
        if (input[i] == '^')
        {
            power = i;
            countp++;
        }
    }
    if (countx > 1 || countp > 1)
    {
        result = false;
    }

    if (x != -1 && x + 1 != power && power != -1)
    {
        result = false;
    }
    if (x == -1 && countp != 0)
    {
        result = false;
    }
    if (x != -1 && x != input.size() - 1 && input[x + 1] != '^')
    {
        result = false;
    }

    return result;
}
Term &operator>>(std::string & in, Term &input) // converting string to term
{
    std::string temp, part1, part2;
        temp=in;
        if (!check_input(temp))
        {
            throw "error:invalid input";
        }
    int i, x = -1;
    for (i = 0; i < temp.size(); i++)
    {
        if (temp[i] == 'x')
        {
            x = i;
        }
    }
    if (x == -1)
    {
        input.set_c(std::stoi(temp));
        input.set_p(0);
    }
    else if (x == 0 || temp[x - 1] == '+')
    {
        input.set_c(1);
    }
    if (x == temp.size() - 1)
    {
        input.set_p(1);
    }
    if (temp[x - 1] == '-')
    {
        input.set_c(-1);
    }

    if (x == temp.size() - 1 && x != 0 && temp[x - 1] != '-' && temp[x - 1] != '+')
    {
        for (i = 0; i < x; i++)
        {
            part1 += temp[i];
        }
        input.set_c(std::stoi(part1));
    }
    if (x == 0 && x != temp.size() - 1)
    {
        for (i = x + 2; i < temp.size(); i++)
        {
            part2 += temp[i];
        }
        input.set_p(std::stoi(part2));
    }
    if (x != 0 && x != temp.size() - 1 && x != -1)
    {
        if (temp[x - 1] != '-' && temp[x - 1] != '+')
        {
            for (i = 0; i < x; i++)
            {
                part1 += temp[i];
            }
            input.set_c(std::stoi(part1));
        }

        for (i = x + 2; i < temp.size(); i++)
        {
            part2 += temp[i];
        }
        input.set_p(std::stoi(part2));
    }
    return input;
}