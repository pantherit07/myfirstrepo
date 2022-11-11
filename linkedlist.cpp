#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
class singlelist{
    node* head;
    public:
    singlelist(){
        head=NULL;
    }
    void insertatstart(int val){
        node* nn=new node;
        nn->data=val;
        nn->next=head;
        head=nn;
    }
    void insertatend(int val){
        node* nn=new node;
        nn->data=val;
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nn;
        nn->next=NULL;
    }
    void insertatpos(int val,int aftval){
        node* nn=new node;
        nn->data=val;
        node* temp=head;
        while(temp->data!=aftval){
            temp=temp->next;
        }
        nn->next=temp->next;
        temp->next=nn;
    }
    void searchnode(int val){
        node* temp=head;
        int fg;
        while(1){
            if(temp->data==val){
                cout<<"Value found.."<<endl;
                break;
            }
            else if(temp->data != val && temp->next==NULL){
                cout<<"Value not found.."<<endl;
                break;
            }
            temp=temp->next;
        }
    }
    void deletenode(int val){
        node *temp = head, *prev = NULL;
        if(temp == NULL){
            cout<<"Empty List,can't delete"<<endl;
            return;
        }
        if(temp->data == val){
            head = head->next;
            free(temp);
            return;
        }
        while(temp->data != val && temp!=NULL){
            prev = temp;
            temp = temp->next;
        }
        if(temp==NULL){
            cout<<"Data not found,can't delete"<<endl;
            return;
        }
        else{
            prev->next = temp->next;
            free(temp);
        }
    }
    void display(){
        node* temp=head;
        while(temp!=NULL){
            cout<<"-->"<<temp->data;
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    singlelist ob;
    int i;
    do{
        cout<<"\n1.Insert at start\n"<<"2.Insert at End\n"<<"3.Insert after value\n";
        cout<<"4.Search value\n"<<"5.Delete value\n"<<"6.Display list\n";
        cout<<"0.Exit\n"<<"Enter choice: ";
        cin>>i;
        switch(i){
            case 1:
                int inst;
                cout<<"\nEnter value: ";
                cin>>inst;
                ob.insertatstart(inst);
                cout<<"\n";
                break;
            case 2:
                int ined;
                cout<<"\nEnter value: ";
                cin>>ined;
                ob.insertatend(ined);
                cout<<"\n";
                break;
            case 3:
                int dt,afval;
                cout<<"\nEnter value: ";
                cin>>dt;
                cout<<"Insert after: ";
                cin>>afval;
                ob.insertatpos(dt,afval);
                cout<<"\n";
                break;
            case 4:
                int srvl;
                cout<<"\nEnter value to search: ";
                cin>>srvl;
                ob.searchnode(srvl);
                cout<<"\n";
                break;
            case 5:
                int dlvl;
                cout<<"\nEnter value to delete: ";
                cin>>dlvl;
                ob.deletenode(dlvl);
                cout<<"\n";
                break;
            case 6:
                cout<<endl;
                ob.display();
        }
    }while(i!=0);
    return 0;
}