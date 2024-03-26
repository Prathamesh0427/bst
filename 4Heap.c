#include <stdio.h>
#include <stdlib.h>

void display(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d \t",arr[i]);
    }
}
void heapify(int a[],int top,int last)
{
    int j,temp,key;
    key=a[top];
    j=2*top+1;
    if((j<last) && (a[j]<a[j+1]))
        j=j+1;
    if((j<=last) && (key<a[j]))
    {
        temp=a[top];
        a[top]=a[j];
        a[j]=temp;
        heapify(a,j,last);
    }
}

void buildheap(int a[],int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
        heapify(a,i,n-1);
}

void heapsort(int a[],int n)
{
    int i,temp,top=0,last;
    buildheap(a,n);
    printf("Initial Heap =");
    display(a,n);
    for(last=n-1;last>=1;last--)
    {
        temp=a[top];
        a[top]=a[last];
        a[last]=temp;
        printf("\n After Iteration %d:",n-last);
        display(a,n);
        heapify(a,top,last-1);
    }
}

int main()
{
    int a[8]={26,5,77,1,61,11,59,15};
    heapsort(a,8);
    printf("\nThe sorted elements are:");
    display(a,8);
    return 0;
}