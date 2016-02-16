#include<iostream>
using namespace std;

int main()
{
    static int a=1;
    int x;
    a++;
    cout << a << endl;
    main();
    return 0;
}
