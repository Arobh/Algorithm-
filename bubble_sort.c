/* BUBBLE SORT IN AN ARRAY... WITHOUT FLAG */
#include<stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_Sort(int arr[],int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
        }
      }
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
  bubble_Sort(arr,size);
  printf("\nSorted array: \n");
  printArray(arr, size);
}