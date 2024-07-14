#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		node* prev;
		
		node(int data){
			this->data=data;
			this->next=NULL;
			this->prev=NULL;
		}
		
		~node(){
			int value=this->data;
			if(this->next!=NULL){
				next=NULL;
				delete next;
				//this->next=NULL;
			}
			
			cout<<"memory cleared for data"<<value<<endl;
		}
};

int getLength(node* head){
node* temp=head;
int len=0;
while(temp!=NULL){
len++;
temp=temp->next;
}
return len;
}

void insertathead(node* &head,node* &tail, int d){

	if(head==NULL){
	node* temp = new node(d);
	head=temp;
	tail=temp;
	}else{
	node* temp=new node(d);
	temp->next=head;
	head->prev=temp;
	head=temp;
	}
}

void insertattail(node* &head, node* &tail, int d){

	if(tail==NULL){
	node* temp= new node(d);
	tail=temp;
	head=temp;
	}else{
	node* temp=new node(d);
	tail->next=temp;
	temp->prev=tail;
	tail=tail->next; // tail=temp;
	}
}

void insertatanyposition(node* &head, node* &tail, int position, int d){
	if(position==1){
		insertathead(head,tail,d);
		return;
	}
	
	node* temp=head;
	int cnt=1;
	
	while(cnt<position-1){
		temp=temp->next;
		cnt++;
	}
	
	if(temp->next==NULL){
		insertattail(head,tail,d);
		return;
	}

	// middle ke liye
	node* nodeToInsert= new node(d);
	nodeToInsert->next=temp->next;
	temp->next->prev=nodeToInsert;
	temp->next=nodeToInsert;
	nodeToInsert->prev=temp;
	
	
}

void print(node* &head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<endl;
}



void deletenode(int position, node* &head){
	
	if(position==1){
		node* temp=head;
		temp->next->prev=NULL;
		head=temp->next;
		temp->next=NULL;
		delete temp;
	}else{
		node* curr=head;
		node* prev=NULL;
		
		int cnt=1;
		while(cnt<position){
			prev=curr;
			curr=curr->next;
		
			cnt++;
		}

		if(curr->next == NULL){
			tail=prev
		}
		
		curr->prev=NULL;
		prev->next=curr->next;
		curr->next=NULL;
		delete curr;
		
	}
}


int main(){
	node* node1= new node(4);
	node* head=node1;
	node* tail=node1;
	print(head);
	
	
	insertathead(head,3);
	print(head);
	
	insertathead(head,1);
	print(head);
	
	insertattail(tail,5);
	print(head);
	
	insertatanyposition(head,tail,2,2);
	print(head);
	
	deletenode(5,head);
	print(head);

}
