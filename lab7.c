#include<stdio.h>
#define MAX_ITEMS 10
int knapSack(int w,int wt[],int val[],int n)
  {
    int i,j;
    int v[MAX_ITEMS+1][w+1];
    for(i=0;i<=n;i++)
    {
      for(j=0;j<=w;j++)
      {
        if(i==0||j==0)
        {
          v[i][j]=0;
        }
        else if(j-wt[i]<0)
        {
          v[i][j]=v[i-1][j];
        }
        else
        {
          v[i][j]=max(v[i-1][j],val[i]+v[i-1][j-wt[i]]);
        }
      }
    }
    return v[n][w];
  }
  int max(int a,int b)
  {
     return(a>b)?a:b;
  }
void main()
{
  int i,n,w,wt[MAX_ITEMS],val[MAX_ITEMS];
  printf("Enter the value of n");
  scanf("%d",&n);
  printf("Enter the Maximum capacity");
  scanf("%d",&w);
  printf("Enter the weight:\n");
  for(i=1;i<=n;i++)
  {
    scanf("%d",&wt[i]);
  }
  printf("Enter the values:\n");
  for(i=1;i<=n;i++)
  {
     scanf("%d",&val[i]);
  }
  printf("the maximum profit is %d",knapSack(w,wt,val,n));
  printf("\n");
}  
        