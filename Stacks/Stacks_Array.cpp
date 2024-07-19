#include<bits/stdc++.h>

// TIME COMPLEXITY: O(N)

using namespace std;
class Stack {

public:
  int size;
  int *arr;
  int top;
  
  Stack(int size){
    this->size=size;
    arr = new int[size];
    top=-1
  }
  void push(int x) {
    if(size-top>1){
    top++;
    arr[top] = x;
    }else{
      cout<<"Stack Overflow"<<endl;
    }
  }

  int pop() {
    if(top==-1){
      cout<<"Stack is Empty"<<endl;
    }else{
    int x = arr[top];
    top--;
    return x;
    }
  }

  int Top() {
    if(top>=0) return arr[top];
    else{
      cout<<"Stack is Empty"<<endl;
      return -1;
    }
  }

  int Size() {
    return top + 1;
  }

  bool isEmpty(){
    if(top==-1) return true;
    else return false;
  }

};
int main() {

  Stack s;
  s.push(6);
  s.push(3);
  s.push(7);
  cout << "Top of stack is before deleting any element " << s.Top() << endl;
  cout << "Size of stack before deleting any element " << s.Size() << endl;
  cout << "The element deleted is " << s.pop() << endl;
  cout << "Size of stack after deleting an element " << s.Size() << endl;
  cout << "Top of stack after deleting an element " << s.Top() << endl;
  return 0;
}
