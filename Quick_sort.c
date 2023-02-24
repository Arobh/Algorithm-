/* QUICK SORT IN AN ARRAY */
#include<stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[],int l,int h){
     int pivot,i,j;
     pivot=arr[l];
     i=l;
     for(j=l+1;j<=h;j++){
         if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
         }
     }
     swap(&arr[i],&arr[l]);
     return(i);

}
void quick_Sort(int arr[],int i,int j){
    if(i<j){
        int p=partition(arr,i,j);
        quick_Sort(arr,i,p-1);
        quick_Sort(arr,p+1,j);
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
  quick_Sort(arr, 0, size - 1);
  printf("\nSorted array: \n");
  printArray(arr, size);
}