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

		// destructor
		~node(){
			int value= this->data;
			if(this->next!=NULL){
				delete next;
				next=NULL;
			}
			
			cout<<"memory cleared for node with data"<<value<<endl;
		}
};

// node* &head reference taken because i dont want to create a copy and changes should be made in the original linked list

void insertatHead(node* &head, ind d){
	node* temp= new node(d);
	temp->next=head;
	head=temp;
}

void insertatTail(node* &tail, int d){
	node* temp = new node(d);
	tail->next=temp;
	tail=tail->next; //tail=temp;
}

void insertatPosition(node* &tail, node* &head, int pos, int d){

	// first position
	if(pos==1){
		insetatHead(head,d);
		return;
	}

	node* temp = head;
	int cnt=1;

	// n position pe jaana hai toh n-1 node tak traversal karo
	while(cnt<pos-1){
		temp=temp->next;
		cnt++;
	}

	//last position
	if(temp->next == NULL){
		insertatTail(tail,d);
		return;
	}

	node* nodeToInsert = new node(d);
	nodeToInsert->next= temp->next;
	temp->next = nodeToInsert;	
	
}

void print(node* &tail){
	
	node* temp= tail;

	//use if(){}
	do{
		cout<< tail->data <<endl;
		temp=temp->next;
	}
	while(tail!=temp);
}

//deletion with position
void deleteNodePosition(int pos,node* &head){
	if(pos==1){
		node* temp = head;
		head=head->next;
		//memory free
		delete temp;
	}

	node* curr = head;
	node* prev = NULL;

	int cnt=1;
	while(cnt<pos){
		prev=curr;
		curr=curr->next;
		cnt++
	}

	prev->next = curr ->next;
	curr->next = NULL;
	delete curr;
}

// deletion with value 

int main(){
	
	node* tail=NULL;
	cout<<head->data<<endl;
	cout<<tail->data<<endl;
}
