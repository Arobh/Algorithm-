/* MERGE SORT IN AN ARRAY */
#include <stdio.h>
void merge(int arr[], int p, int q, int r) {
    
  int n1=q-p+1;
  int n2=r-q;

  int L[n1],M[n2];

  for (int i=0;i<n1;i++)
    L[i]=arr[p + i];
  for (int j=0;j<n2;j++)
    M[j]=arr[q+1+j];

  int i=0, j=0, k=p;
  while (i<n1&&j<n2){
    if(L[i]<=M[j]){
      arr[k]=L[i];
      i++;
    } 
    else{
      arr[k]=M[j];
      j++;
    }
    k++;
  }
  while(i<n1){
    arr[k]=L[i];
    i++;
    k++;
  }

  while(j<n2){
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l<r){
    int m=(r+l)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
  return;
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
  mergeSort(arr, 0, size - 1);
  printf("\nSorted array: \n");
  printArray(arr, size);
}