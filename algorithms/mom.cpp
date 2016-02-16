#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int partition(vector<int> &a,int p,int r,int mom)
{
    int pivot=mom;
//    cout << "pivot: " << a[pivot] << endl;
    int i=p-1;
    for(int j=p;j<r;j++)
    {
        if(a[j]<=a[pivot])
        {
            i++;
            iter_swap(&a[i],&a[j]);
        }
    }
    iter_swap(&a[i],&a[pivot]);
    return i;
}

int select(vector<int> &a,int s,int e,int k)
{
    if(e-s+1<=5)
    {
        sort(a.begin()+s,a.begin()+e);
        return s+k-1;
    }

    for(int i=0;i<(e)/5;i++)
    {
        int l=5*i;
        int r=l+4;
        if(r>e)r=e;
        int median=select(a,5*i,5*i+4,3);
        iter_swap(&a[median],&a[i]);
    }
//    for(int i=0;i<e;i++)
  //      cout << a[i] << endl;
    
    int mom = select(a,0,(e)/5,(e)/10);
    int l=partition(a,0,n,mom);
 //   cout << "l " << l << endl;
  //  cout << "k " << k << endl;
   // cout << "mom "<< mom << endl;
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    cout << "\n";
    if(l==k-1)
        return a[l];
    else if(k<=l)
        select(a,0,l,k);
    else if(k>l+1)
        select(a,l+1,n,k-l-1);
}


int main()
{
    int k,ans;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    ans=select(a,0,n,k);
    cout << ans << endl;   
    sort(a.begin(),a.end());
    cout << a[k-1] << endl;
    return 0;
}
