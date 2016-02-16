/*Implement mergesort
 * Divide and conquer
 * Merge: Imp. step
 */
#include<stdio.h>
int temp[100000];

void merge(int a[],int s,int mid,int e)
{
    int p1=mid-s+1,p2=e-mid;
    int i,j,k;
    int l[p1+1],r[p2+1];//left and right arrays
  
    for(i=1;i<=p1;i++)
        l[i]=a[s+i-1];
    
    for(j=1;j<=p2;j++)
        r[j]=a[mid+j];
    
    l[p1+1]=999999;
    r[p2+1]=999999;
    i=1,j=1;
    for(k=s;k<=e;k++)//comparing left and right arrays to get final sorted array
    {
        if(l[i]<=r[j])
            a[k]=l[i++];
        else
            a[k]=r[j++];
    }
}


void mergesort(int a[],int s,int e)//to divide array and to call merge
{
    if(s<e)
    {
        int mid=(s+e)/2;
        mergesort(a,s,mid);
        mergesort(a,mid+1,e);
        merge(a,s,mid,e);
    }
}

int main()
{
    int n;
    scanf("%d",&n);//scan total no. of elements
    int a[100000];
    int i;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);//scan nos.
    mergesort(a,1,n);      
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);//print final sorted array
    printf("\n");
    return 0;
}
