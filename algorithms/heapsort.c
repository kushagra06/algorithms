/*Implement heapsort
 * AUTHOR: Kushagra Chandak
 * Time complexity: O(n*lg(n))
 * Given an unsorted array, first build min-heap and then extract min. element by lazy deletion and then run heapify
 */

#include<stdio.h>
int sz=0,n;

void swap(int *p,int *q)
{
    int hold=*p;
    *p=*q;
    *q=hold;
}

void min_heapify(int A[],int i)
{
    int min;
    if(2*i<=sz && A[2*i]<A[i]){//if left child is smaller than parent, make it as min (the index of lchild)
        min=2*i;
    }
    else
        min=i;
    if(2*i+1<=sz && A[2*i+1]<A[min]){// if right child is smaller than min then make it min (the index of rchild)
        min=2*i+1;
    }
    if(min!=i)
    {
        swap(&A[i],&A[min]);
        min_heapify(A,min);
    }
}

void build_min_heap(int A[],int n)
{
    int i;
    for(i=sz/2;i>=1;i--)  //O(n) and not O(n*lg(n))
        min_heapify(A,i);
}

void heapsort(int A[],int n)
{ 
    int x,i;
    while(sz!=0)
    {
        x=A[1];
        printf("%d ",x);
        swap(&A[1],&A[sz]);
        --sz;
        min_heapify(A,1);
    }
    printf("\n");
}

int main()
{
    int i;
    scanf("%d",&n);//input no. of elements
    int A[n+1];
    sz=n;
    A[0]='\0';
    for(i=1;i<=n;i++)
        scanf("%d",&A[i]);//enter elements
    build_min_heap(A,n);
    heapsort(A,n);
    return 0;
}


