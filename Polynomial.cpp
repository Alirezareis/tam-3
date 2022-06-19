//                                                               //
//                                                               //
//                                                               //
//                                                               //
//                      POLYNOMIAL CLASS                         //
//                         2022/06/04                            //
//                        ALIREZA REISI                          //
//                     AMIRHOSSEIN BAHRAMI                       //
//                                                               //
//                                                               //
//                                                               //
//                                                               //
//                                                               //
#include <fstream>
using namespace std;
class Polynomial // polynomial class
{
private:
    vector<Term> Terms;

public:
    Polynomial();
    Polynomial(float input);        // defualt float to polynomial convertor
    Polynomial(Term input);         // defualt term to polynomial convertor
    Polynomial(vector<Term> input); // defualt vector to polynomial convertor
    ~Polynomial();
    void sort(); // sort func for polynomial
    void push_back(Term input);
    void pop_back();
    void save(string file_name);
    void load(string file_name);
    void write(string file_name);
    void read(string file_name);
    int size();
    int power();
    Term operator[](int input) const;
    void operator=(Polynomial input);
    Polynomial operator+(Polynomial input) const;
    Polynomial operator*(Polynomial input) const;
    Polynomial operator/(Polynomial input) const;
    Polynomial operator-(Polynomial input) const;
    void operator+=(Polynomial input);
    void operator-=(Polynomial input);
    void operator*=(Polynomial input);
    void operator/=(Polynomial input);
    bool operator>(Polynomial input) const;
    bool operator<(Polynomial input) const;
    bool operator>=(Polynomial input) const;
    bool operator<=(Polynomial input) const;
    bool operator==(Polynomial input) const;
    bool operator!=(Polynomial input) const;
    Polynomial operator~() const;
    Polynomial operator++();
    Polynomial operator++(int);
    Polynomial operator--();
    Polynomial operator--(int);
    float operator()(float input);
    friend std::ostream &operator<<(std::ostream &out, Polynomial &input);
    friend std::istream &operator>>(std::istream &in, Polynomial &input);
    friend string &operator<<(string &out, Polynomial &input);
    friend Polynomial &operator<<(Polynomial &output, string &in);
};

