#include <iostream>
using namespace std;
typedef struct nodetype{
    int info;
    struct nodetype *next;
}node;
void insertatbeg(node **start,int item){
    node *ptr;
    ptr=(node*)malloc(sizeof(node));
    ptr->info=item;
    ptr->next=NULL;
    if (*start==NULL){
        *start=ptr;
    }
    else{
        ptr->next=*start;
        *start=ptr;
    }
}
void insertatend(node **start,int item){
    node *ptr,*temp;
    ptr=(node*)malloc(sizeof(node));
    ptr->info=item;
    ptr->next=NULL;
    if(*start==NULL){
        *start=ptr;
    }
    else{
        temp=*start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ptr;
    }
}
void display(node *start){
    if(start==NULL){
        cout<<"linked list is empty"<<endl;
        return;
    }
    else{
        while(start!=NULL){
            cout<<start->info;
            start=start->next;
        }
    }
}
void deleteatbeg(node **start){
    node *ptr;
    if (*start==NULL){
        cout<<"Linked list is empty"<<endl;
        return;
    }
    else{
        ptr=*start;
        *start=ptr->next;
        cout<<"Deleted item is"<<ptr->info<<endl;
    }
    free(ptr);
}
void deleteatend(node **start){
    node *ptr,*last;
    if(*start==NULL){
        cout<<"Linked list is empty"<<endl;
        return;
    }
    else{
        last=*start;
        while((last->next)->next!=NULL){
            last=last->next;
        }
        ptr=last->next;
        cout<<"deleted item is "<<ptr->info<<endl;
        last->next=NULL;
    }
    free(ptr);
}
void insertafterpos(node **start,int item,int after){
    node *ptr,*temp;
    ptr=(node*)malloc(sizeof(node));
    ptr->info=item;
    ptr->next=NULL;
    if (*start==NULL){
        *start=ptr;
    }
    else{
        temp=*start;
        while((after-1)>0){
            temp=temp->next;
            after--;
        }
        ptr->next=temp->next;
        temp->next=ptr;
    }
}
void deleteafterpos(node **start,int after){
    node *ptr,*temp;
    if(*start==NULL){
        cout<<"Linked list is empty"<<endl;
        return;
    }
    else{
        temp=*start;
        while((after-1)>0){
            temp=temp->next;
            after--;
        }
        ptr=temp->next;
        cout<<"deleted value is "<<ptr->info<<endl;
        temp->next=NULL;
    }
    free(ptr);
}
int main(){
    node *start;
    int choice,item,after;
    while(1){
        cout<<"Welcome to Linked list program"<<endl;
        cout<<"enter your choice"<<endl;
        cout<<"1.Insert at beginning"<<endl;
        cout<<"2.Insert at end"<<endl;
        cout<<"3.Delete at beginning"<<endl;
        cout<<"4.Delete at end "<<endl;
        cout<<"5.Display"<<endl;
        cout<<"6.Insert after position"<<endl;
        cout<<"7.Delete after position"<<endl;
        cout<<"8.Exit"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"Enter item"<<endl;
            cin>>item;
            insertatbeg(&start,item);
            break;
            case 2:
            cout<<"Enter item"<<endl;
            cin>>item;
            insertatend(&start,item);
            break;
            case 3:
            deleteatbeg(&start);
            break;
            case 4:
            deleteatend(&start);
            break;
            case 5:
            display(start);
            break;
            case 6:
            cout<<"Enter item "<<endl;
            cin>>item;
            cout<<"Enter position"<<endl;
            cin>>after;
            insertafterpos(&start,item,after);
            break;
            case 7:
            cout<<"Enter position"<<endl;
            cin>>after;
            deleteafterpos(&start,after);
            break;
            default:
            exit(1);
        }
    }
return 0;
}