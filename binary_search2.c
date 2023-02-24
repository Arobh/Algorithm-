/* BINARY SEARCH IN AN ARRAY ITERATIVE METHOD */
#include<stdio.h>
int binary_search(int arr[],int i,int j,int key){
    int mid;
    while(i<=j){
        mid=(i+j)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]>key){
            j=mid-1;
        }
        else{
            i=mid+1;
        }
    }
    return(-1);
}
int main(){
    int n;
    printf("Enter the size of an array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements in sorted manner in order of binary search to work:\n");
    for(int i=0;i<n;i++){
        printf("Enter %d element: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("You have entered the following elements: ");
    for(int i=0;i<n;i++)
       printf("%d  ",arr[i]);
    int x;
    printf("\n\nEnter the number of times you want to perform search operation: ");
    scanf("%d",&x);
    int p=1;
    while(p<=x){
       int key;
       if(p==1)
       printf("\n%d time...\nEnter the key you want to search in the sorted array: ",p);
       else
       printf("\n%d times...\nEnter the key you want to search in the sorted array: ",p);
       scanf("%d",&key);
       int y=binary_search(arr,0,n,key);
       if(y==-1)
         printf("%d is not present in the array\n",key);
       else
         printf("%d is present in the array at index %d\n",key,y);
       p++;  
    }
    return(0);  
}