#include<iostream>
using namespace std;

class Node{
    public:
        int key;
        int data;
        Node * next;
        
        Node(){
            key=0;
            data=0;
            next=NULL;
        }
        Node(int k,int d){
            key=k;
            data=d;
        }
};

class SinglyLinkedList{
    public:
        Node * head;

        SinglyLinkedList(){
            head=NULL;
        }
        SinglyLinkedList(Node * h){
            head=h;
        }
        Node * isPresent(int k){
            
            Node *ptr=NULL;
            Node *copy=head;
            
            while(copy!=NULL){
               
                if(copy->key==k){
                    ptr=copy;
                }
                copy=copy->next;
                
            }
            
            return ptr;
        }

        void appendingNode(Node *n){
            
           

            if(isPresent(n->key)!=NULL){
                cout<<"this key Node is already present"<<endl;
            }
            else{
                if(head==NULL){
                    head=n;
                    cout<<"Node is appended881"<<endl;
                }
                else{
                    Node * ptr=head;

                    while(ptr->next!=NULL){
                        cout<<ptr->key;
                        ptr=ptr->next;
                    }
                    cout<<ptr->key;
                    ptr->next=n;
                    cout<<"Node is appended"<<endl;
                    
                }
               
            }
           
        }
        void insertingNode(Node *n,int p){
           
            if(isPresent(n->key)!=NULL){
                cout<<"this key Node is already present"<<endl;
            }
            else{
                if(head==NULL){
                    cout<<"this cannot insert as head=NULL"<<endl;
                }
                else{
                    Node * ptr=head;
                    
                    while(ptr!=NULL){
                        if(ptr->key==p){
                            break;
                        }
                    
                        ptr=ptr->next;
                    }
                    n->next=ptr->next;
                    ptr->next=n;
                    
                }
            }
            cout<<"Node is inserted successfully"<<endl;
        }

        void prependNode(Node *n){
          
            if(isPresent(n->key)!=NULL){
                cout<<"Enter another node,this is already exists"<<endl;
            }
            else{
                if(head==NULL){
                    head=n;
                     cout<<"Node is prepended successfully"<<endl;
                }
                else{
                    n->next=head;
                    head=n;
                     cout<<"Node is prepended successfully"<<endl;
                }
            }
            
           
        }

        void deletingNode(int k){
            Node * ptr=head;
            Node * ptr2=head->next;
            if(head==NULL){
                cout<<"LinkedList is emtpy"<<endl;
            }
            else{
                Node * ptr=isPresent(k);
                if(ptr==NULL){
                    cout<<"LinkedList is empty"<<endl;
                }
                else{
                    Node * ptr=head;
                    Node * ptr2=head->next;
                    while(ptr2->key!=k){
                        ptr=ptr2;
                        ptr2=ptr2->next;
                    }
                    ptr->next=ptr2->next;
                    ptr2=NULL;
                }
            }
            cout<<k<<" th valued node is deleted successfully"<<endl;
           
        }

        void deletingLastNode(){
            Node *ptr=head;
            Node * ptr2=head->next;
            if(head==NULL){
                cout<<"linkedList is emtpy";
            }
            else{
                while(ptr2->next!=NULL){
                    ptr=ptr2;
                    ptr2=ptr2->next;
                }
                ptr->next=NULL;
                ptr2=NULL;
            }
            cout<<"last node is deleted successfully"<<endl;
        
        }
        void printing(){
            Node * ptr=head;
            if(head==NULL){
                cout<<"LinkedList is empty";
            }
            else{
                while(ptr!=NULL){
                    cout<<ptr->key<<" "<<ptr->data<<" -> ";
                    ptr=ptr->next;
                }
            }
        }
};

int main(){
    
    int k,d,p,choice;

    cout<<"1. To appendNode"<<endl<<"2. InsertingNode "<<endl<<"3.prependNode"<<endl<<"4.deletingNode"<<endl<<
    "5.deletingLastNode"<<endl<<"6.printing"<<endl<<"0. exit"<<endl<<endl;
    cout<<"Enter choice :";
    
    SinglyLinkedList  s;
    cin>>choice;
    while(choice!=0){
       
       
        Node * n =new Node();
        switch(choice){
            case 1:
                cout<<"Enter key , data to append a node : ";
                cin>>k>>d;
                n->key=k;
                n->data=d;
                s.appendingNode(n);
                break;
            case 2:
                cout<<"Enter key , data , position to append  a node : ";
                cin>>k>>d>>p;
                n->key=k;
                n->data=d;
                s. insertingNode(n,p);
                break;
            case 3:
                cout<<"Enter key , data to prepend a node : ";
                cin>>k>>d;
                n->key=k;
                n->data=d;
                s.prependNode(n);
                break;
            case 4:
                cout<<"Enter key to delete a node : ";
                cin>>k;
                s.deletingNode(k);
                break;
            case 5:
                s.deletingLastNode();
                break;
            case 6:
                s.printing();
                break;
            default :
                cout<<"Enter the valid number"<<endl;
                break;
        }
        cout<<"\nEnter the choice  : ";
        cin>>choice;
    }
    return 0;
}
