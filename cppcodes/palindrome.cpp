#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    ostream_iterator<int> output(cout," ");
    for(int i=0;i<n;i++)
        cin >> a[i];
    int j=n-1;
    int flag=0;
    for(int i=0;i<=n/2;i++)
    {
        if(a[i]!=a[j])
        {
            flag=1;
            break;
        }
        else
            j--;
    }
    if(flag==1)
        cout << "Not a palindrome\n";
    else
        cout << "Palindrome\n";

    return 0;
}