Polynomial::Polynomial()
{
}
Polynomial::Polynomial(float input)
{
    Term term = input;
    Terms.push_back(input);
    Polynomial::sort();
}
Polynomial::Polynomial(Term input)
{
    Terms.push_back(input);
    Polynomial::sort();
}
Polynomial::Polynomial(vector<Term> input)
{
    Terms = input;
    Polynomial::sort();
}
Polynomial::~Polynomial()
{
}
void Polynomial::sort()
{
    for (size_t i = 0; i < Terms.size(); i++)
    {
        for (int j = i + 1; j < Terms.size(); j++)
        {
            if (Terms[i].get_p() < Terms[j].get_p())
            {
                Term temp = Terms[i];
                Terms[i] = Terms[j];
                Terms[j] = temp;
            }
            else if (Terms[i].get_p() == Terms[j].get_p())
            {
                Terms[i] += Terms[j];
                Terms.erase(Terms.begin() + j);
                j--;
            }
        }
    }
    for (size_t i = 0; i < Terms.size(); i++)
    {
        if (Terms[i].get_c() == 0)
        {
            Terms.erase(Terms.begin() + i);
            i--;
        }
    }
}
Term Polynomial::operator[](int input) const
{
    Term result;
    result = Terms[input];
    return result;
}
void Polynomial::operator=(Polynomial input)
{
    Terms = input.Terms;
    Polynomial::sort();
}
Polynomial Polynomial::operator+(Polynomial input) const
{
    Polynomial result;
    input.sort();
    result.Terms = Terms;
    result.sort();
    for (size_t i = 0; i < input.Terms.size(); i++)
    {
        result.Terms.push_back(input[i]);
        result.sort();
    }
    return result;
}
std::ostream &operator<<(std::ostream &out, Polynomial &input)
{
    for (size_t i = 0; i < input.size(); i++)
    {
        if (i > 0 && input[i].get_c() > 0)
        {
            out << "+";
        }

        out << input[i];
    }

    return out;
}
std::istream &operator>>(std::istream &in, Polynomial &input)
{
    Term term;
    string st, part = "";
    in >> st;
    for (size_t i = 0; i < st.size(); i++)
    {
        if ((st[i] == '+' || st[i] == '-') && i != 0)
        {
            part >> term;
            input.push_back(term);
            part = "";
        }
        part += st[i];
    }
    part >> term;
    input.push_back(term);
    return in;
}
Polynomial Polynomial::operator-(Polynomial input) const
{
    Polynomial result;
    input.sort();
    result.Terms = Terms;
    result.sort();
    for (size_t i = 0; i < input.Terms.size(); i++)
    {
        result.Terms.push_back(input[i] * (-1));
        result.sort();
    }
    return result;
}
Polynomial Polynomial::operator*(Polynomial input) const
{
    Polynomial result;
    input.sort();
    for (size_t i = 0; i < input.size(); i++)
    {
        for (size_t j = 0; j < Terms.size(); j++)
        {
            result.push_back(input[i] * (Terms[j]));
            result.sort();
        }
    }
    return result;
}
Polynomial Polynomial::operator/(Polynomial input) const
{
    Polynomial result, temp;
    temp.Terms = Terms;
    temp.sort();
    input.sort();
    int count;
    if (temp[0].get_p() >= input[0].get_p())
    {
        count = temp[0].get_p() - input[0].get_p() + 1;
    }
    else
    {
        count = input[0].get_p() - temp[0].get_p() + 1;
    }

    if (input.size() == 1)
    {
        for (size_t i = 0; i < temp.size(); i++)
        {
            result.push_back(temp[i] / input[0]);
        }
    }
    else if (input.size() > 1)
    {
        for (size_t i = 0; i < count; i++)
        {
            result.push_back(temp[0] / input[0]);
            temp = temp - (input * result);
            temp.sort();
        }
        if (temp.size() != 0)
        {
            throw "error:cant divide by input";
        }
    }
    return result;
}
void Polynomial::operator+=(Polynomial input)
{
    Polynomial::operator=(Polynomial::operator+(input));
}

void Polynomial::operator-=(Polynomial input)
{
    Polynomial::operator=(Polynomial::operator-(input));
}
void Polynomial::operator*=(Polynomial input)
{
    Polynomial::operator=(Polynomial::operator*(input));
}
void Polynomial::operator/=(Polynomial input)
{
    Polynomial::operator=(Polynomial::operator/(input));
}
bool Polynomial::operator==(Polynomial input) const
{
    bool result = true;
    Polynomial temp;
    temp.Terms = Terms;
    input.sort();
    temp.sort();
    if (input.size() != temp.size())
    {
        result = false;
    }
    else
    {
        for (size_t i = 0; i < input.size(); i++)
        {
            if (input[i] != temp[i])
            {
                result = false;
            }
        }
    }
    return result;
}

bool Polynomial::operator!=(Polynomial input) const
{
    bool result;
    result = Polynomial::operator==(input);
    return !result;
}

Polynomial Polynomial::operator++()
{
    Polynomial result;
    Term term;
    term.set_c(1);
    term.set_p(0);
    result.push_back(term);
    Polynomial::operator=(result);
    return result;
}

Polynomial Polynomial::operator++(int)
{
    Polynomial result;
    result.Terms = Terms;
    Term term;
    term.set_c(1);
    term.set_p(0);
    Terms.push_back(term);
    return result;
}

Polynomial Polynomial::operator--()
{
    Polynomial result;
    Term term;
    term.set_c(-1);
    term.set_p(0);
    result.push_back(term);
    Polynomial::operator=(result);
    return result;
}

Polynomial Polynomial::operator--(int)
{
    Polynomial result;
    result.Terms = Terms;
    Term term;
    term.set_c(-1);
    term.set_p(0);
    Terms.push_back(term);
    return result;
}

