/*Implementation of insertion sort
 * Sorts in-place: it rearranges the nos. within the input array A
 * key: nos. to be sorted
 * AUTHOR: Kushagra Chandak
 */

#include<stdio.h>
int main()
{
    int n,i,key,j;
//    printf("Enter no. of elements to be sorted (keys): ");
    scanf("%d",&n); //scanning no. of elements to be sorted
    int A[n];
  //  printf("Enter %d nos.:\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);  //scanning elements
    for(j=1;j<n;j++)        //insertion sort
    {
        key=A[j]; //insert A[j] into the sorted seq. A[1...j-1]
        i=j-1;
        while(i>=0 && A[i]>key)
        {
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
    }
  //  printf("Sorted array:\n");//printing final sorted array
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
    return 0;
}



