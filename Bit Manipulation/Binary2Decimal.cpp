// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int BinarytoDecimal(int n){
   
    int ans =0;
    int mul=1;
    while(n!=0){
        ans+=(n%10)*mul;
        n=n/10;
        mul*=2;
    }
    
    return ans;
}

int main() {
    int s;
    cout<<"Enter Binary Number"<<endl;
    cin>>s;
      
    int sol = BinarytoDecimal(s);
     cout<<"Decimal Number is "<<sol<<endl;
    return 0;
}