Polynomial Polynomial::operator~() const
{
    Polynomial result, temp;
    temp.Terms = Terms;
    for (size_t i = 0; i < temp.size(); i++)
    {
        result.push_back(~temp[i]);
    }
    result.sort();
    return result;
}
bool Polynomial::operator>(Polynomial input) const
{
    bool result = true;
    input.sort();
    Polynomial temp = Terms;
    temp.sort();
    int i = 0;
    if (input.size() < temp.size())
    {
        while (result && i < input.size())
        {
            if (temp[i] < input[i])
            {
                result = false;
            }
            i++;
        }
    }
    else
    {
        while (result && i < temp.size())
        {
            if (temp[i] < input[i])
            {
                result = false;
            }
            i++;
        }
        Polynomial copy;
        for (size_t i = 0; i < temp.size(); i++)
        {
            copy.push_back(input[i]);
        }
        if (copy == temp)
        {
            result = false;
        }
    }

    return result;
}
bool Polynomial::operator<(Polynomial input) const
{
    bool result = false;
    if (!(Polynomial::operator>(input)) && Polynomial::operator!=(input))
    {
        result = true;
    }
    return result;
}
bool Polynomial::operator>=(Polynomial input) const
{
    bool result = false;
    if (!(Polynomial::operator<(input)))
    {
        result = true;
    }
    return result;
}
bool Polynomial::operator<=(Polynomial input) const
{
    bool result = false;
    if (!(Polynomial::operator>(input)))
    {
        result = true;
    }
    return result;
}
float Polynomial::operator()(float input)
{
    float result;
    Polynomial::sort();
    for (size_t i = 0; i < Terms.size(); i++)
    {
        result += Terms[i](input);
    }
    return result;
}
int Polynomial::power()
{
    Polynomial::sort();
    return Terms[0].get_p();
}
void Polynomial::save(string file_name) // save to text file
{
    file_name += ".txt";
    ofstream file(file_name);
    file.clear();
    Polynomial temp = Terms;
    file << temp;
    file.close();
}
void Polynomial::load(string file_name) // load from text file
{
    file_name += ".txt";
    ifstream file(file_name);
    if (!file)
    {
        throw "error:file not found";
    }
    else
    {
        Polynomial temp;
        file >> temp;
        Polynomial::operator=(temp);
        file.close();
    }
}
void Polynomial::write(string file_name) // write to binary file
{
    file_name += ".dat";
    Polynomial temp = Terms;
    string s;
    s << temp;
    unsigned int size = s.length();
    ofstream file;
    file.open(file_name, ios::out | ios::binary);
    file.clear();
    file.write((char *)(&size), sizeof(size));
    file.write(s.c_str(), size);
    if (!file.good())
    {
        throw "error:writing to file was not sucessful";
    }

    file.close();
}
void Polynomial::read(string file_name) // read from binary file
{
    file_name += ".dat";
    ifstream file;
    if (!file)
    {
        throw "error:file not found";
    }
    else
    {
        if (!file.good())
        {
            throw "error:file is damaged";
        }
        Polynomial temp;
        string s;
        unsigned int size;
        file.open(file_name, ios::in | ios::binary);
        file.read((char *)(&size), sizeof(size));
        s.resize(size);
        file.read((char *)(s.c_str()), size);
        temp << s;
        Polynomial::operator=(temp);
        file.close();
    }
}
string &operator<<(string &out, Polynomial &input) // conveting polynomial to string
{
    ofstream temp("temp.text");
    temp << input;
    temp.close();
    ifstream tem("temp.text");
    tem >> out;
    tem.close();
    remove("temp.text");
    return out;
}
Polynomial &operator<<(Polynomial &output, string &in) // conveting string to polynomial
{
    ofstream temp("temp.text");
    temp << in;
    temp.close();
    ifstream tem("temp.text");
    tem >> output;
    tem.close();
    remove("temp.text");
    return output;
}
