/* STACK DATA STRUCTURE IMPLEMENTATION USING AN ARRAY... */
#include<stdio.h>
#include<stdbool.h>

#define MAX 6

int arr[MAX];
int top=-1;
int count=0;

bool isEmpty(){
   if(top==-1)
      return true;
    else
      return false;
}

int peek(){
   if(!isEmpty()) 
   return arr[top];
   else
     printf("\nStack is empty...\n");
}

bool isFull(){
   if(count==MAX)
    return true;
    else
    return false;
}

int size(){
   return count;
} 

void push(){
   int data;
   printf("\nEnter the data to push: ");
   scanf("%d",&data);

   if(!isFull()) {
      top++;
      arr[top]=data;
      count++;
   }
   else
     printf("\nOverflow...\n");
}

void pop() {
   
   if(!isEmpty()) {
       int data=arr[top];
	    top--;
       count--;
       printf("\nDeleted data is %d ",data); 
   }
   else
     printf("\nUnderflow...");
   
}

int main(){
   printf("The size of the Stack implemented using an array is %d",MAX);
   int choice;
   do{
       printf("\nEnter 1 for INSERTION i.e. PUSH() in Stack...\n");
       printf("Enter 2 for DELETION i.e. POP() in Stack...\n");
       printf("Enter 3 for  PEEK() operation...\n");
       printf("Enter 4 for Printing all element by  deleting all element...\n");
       printf("Enter 5 to stop...\n");
       
       printf("Enter your choice: ");
       scanf("%d",&choice);
       switch (choice){
           case 1:
            int x;
            printf("\nEnter how many insertion operations you want to perform: ");
            scanf("%d",&x);
            for(int i=0;i<x;i++){
                if(!isFull()){
                  push();
                 }
                 else{
                  printf("\nSatck is full i.e. cannot be inserted...\n");
                  break;
                 }
            }    
            break;
          case 2:
            int y;
            printf("\nEnter how many Deletion operations you want to perform: ");
            scanf("%d",&y);
            for(int i=0;i<y;i++){
               if(!isEmpty()){
                   pop();
               }
               else{
                  printf("\nStack is empty i.e. cannot be deleted...\n");
                  break;
               }
            }
            break;
          case 3:
            peek();
            break;  
          case 4:
               while(true){
                  if(!isEmpty()){
                   pop();
               }
               else{
                  printf("\nStack is empty i.e. cannot be deleted...\n");
                  break;
               }
               }
               break;
          default:
               break;     
       }
   }while(choice!=5);

   return(0);
   
}