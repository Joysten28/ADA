#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b)
{
   int temp=*a;
   *a=*b;
   *b=temp;
}
int partition(int arr[],int low,int high)
{
  int pivot=arr[low];
  int i=low+1;
  int j=high;
  while(i<=j)
  {
    while(i<=high&&arr[i]<=pivot)
    i++;
    while(arr[j]>pivot)
    j--;
    if(i<j)
    swap(&arr[i],&arr[j]);
  }
  swap(&arr[low],&arr[j]);
  return j;
}
void quicksort(int arr[],int low,int high)
{
  if(low<high)
  {
    int pi=partition(arr,low,high);
    quicksort(arr,low,pi-1);
    quicksort(arr,pi+1,high);
  }
}
int main()
{
   int n,i;
   printf("Enter the number of elements");
   scanf("%d",&n);
   int arr[n];
   srand(time(NULL));
   for(i=0;i<=n;i++)
   {
      arr[i]=rand()%10000000;
   }
   clock_t start=clock();
   quicksort(arr,0,n-1);
   clock_t end=clock();
   double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
   printf("Time taken for sorting:%f seconds\n",time_taken);
   return 0;
}
