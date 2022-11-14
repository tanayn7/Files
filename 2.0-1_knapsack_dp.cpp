#include<bits/stdc++.h>
using namespace std;


int Knapsack(int n, int wt[], int val[], int w){
    
    int dp[n+1][w+1];
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
    for(int i=0; i<=w; i++)
        dp[0][i] = 0;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            if(wt[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
        }
    }
    return dp[n][w];
}

int main(){
    
    int W = 10;
    int wt[] = {5,6,4,3};   
    int val[] = {10,30,40,50};
    int N = sizeof(wt)/sizeof(wt[0]);
    cout<<Knapsack(N,wt,val,W);   
}

/*
Time Complexity : O(N*W). 
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space : O(N*W). 
The use of 2-D array of size ‘N*W’.
*/