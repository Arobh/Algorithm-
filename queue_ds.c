/* QUEUE DATA STRUCTURE IMPLEMENTATION USING AN ARRAY... */

#include<stdio.h>
#include<stdbool.h>

#define MAX 6

int arr[MAX];
int front = 0;
int rear = -1;
int count = 0;

int peek(){
   if(count==0){
      printf("\nQueue is empty...\n");
   }
   else
   return arr[front];
}

bool isEmpty(){
   if(count==0)
      return true;
    else
      return false;
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

void Enqueue(int data){
   if(!isFull()) {
      rear++;
      arr[rear]=data;
      count++;
   }
   else
     printf("\nOverflow...\n");
}

int Dequeue() {
   
   if(!isEmpty()) {
       int data=arr[front];
	    front++;
       count--;
       return data;  
   }
   else
     printf("\nUnderflow...");
   
}
int main(){
   printf("The size of the Queue implemented using an array is %d",MAX);
   int choice;
   do{
       printf("\nEnter 1 for INSERTION i.e. ENQUEUE in Queue...\n");
       printf("Enter 2 for DELETION i.e. DEQUEUE in Queue...\n");
       printf("Enter 3 to stop...\n");
       printf("Enter 4 for Printing all element by  deleting all element...\n");
       
       printf("Enter your choice: ");
       scanf("%d",&choice);
       switch (choice){
          case 1:
            int x;
            printf("\nEnter how many insertion operations you want to perform: ");
            scanf("%d",&x);
            for(int i=0;i<x;i++){
                if(!isFull()){
                   int data;
                   printf("Enter the %d data to insert: ",i+1);
                   scanf("%d",&data);
                   Enqueue(data);
                 }
                 else{
                  printf("\nQueue is full i.e. cannot be inserted...\n");
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
                   int data;
                   data=Dequeue();
                   printf("\nThe %d deleted element is %d.\n",i+1,data);
               }
               else{
                  printf("\nQueue is empty i.e. cannot be deleted...\n");
                  break;
               }
            }
            break;
          case 4:
               while(true){
                  if(!isEmpty()){
                   int data;
                   data=Dequeue();
                   printf("\nThe deleted element is %d.\n",data);
               }
               else{
                  printf("\nQueue is empty i.e. cannot be deleted...\n");
                  break;
               }
               }
               break;
          default:
               break;     
       }
   }while(choice!=3);

   return(0);
   
}