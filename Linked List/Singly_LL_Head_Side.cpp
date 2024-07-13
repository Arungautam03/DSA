#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		
		node(int d){
			this->data=data;
			this->next=NULL;
		}
		
		~node(){
			int value= this->data;
			if(this->next!=NULL){
				delete next;
				next=NULL;
			}
			
			cout<<"memory cleared for data"<<value<<endl;
		}
};

void insertnode(node* &tail, int element,int d){
	if(tail==NULL){
		node* newnode= new node(d);
		tail= newnode;
		newnode->next=newnode;
	}
	
	else{
		node* curr=tail;
		
		while(curr->next!=  element){
			curr=curr->next;
		}
		
		node* temp= new node(d);
		temp->next=curr->next;
		curr->next=temp;
	}
}

void print(node* &tail){
	
	node* temp= tail;
	do{
		cout<<tail->data<<endl<<endl;
		tail=tail->next;
	}
	while(tail!=temp);
}

void deletenode(node* &tail, int value){
	if(tail==NULL){
		cout<<"check again"<<endl;
	}
	
	else{
		node* prev=tail;
		node* curr=prev->next;
		
		while(curr->next!=value){
			curr=curr->next;
		}
		
		prev->next=curr->next;
		
		if(curr==prev){
			tail=NULL;
		}
		
		if(tail==curr){
			tail=prev;
		}
		
		curr->next=NULL;
		delete curr;
		}	
}

int main(){
	
	node* tail=NULL;
	
	insertnode(tail,2,3);
	print(tail);
	
		insertnode(tail,3,5);
	print(tail);
	
		insertnode(tail,3,4);
	print(tail);
	
	
		deletenode(tail,3);
	print(tail);
	
		insertnode(tail,5,7);
	print(tail);
	
}
