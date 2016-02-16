/*Implementation of quicksort
 * Sorts in place
 * Applies the divide and conquer paradigm
 * Partition the array such that the pivot is in its correct place
 */

#include<stdio.h>

void swap(int *X,int *Y)
{
    int hold=*X;
    *X=*Y;
    *Y=hold;
}

void quicksort(int a[],int p,int r)
{
    if(p<r)
    {
        int q=partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}

int partition(int a[],int p,int r)
{
    int x=a[r];
    int i=p-1, j;
    for(j=p;j<r;j++)
    {
        if(a[j]<=x)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[r]);
    return i+1;
}

int main()
{
    int n, i;
    scanf("%d",&n);
    int a[n+1];
    a[0]='\0';
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);

    quicksort(a,1,n);

    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n");

    return 0;
}

