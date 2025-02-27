#include<stdio.h>
#define MAX 100
void merge_sort(int arr[],int low,int up);
void merge(int arr[],int temp[],int low1,int up1, int low2, int up2);
void copy(int arr[],int temp[],int low,int up);
int main()
{
    int i,n,arr[MAX];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("Enter Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    merge_sort(arr,0,n-1);
    printf("\nSorted list is: \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t", arr[i]);
    }

  return 0;
}
void merge_sort(int arr[], int low, int up)
{
    int mid;
    int temp[MAX];
    if(low<up)
    {
        mid = (low+up)/2;
        merge_sort(arr,low,mid); //sort arr[low:mid]
        merge_sort(arr,mid+1,up); //sort arr[mid+1:up]
        //merge arr[low:mid] and arr[mid+1:up] to temp[low:up]
        merge(arr,temp,low,mid,mid+1,up);
        copy(arr,temp,low,up);   //copy temp[low:up] to arr[low:up]
    }
}
void merge(int arr[], int temp[], int low1, int up1, int low2, int up2)
{
    int i = low1;
    int j = low2;
    int k = low1;
    while((i<=up1) && (j<=up2))
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i<=up1)
        temp[k++] = arr[i++];
    while(j<=up2)
        temp[k++] = arr[j++];
}
void copy(int arr[], int temp[], int low, int up)
{
    int i;
    for(i=low;i<=up;i++)
    {
        arr[i]=temp[i];
    }
}
