#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

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

// tail can access both first and last element therefore we dont make head pointer

void insertElement(node* &tail, int target, int d){
// assuming target is present in the list
	
    //empty list
    if(tail==NULL){
        node* newNode=new node(d);
        newNode->next=newNode;
        tail=newNode;
    }else{
	// non empty list and target is present
        node* curr = tail;
        
        while(curr->data != target){
            curr=curr->next;
        }
	    
        //curr is at target now
	    
        node* temp = new node(d);
        temp->next=curr->next;
        curr->next=temp;

    }
}

void display(node* &tail){

    if(tail==NULL){
	    cout<<"List is Empty"<<endl;
    }
	
    node* temp=tail;

    // do while ek bari toh execute hota he hota hai toh we use it for single element in linked list
    do{
        cout<<tail->data;
        tail=tail->next;
    }while(tail != temp) 
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

	// for 1 node linked list
	if(curr==prev){
		tail=NULL;
	}

	// >=2 nodes ke liye    
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
