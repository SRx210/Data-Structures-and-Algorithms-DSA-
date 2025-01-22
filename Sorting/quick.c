#include<stdio.h>
#define MAX 100
void quicksort(int arr[100],int low,int up){
   int i, j, pivot, temp;
   if(low<up){
      pivot=low;
      i=low;
      j=up;
      while(i<j){
         while(arr[i]<=arr[pivot]&&i<low)
         i++;
         while(arr[j]>arr[pivot])
         j--;
         if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }
      temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;
      quicksort(arr,low,j-1);
      quicksort(arr,j+1,up);
   }
}
int main()
{
   int i, n, arr[MAX];
   printf("Enter number of elements: ");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
     printf("Enter elements %d: ", i+1);
     scanf("%d",&arr[i]);
   }
   quicksort(arr,0,n-1);
   printf("Sorted elements are: \n");
   for(i=0;i<n;i++)
   {
     printf("%d\t",arr[i]);
   }
   return 0;
}
