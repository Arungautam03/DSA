#include<iostream>
using namespace std;
 
 class queue{
 	private:
 		int *arr;
 		int front;
 		int rear;
 		int size;
 		
 	public:
 		
 		queue(int n){
 			size=n;
 			arr= new int[size];
 			front=rear=-1;
		 }
		 
		void enqueue(int element){
			
			if((front==0 && rear==(size-1)) || (rear==(front-1)%(size-1))){
			
				cout<<"queue is full"<<endl;
			}
			
			else if(front==-1){
			
				front=rear=0;
			arr[rear]=element;
			}
			
			else if( rear==(size-1) && front!=0) {
				rear=0;
				arr[rear]=element;
			}
			
			else{
				rear++;
				arr[rear]=element;
				
			}
			return ;
		}
		
		int dequeue(){

			if(front==-1){
				cout<<"queue is empty"<<endl;
			}

			int value= arr[front];
			arr[front]=-1;
			
			
			else if(front==rear){
			
				front=rear=-1;
			}
			
			else if(front==(size-1))
			{
				front=0; // to maintain cyclic nature
			}
			
			else{
				front++;
			}
			
			return value;
		}
 };
 
 int main(){
 	
 	return 0;
 }
