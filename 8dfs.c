#include <stdio.h>
#include <stdlib.h>

int visited[20]={0};

void createmat(int m[10][10],int n)
{
    int i,j;
    char ans;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            m[i][j]=0;
            if(i!=j)
            {
                printf("Is ther an edge between %d and %d(1/0):",i+1,j+1);
                scanf("%d",&m[i][j]);
            }
        }
    }
}

void dispmat(int m[10][10],int n)
{
    int i,j;
    char ans;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d \t",m[i][j]);
        }
        printf("\n");
    }
}

void dfs(int m[10][10],int i,int n)
{
    int j;
    printf("%d",i);
    visited[i]=1;
    for(j=0;j<n;j++)
    {
        if(m[i][j]==1 && !visited[j])
        {
            dfs(m,j,n);
        }
    }
}

void main()
{
    int m[10][10];
    int n;
    printf("Enter the no. of vertices \n");
    scanf("%d",&n);
    createmat(m,n);
    dispmat(m,n);
    dfs(m,0,n);
}