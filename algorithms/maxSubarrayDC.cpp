#include <bits/stdc++.h>
using namespace std;
typedef long long        ll;
typedef vector<int>      vi;
typedef pair<int, int>   ii;
typedef vector<ii>       vii;
typedef set<int>         si;
typedef map<string, int> msi;

#define REP(i, a, b) for(int i=a; i <= int(b); i++) 
#define TRvi(c, it) for(vi::iterator it = c.begin(); it != c.end(); it++)
#define TRvii(c, it) for(vii:iterator it = c.begin(); it != c.end(); it++)
#define TRmsi(c, it) for(msi::iterator it = c.begin(); it != c.end(); it++)

#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distance
//memset(dp_memo, -1, sizeof dp_memo); // usefull to initialize DP memoization table 
//memset(arr, 0, sizeof arr); //useful to clear array of integers

ll crossSubarray(int a[], int low, int mid, int high)
{
    int leftsum = INT_MIN;
    int sum = 0;
    for(int i = mid; i>=low; i--)
    {
        sum += a[i];
        if(sum > leftsum)
            leftsum = sum;
    }
    sum = 0;
    int rightsum = INT_MIN;
    REP(i, mid+1, high)
    {
        sum += a[i];
        if(sum > rightsum)
            rightsum = sum;
    }
    return (leftsum + rightsum);
}

ll maxSubarray(int a[], int low, int high)
{
    int mid, lsum, rsum, crossum;
    if(low == high)
        return a[low];
    else
    {
        mid = (low+high)/2;
        lsum = maxSubarray(a, low, mid);
        rsum = maxSubarray(a, mid+1, high);
        crossum = crossSubarray(a, low, mid, high);
        if(lsum > rsum && lsum > crossum)
            return lsum;
        else if(rsum > lsum && rsum > crossum)
            return rsum;
        else
            return crossum;
    }
}

int main()
{
    int n,m;
    scanf("%d",&n);
    int a[n];
    REP(i, 0, n-1)
    { 
        scanf("%d",&a[i]);
    }
    ll s = maxSubarray(a, 0, n-1);
    printf("%lld\n",s);
    return 0;
}
