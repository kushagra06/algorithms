/*Implementation of counting sort
 * Stable sort
 * It assumes that each of the n i/p elements is an integer in the range 0 to k. When k=O(n), the sort runs in theta(n) time.
 */

#include<stdio.h>
int main()
{
    int n,i;
//    printf("Enter no. of elements: ");
    scanf("%d",&n);
    int a[n+1],c[1001],b[n+1];
    
    for(i=0;i<1001;i++)
        c[i]=0;
    
  //  printf("Enter %d elements (b/w 0 and 1000):\n",n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    
    for(i=1;i<=n;i++)
        c[a[i]]=c[a[i]]+1;
    
    for(i=1;i<1000;i++)
        c[i]=c[i]+c[i-1];
        
    for(i=n;i>=1;i--)
    {
        b[c[a[i]]]=a[i];
        c[a[i]]=c[a[i]]-1;
    }
    
    for(i=1;i<=n;i++)
        printf("%d ",b[i]);
    printf("\n");
    
    return 0;
}
