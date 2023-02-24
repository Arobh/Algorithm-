/* LINKED LIST DATA STRUCTURE IMPLEMENTATION ALONG WITH OPERATIONS LIKE INSERTION, DELETION, TRAVERSE... */
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;
node *start=NULL;
node *getnode(){ 
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\nEnter the data:");
    scanf("%d",&newnode->data);
    newnode->next==NULL;
    return(newnode);
}
void create_linkedlist(){
    node *temp,*last;
    int n_node;
    printf("\nEnter the no. of nodes:");
    scanf("%d",&n_node);
    int ctr=1;
    while(ctr<=n_node){
        temp=getnode();
        if(start==NULL){
            start=temp;
            last=temp;
        }
        else{
            last->next=temp;
            last=temp;
        }
        ctr++;
    }
}
void traverse(){
    node *temp;
    temp=start;
    if(start==NULL){
        printf("\nLInked list is empty...");
    }
    else{
        printf("\nThe linked list nodes elements are: \n");
        while(temp!=NULL){
            printf("%d  ",temp->data);
            temp=temp->next;
        }
    }
}
int count_node(){
    node *temp;
    temp=start;
    int count=0;
    if(start==NULL){
        return(0);
    }
    else{
        while(temp!=NULL){
            count+=1;
            temp=temp->next;
        }
        return(count);
    }
}
void insert_at_beg(){
    node*newnode;
    newnode=getnode();
    if(start==NULL){
        start=newnode;
    }
    else{
        newnode->next=start;
        start=newnode;
    }
}
void insert_at_end(){
    node*newnode;
    newnode=getnode();
    if(start==NULL){
        start=newnode;
    }
    else{
        node*temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }   
}
void insert_at_mid(int pos){
    node*newnode;
    newnode=getnode();
    if(start==NULL){
        start=newnode;
    }
    else{
        node*temp,*prev;
        int ctr=1;
        temp=prev=start;
        while(ctr<pos){
            prev=temp;
            temp=temp->next;
            ctr++;
        }
        prev->next=newnode;
        newnode->next=temp;
    }
}
void delete_at_beg(){
    if(start==NULL){
        printf("\nLinked list is empty...");
        return;
    }
    else{
        node*temp;
        temp=start;
        start=start->next;
        printf("\nDeleted element: %d\n",temp->data);
        free(temp);
    }
}
void delete_at_end(){
    node*temp,*prev;
    if(start==NULL){
        printf("\nLinked list is empty...");
        return;
    }
    else{
        temp=prev=start;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        printf("\nDeleted element: %d\n",temp->data);
        free(temp);
    }
}
void delete_at_mid(int pos){
    if(start==NULL){
        printf("\nLinked list is empty...");
        return;
    }
    else{
        node*temp,*prev;
        temp=prev=start;
        int ctr=1;
        while(ctr<pos){
            prev=temp;
            temp=temp->next;
            ctr++;
        }
        prev->next=temp->next;
        printf("\nDeleted element: %d\n",temp->data);
        free(temp);
    }
}

int main(){
    printf("let's start by creating the Linked list\n");
    create_linkedlist();
    printf("\nYou have created the linked list... of size %d:\n",count_node());
    traverse();
    int choice;
    do{
        printf("\nEnter 1  for Insertion:\n");
        printf("Enter 2 for Deleltion:\n");
        printf("Enter 4 for Traversal:\n");
        printf("Enter 5 to stop:\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
           int x;
           printf("\nEnter how many Insertion you want to perform: ");
           scanf("%d",&x);
           int pos;
           for(int i=0;i<x;i++){
              int c=count_node();
              printf("\n0th postion means at starting\n");
              printf("%d postion means at last\n",c);
              printf("Any postion between 1 and %d is the middle\n",c); 
              printf("\nEnter the postion where you want to insert:");
              scanf("%d",&pos);
              int m=count_node();
              if(pos>=0||pos<=m){
                if(pos==0)
                  insert_at_beg();
                else if(pos==m)
                  insert_at_end();
                else
                  insert_at_mid(pos);      
              }
              else{
                printf("\nInvalid position for insertion...");
              }
           }
           break;
        case 2:
           int y;
           printf("Enter how many Deletion you want to perform: ");
           scanf("%d",&y);
           int q;
           for(int i=0;i<y;i++){ 
              int count=count_node();
              printf("\n1st postion means at starting\n");
              printf("%d postion means at last\n",count);
              printf("Any postion between 1 and %d is the middle\n",count); 
              printf("\nEnter the postion where you want to delete:");
              scanf("%d",&q);
              int l=count_node();
              if(q>0||q<=l){
                if(q==1)
                  delete_at_beg();
                else if(q==l)
                  delete_at_end();
                else
                  delete_at_mid(q);      
              }
              else{
                printf("\nInvalid position for Deletion...");
              }
           }
           break;
        case 4:
           traverse();
           break;
        default:
           break; 
        }        
    }while(choice!=5);
    return(0);
}