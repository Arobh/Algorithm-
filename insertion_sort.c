/* INSERTION SORT IN AN ARRAY... */
#include<stdio.h>
void insertion_Sort(int arr[],int n){
    int i;
    for(i=1;i<n;i++){
        int var=arr[i];
        int j=i-1;
        while(var<arr[j]&&j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=var;
    }
}

void printArray(int arr[],int size) {
  for (int i=0;i<size;i++)
    printf("%d ", arr[i]);
}

int main() {
  int size;
  printf("Enter the size of the array: ");
  scanf("%d",&size);
  int arr[size];
  printf("Enter the elements of array: \n");
  for(int i=0;i<size;i++){
      printf("Enter %d element: ",i+1);
      scanf("%d",&arr[i]);
  }
  printf("You have entered the following: \n");
  for(int i=0;i<size;i++){
      printf("%d  ",arr[i]);
  }
  insertion_Sort(arr,size);
  printf("\nSorted array: \n");
  printArray(arr, size);
}