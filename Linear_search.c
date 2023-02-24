/* LINEAR SEARCH IN AN ARRAY */
#include<stdio.h>
int linear_search(int arr[],int n,int key);
int main(){
    int n;
    printf("Enter the size of an array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array of %d size:---\n",n);
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
       printf("\n%d time...\nEnter the key you want to search in the array: ",p);
       else
       printf("\n%d times...\nEnter the key you want to search in the array: ",p);
       scanf("%d",&key);
       int y=linear_search(arr,n,key);
       if(y==-1)
         printf("%d is not present in the array\n",key);
       else
         printf("%d is present in the array at index %d\n",key,y);
       p++;  
    }   
    return(0);  
}
int linear_search(int arr[],int n,int key){
    for(int i=0;i<n;i++){
         if(arr[i]==key)
            return(i);
    }
    return(-1);
}