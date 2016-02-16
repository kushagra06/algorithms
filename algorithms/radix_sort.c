/*Implementation of radix sort
 * Uses counsort (or any stable sort) as a subroutine
 * Takes theta(d(n+k)) time if the stable sort it uses takes theta(n+k) time. (k = No. of possible values of each digit)
 */


#include<stdio.h>
int c[10],n;

void countsort(int a[],int b[],int d)
{
    int i;
    for(i=0;i<10;i++)
        c[i]=0;
    int digit[n+1];
    int j;
    for(i=1;i<=n;i++)
    {
        int x=a[i];
        for(j=1;j<d;j++)
            x=x/10;
        digit[i]=x%10;
    }
/*    for(i=1;i<=n;i++)
        printf("digit: %d ",digit[i]);
    printf("\n");*/
    for(i=1;i<=n;i++)
        c[digit[i]]++;
    
    for(i=1;i<10;i++)
        c[i]=c[i]+c[i-1];
    
    for(i=n;i>=1;i--)
    {
        b[c[digit[i]]]=a[i];
        c[digit[i]]--;
    }
    for(i=1;i<=n;i++)
        a[i]=b[i];
}

int main()
{
    int i,d;
//    printf("Enter total elements: ");
    scanf("%d",&n);
    int a[n+1],b[n+1];
  //  printf("Enter d (no. of digits of each number): ");
    scanf("%d",&d);
   // printf("Enter %d elements: \n",n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=d;i++)
        countsort(a,b,i);
    for(i=1;i<=n;i++)
        printf("%d ",b[i]);
    printf("\n");
    return 0;
}
    

