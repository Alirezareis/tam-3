#include <iostream>
#include <vector>
#include <windows.h>
#include "../tamrin3/Term.h"
#include "../tamrin3/Polynomial.h"
#include <fstream>
using namespace std;
int main()
{
    string t[2] = {"false", "true"};
    Polynomial current = 0;
    int entry;
    do
    {
        system("cls");
        string a;
        cout << "main menu" << endl
             << endl;
        cout << "1.new polynomial" << endl;
        cout << "2.load from text file" << endl;
        cout << "3.load from binary file" << endl;
        cout << "4.quit" << endl
             << endl;
        cout << "enter your choice:" << endl;
        cin >> entry;
        if (entry == 1)
        {

            int entry1;
            do
            {
                system("cls");
                cout << "current polynomial: " << current << endl
                     << endl;
                cout << "1.Add" << endl;
                cout << "2.Subtract" << endl;
                cout << "3.Multiply" << endl;
                cout << "4.Derivatve" << endl;
                cout << "5.Find Degree" << endl;
                cout << "6.Find value For Specific x" << endl;
                cout << "7.Compare" << endl;
                cout << "8.Save to a text file " << endl;
                cout << "9.Save to a binary file" << endl;
                cout << "10.back to Main Menu" << endl
                     << endl;
                cout << "enter your choice:" << endl;
                cin >> entry1;
                if (entry1 == 1)
                {
                    system("cls");
                    Polynomial temp;
                    try
                    {
                        cout << "enter the polynomial that you want to add: " << endl;
                        cin >> temp;
                        current += temp;
                    }
                    catch (const char *e)
                    {
                        std::cerr << e << endl;
                        cout << "going back to polynomial menu in : 3";
                        Sleep(1000);
                        cout << "\b2";
                        Sleep(1000);
                        cout << "\b1";
                        Sleep(1000);
                        cout << "\b0" << endl;
                    }
                }
                else if (entry1 == 2)
                {
                    system("cls");
                    Polynomial temp;
                    try
                    {
                        cout << "enter the polynomial that you want to substract: " << endl;
                        cin >> temp;
                        current -= temp;
                    }
                    catch (const char *e)
                    {
                        std::cerr << e << endl;
                        cout << "going back to polynomial menu in : 3";
                        Sleep(1000);
                        cout << "\b2";
                        Sleep(1000);
                        cout << "\b1";
                        Sleep(1000);
                        cout << "\b0" << endl;
                    }
                }
                else if (entry1 == 3)
                {
                    system("cls");
                    Polynomial temp;
                    try
                    {
                        cout << "enter the polynomial that you want to multiply: " << endl;
                        cin >> temp;
                        current *= temp;
                    }
                    catch (const char *e)
                    {
                        std::cerr << e << endl;
                        cout << "going back to polynomial menu in : 3";
                        Sleep(1000);
                        cout << "\b2";
                        Sleep(1000);
                        cout << "\b1";
                        Sleep(1000);
                        cout << "\b0" << endl;
                    }
                }
                else if (entry1 == 4)
                {
                    current = ~current;
                }
                else if (entry1 == 5)
                {
                    system("cls");
                    cout << "polynominals degree is " << current.power() << endl;
                    cout << "going back to polynomial menu in : 3";
                    Sleep(1000);
                    cout << "\b2";
                    Sleep(1000);
                    cout << "\b1";
                    Sleep(1000);
                    cout << "\b0" << endl;
                }
                else if (entry1 == 6)
                {
                    float x;
                    cout << "enter the number you want to put in polynomial: ";
                    cin >> x;
                    system("cls");
                    cout << "value for " << x << " is " << current(x) << endl;
                    cout << "going back to polynomial menu in : 3";
                    Sleep(1000);
                    cout << "\b2";
                    Sleep(1000);
                    cout << "\b1";
                    Sleep(1000);
                    cout << "\b0" << endl;
                }
                else if (entry1 == 7)
                {
                    system("cls");
                    Polynomial temp;
                    cout << "enter the polynomial that you want to compare with current polynomial:";
                    cin >> temp;
                    cout << "current_polynomial:" << current << endl;
                    cout << "other_polynomial:" << temp << endl;
                    cout << "current_polynomial > other_polynomial:" << t[current > temp] << endl;
                    cout << "current_polynomial >= other_polynomial:" << t[current >= temp] << endl;
                    cout << "current_polynomial < other_polynomial:" << t[current < temp] << endl;
                    cout << "current_polynomial <= other_polynomial:" << t[current <= temp] << endl;
                    cout << "current_polynomial == other_polynomial:" << t[current == temp] << endl;
                    cout << "going back to polynomial menu in : 9";
                    for (int i = 8; i >= 0; i--)
                    {
                        Sleep(1000);
                        cout << "\b" << i;
                    }
                    cout << endl;
                }
                else if (entry1 == 8)
                {
                    system("cls");
                    string filename;
                    try
                    {
                        cout << "enter the filename  for saving in text file: ";
                        cin >> filename;
                        current.save(filename);
                        cout << "saving";
                        Sleep(1000);
                        cout << ".";
                        Sleep(1000);
                        cout << ".";
                        Sleep(1000);
                        cout << "." << endl;
                    }
                    catch (const char *e)
                    {
                        std::cerr << e << endl;
                        cout << "going back to polynomial menu in : 3";
                        Sleep(1000);
                        cout << "\b2";
                        Sleep(1000);
                        cout << "\b1";
                        Sleep(1000);
                        cout << "\b0" << endl;
                    }
                }
                else if (entry1 == 9)
                {
                    system("cls");
                    string filename;
                    try
                    {
                        cout << "enter the filename for saving in binary file: ";
                        cin >> filename;
                        current.write(filename);
                        cout << "saving";
                        Sleep(1000);
                        cout << ".";
                        Sleep(1000);
                        cout << ".";
                        Sleep(1000);
                        cout << "." << endl;
                    }
                    catch (const char *e)
                    {
                        std::cerr << e << endl;
                        cout << "going back to polynomial menu in : 3";
                        Sleep(1000);
                        cout << "\b2";
                        Sleep(1000);
                        cout << "\b1";
                        Sleep(1000);
                        cout << "\b0" << endl;
                    }
                }
            } while (entry1 != 10);
            // system("cls");
        }
        else if (entry == 2)
        {
            system("cls");
            string namefile;
            cout << "enter name of text file: ";
            cin >> namefile;

            try
            {

                current.load(namefile);
            }
            catch (const char *e)
            {
                std::cerr << e << endl;
                cout << "going back to main menu in : 3";
                Sleep(1000);
                cout << "\b2";
                Sleep(1000);
                cout << "\b1";
                Sleep(1000);
                cout << "\b0" << endl;
            }
        }
        else if (entry == 3)
        {
            system("cls");
            string namefile;
            cout << "enter name of binary file: ";
            cin >> namefile;
            try
            {
                current.read(namefile);
            }
            catch (const char *e)
            {
                std::cerr << e << endl;
                cout << "going back to main menu in : 3";
                Sleep(1000);
                cout << "\b2";
                Sleep(1000);
                cout << "\b1";
                Sleep(1000);
                cout << "\b0" << endl;
            }
        }
    } while (entry != 4);

    // Term a;
    // Term b;
    // Polynomial c,d;
    // cin>>d;
    // cout<<d<<endl;

    system("pause");
    return 0;
}
