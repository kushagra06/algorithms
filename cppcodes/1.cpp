#include<iostream>
#include<string>
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    unsigned short age;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Your age is ";
    cout << age << endl;
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "The string you entered is ";
    cout << s << endl;
    cout << "Literal Constants:" << endl;
    int x=75u; //decimal
    int y=0113; //octal
    int z=0x4b; //hexadecimal
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    float a=6.02e23;
    cout << a << endl;
    float b=1.6e-19;
    cout << b << endl;
    cout << "\?" << endl;
    string t;
    cout << "Enter a line: \n";
    getline (cin,t);
    string::const_iterator i=t.end();
    while(i!=t.begin())
    {
        cout << *i;
        --i;
    }
    cout << endl;
    cout << "The entered string is " << t << "\nOkay!" << endl;
    cout << "     *\n";
    for(int i=1;i<=5;i++)
    {
        for(int j=5-i;j>=1;j--)
            cout << " ";
        cout << "*";
        for(int j=1;j<=2*i-1;j++)
            cout << " ";
        cout << "*\n";
    }
    for(int i=4;i>=1;i--)
    {
        for(int j=5-i;j>=1;j--)
            cout << " ";
        cout << "*";
        for(int j=1;j<=2*i-1;j++)
            cout << " ";
        cout << "*\n";
    }
    cout << "     *\n";
    for ( int i = 1; i <= 5; ++i )
    {
        for ( int j = 1; j <= 3; ++j )
        {
            for ( int k = 1; k <= 4; ++k )
                cout << '*';
            cout << endl;
        } // end inner for
        cout << endl;
    } // end outer for
    return 0;
}
