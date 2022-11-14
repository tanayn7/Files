#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value, weight;
    Item(int v, int w){
        value = v; 
        weight = w;
    }
};

bool cmp(struct Item a, struct Item b){
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight; 
    return r1 > r2;          // > sign
}

double FracionalKnapsack(int W, struct Item arr[], int N){
    
    sort(arr, arr+N, cmp); //sort
    double ans = 0;
    for(int i=0; i<N; i++){
        if(arr[i].weight <= W){
            ans += arr[i].value;
            W -= arr[i].weight;
        }
        else{
            ans += arr[i].value * ((double)W / arr[i].weight);  //double
            break;
        }
    }
    return ans;
}


int main(){
    int W = 50;
    Item arr[]={{60,10},{100,20},{120,30}};   //Item arr[]
    int N = sizeof(arr)/sizeof(arr[0]);
    cout<<FracionalKnapsack(W,arr,N);
}

/*
Time Complexity: O(N * log N)
Auxiliary Space: O(N)
*/