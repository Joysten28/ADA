#include<stdio.h>
#include<time.h>
void main()
{
  int n,i,j,min,temp;
  printf("Enter the size of the array: ");
  scanf("%d",&n);
  int a[n];
  srand(time(NULL));
  for(i=0;i<n;i++)
  {
    a[i]=rand()%25000;
  }
  /*printf("The random array is ");
  for(i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
  printf("\n");*/
  clock_t start=clock();
  for(i=0;i<n;i++)
  {
    min=i;
    for(j=i+1;j<n;j++)
    {
      if(a[j]<a[min])
      {
        min=j;
      }
    }
    temp=a[min];
    a[min]=a[i];
    a[i]=temp;
    }
    clock_t end=clock();
    double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("The time taken is %f\n",time_taken);
    /*printf("The final array\n");
    for(i=0;i<n;i++)
    {
       printf("%d ",a[i]);
    }
    printf("\n");*/
   }