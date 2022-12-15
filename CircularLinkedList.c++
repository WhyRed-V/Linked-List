#include <iostream>
using namespace std;
typedef struct nodetype{
    int info;
    struct nodetype *next;
}node;
void insertatbeg(node **start,int item){
    node *ptr,*temp;
    ptr=(node*)malloc(sizeof(node));
    ptr->info=item;
    if(*start==NULL){
        *start=ptr;
        ptr->next=*start;
    }
    else{
        temp=*start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        ptr->next=*start;
        *start=ptr;
        temp->next=*start;
    }
}
void insertatend(node **start,int item){
    node *ptr,*temp;
    ptr=(node*)malloc(sizeof(node));
    ptr->info=item;
    if(*start==NULL){
        *start=ptr;
        ptr->next=*start;
    }
    else{
        temp=*start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=*start;
    }
}
void deleteatbeg(node **start){
    node *ptr,*temp;
    if(*start==NULL){
        cout<<"Linked list is empty"<<endl;
        return;
    }
    if(*start==*start->next){
        *start==NULL;
    }
    else{
        ptr=*start;
        while(ptr->next!=*start){
            ptr=ptr->next;
        }
        ptr->next=*start->next;
        *start=ptr->next;
        free(ptr);
    }
    void deleteatend(node **start){
        node *ptr;
        if (*start==NULL){
            cout<<"linked List is empty"<<endl;
            return;
        }
        if(*start->next==*start){
            *start=NULL;
        }
        else{
            ptr=*start;
            while((ptr->next)->next!=*start){
                ptr=ptr->next;
            }
            free(ptr->next);
            ptr->next=*start;
        }
    }