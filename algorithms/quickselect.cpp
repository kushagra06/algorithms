#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int temp,mom;
vector<int> m;

int partition(vector<int> &a,int p,int r,int mom)
{
    int pivot=mom;
    int i=p-1,j;
    for(j=p;j<r;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            iter_swap(&a[i],&a[j]);
        }
    }
    swap(a[i+1],pivot);
    return i+1;
}

int select(vector<int> &a,int n,int k,int left,int right)
{
    int flag=0;
    if(n>1)
    {
        for(int i=left;i<right;i+=5)
        {
            if(i+5<=right)
                sort(a.begin()+i,a.begin()+i+5);
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            sort(a.begin()+i,a.begin()+right);
        for(int i=0;i<right;i++)
            cout << "a "<< a[i] << endl;
        for(int i=0;i<right;i+=5)
            m.push_back(a[2+i]);
        for(int i=0;i<ceil(right/5);i++)
            cout << "m " << m[i] << endl;
        temp=right;
        mom=select(m,n,k,0,ceil(right/5));
    }
    else
    {
        cout << "temp " << temp << endl;
        sort(m.begin(),m.begin()+temp-1);
        for(int i=0;i<temp;i++)
            cout << "M " << m[i] << endl;
        mom=m[(temp/2)-1];
    }
    
    int pivot_idx=partition(a,0,n-1,mom);
    cout << pivot_idx << endl;
    if(pivot_idx==k-1)
        return a[pivot_idx];
    else if(k < pivot_idx)
        select(a,n,k,0,pivot_idx-1);
    else
        select(a,n,k,pivot_idx+1,n);
    
}


int main()
{
    int n,k,ans;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    ans=select(a,n,k,0,n);
    cout << ans << endl;
    return 0;
}
