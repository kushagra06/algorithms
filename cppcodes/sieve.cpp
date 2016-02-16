#include<iostream>
#include<cmath>
#include<bitset>
using namespace std;

int main()
{
    const int SIZE=1024;
    int val;
    bitset<SIZE> sieve;
    sieve.flip();
    sieve.reset(0);
    sieve.reset(1);
    //  int finalBit=sqrt(static_cast<double>(sieve.size())) + 1;
    int finalBit=sqrt(sieve.size())+1;
    for(int i=2;i<finalBit;i++)
    {
        if(sieve.test(i))
        {
            for(int j=2*i;j<SIZE;j+=i)
                sieve.reset(j);
        }
    }
    for(int i=0;i<SIZE;i++)
        cout << i << " " << sieve[i] << "\n";
    int x;
    cin >> x;
    if(sieve[x])
        cout << x << " is a prime\n";
    else
    {
        int y=x;
        cout << "Not a prime\n";
        cout << "Prime factors:\n";
        while(y!=1)
        {
            for(int i=2;i<=x/2;i++)
            {
                if(sieve.test(i) && y%i==0)
                {
                    cout << i << " ";
                    y=y/i;
                }
            }
        }
        cout << endl;
    }
    return 0;
}





