#include <iostream>
using namespace std;
typedef struct nodetype{
    int info;
    struct nodetype *prev;
    struct nodetype *next;
}node;
void insertatbeg(node **start,node **end,int item){
    node *ptr;
    ptr=(node*)malloc(sizeof(node));
    ptr->info=item;
    ptr->prev=NULL;
    if(*start==NULL){
        ptr->next=NULL;
        *start=*end=ptr;
    }
    else{
        ptr->next=*start;
        (*start)->prev=ptr;
        *start=ptr;
    }
}
void insertatend(node **start,node **end,int item){
    node*ptr;
    ptr=(node*)malloc(sizeof(node));
    ptr->next=NULL;
    ptr->info=item;
    if(*start==NULL){
        ptr->prev=NULL;
        *start=*end=ptr;
    }
    else{
        ptr->prev=*end;
        (*end)->next=ptr;
        *end=ptr;
    }
}
void deleteatbeg(node **start,node **end){
    node *ptr;
    if (*start==NULL){
        cout<<"Linked list is empty"<<endl;
        return;
    }
    if((*start)->next==NULL){
        *start=NULL;
        free(ptr);
    }
    else{
        ptr=*start;
        *start=ptr->next;
        (*start)->prev=NULL;
    }
}
void deleteatend(node **start,node **end){
    node *ptr;
    if (*start==NULL){
        cout<<"linked list is empty"<<endl;
        return;
    }
    if((*start)->next==NULL){
        *start=NULL;
        free(ptr);
    }
    else{
        ptr=*end;
        *end=ptr->prev;
        (*end)->next=NULL;
    }
}