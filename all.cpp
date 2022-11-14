//Fractional KS:

#include<bits/stdc++.h>
using namespace std;

// struct Item{
//     int value, weight;
//     Item(int v, int w){
//         value = v;
//         weight = w;
//     }
// };

// bool cmp(struct Item A, struct Item B){
    
//     double r1 = double(A.value)/double(A.weight);
//     double r2 = double(B.value)/double(B.weight);
//     return r1>r2;
// }

// double FractionalKnapsack(int W, struct Item arr[], int N){
    
//     sort(arr,arr+N,cmp);
//     double ans=0;
//     for(int i=0; i<N; i++){
//         if(arr[i].weight < W){
//             ans = ans + arr[i].value;
//             W = W - arr[i].weight;
//         }
//         else{
//             ans = ans + arr[i].value * (double(W)/arr[i].weight);
//             return ans;
//         }
//     }
//     return ans;
// }

// int main(){
//     int w=10;
//     Item arr[]={{10,5},{30,6},{40,4},{50,3}};
//     int n=4;
//     cout<<FractionalKnapsack(w,arr,n);
// }








// int Knapsack(int W, int wt[], int val[], int N){
    
//     int dp[N+1][W+1];
//     for(int i=0; i<=N; i++)
//         dp[i][0]=0;
//     for(int i=0; i<=W; i++)
//         dp[0][i]=0;
    
//     for(int i=1;i<=N; i++){
//         for(int j=1;j<=W; j++){
//             if(wt[i-1] > j)
//                 dp[i][j] = dp[i-1][j];
//             else
//                 dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);        }
//     }
//     return dp[N][W];
// }

// int main(){
//     int w=10;
//     int wt[] = {5,6,4,3};   
//     int val[] = {10,30,40,50};
//     int n=4;
//     cout<<Knapsack(w,wt,val,n);
// }



// int partition(int arr[], int l, int h){
//     int pivot = arr[h];
//     int i = l-1;
//     for(int j=l; j<=h; j++){
//         if(arr[j]<pivot){
//             i++;
//             swap(arr[i],arr[j]);
//         }
//     }
//     swap(arr[i+1],arr[h]);
//     return i+1;
// }


// int r_partition(int arr[], int l, int h){
//     srand(time(NULL));
//     int random = l + rand()%(h-l);
//     swap(arr[h], arr[random]);
//     return partition(arr, l, h);
// }

// void quickSort(int arr[], int low, int high){
//     if(low<high){
//         int p = r_partition(arr, low, high);
//         quickSort(arr, low, p-1);
//         quickSort(arr, p+1, high);
//     }
// }


// int main(){
//     int arr[]={1,6,2,7,13,89,11,44};
//     quickSort(arr,0,7);
//     for(int i=0; i<8; i++)
//         cout<<arr[i]<<" ";
// }
