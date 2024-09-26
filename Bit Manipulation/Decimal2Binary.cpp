#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string decimal2binary(int n){
    // Base of log is 2
    //TC: O(log(n))
    //SC: O(log(n)) 
    if(n==0) return 0;
    
    string ans="";
    while(n > 0){
        if(n%2==1){
            ans.push_back('1');
        }else{
            ans.push_back('0');
        }
        n=n/2;
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n;
    cout<<"enter decimal"<<endl;
    cin>>n;
    string ans = decimal2binary(n);
    cout<<"Binary Number is "<<ans<<endl;
    return 0;
}
