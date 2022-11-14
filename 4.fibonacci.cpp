#include<bits/stdc++.h>
using namespace std;

//T.C : O(n)
void iterative(int n){
    int a=0,b=1,c=0;
    while(n--){
        cout<<a<<" ";
        c = a+b;
        a = b;
        b = c;
    }
}

//T.C : O(n)
int recursive(int n, int a, int b){
    if(n==0)
        return 0;
    cout<<a<<" ";
    n = n-1;
    return recursive(n, b, a+b);
}

int main(){
    iterative(10);
    cout<<endl;
    recursive(10,0,1);
}