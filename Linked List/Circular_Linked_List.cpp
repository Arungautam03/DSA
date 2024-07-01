#include<iostream>
using namespace std;

class node{
    public:
    int data;
    int next;

    //constructor
    node(int d){
        this->data=d;
        this->next=NULL;
    }

    ~node(){
			int value=this->data;
			if(this->next!=NULL){
				delete next;
                this->next=NULL;
			}
			
			cout<<"memory cleared for data"<<value<<endl;
		}

};

void insertElement(node* &tail, int target, int d){

    //empty list
    if(tail==NULL){
        node* temp=new node(d);
        temp->next=temp;
        tail=temp;
    }else{
        node* curr = tail;
        
        while(curr->next != ){
            curr=curr->next;
        }

        //curr is at target now
        node* temp=new node(d);
        temp->next=curr->next;
        curr->next=temp;

    }
}

void display(node* &tail){
    node* temp=tail;

    // do while ek bari toh execute hota he hota hai toh we use it for single element in linked list
    do{
        cout<<tail->data;
        tail=tail->next;
    }while(tail!=temp)
}

void deleteNode(node* &tail, int value){
    if(tail==NULL){
        cout<<"Already Empty"<<endl;
        return;
    }else{
        node* prev=tail;
        node* curr= prev->next;

        while(curr->data != value){
            prev=curr;
            curr=curr->next;
        }

        prev-> next = curr->next;
	if(tail==curr){
		tail=prev;
	}
        curr->next=NULL;
        delete curr;
    }
}
int main(){

node* tail=NULL;
insertElement(tail,3,4);
display(tail);


    return 0;
}
