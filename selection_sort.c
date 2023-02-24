/* SELECTION SORT IN AN ARRAY...  */
#include<stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selection_Sort(int arr[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        int ind=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[ind])
              ind=j;

            swap(&arr[ind],&arr[i]);  
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
  selection_Sort(arr,size);
  printf("\nSorted array: \n");
  printArray(arr, size);
}