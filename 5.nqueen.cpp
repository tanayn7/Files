#include<bits/stdc++.h>
using namespace std;
int grid[10][10];


void display(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<grid[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(int cols, int rows, int n){
    for(int i=0; i<rows; i++){
        if(grid[i][cols]==1)
            return false;
    }

    for(int i=rows,j=cols; i>=0 && j>=0; i--, j--){
        if(grid[i][j]==1)
            return false;
    }

    for(int i=rows,j=cols; i>=0 && j<n; i--, j++){
        if(grid[i][j]==1)
            return false;
    }
    return true;
}

bool solve(int n, int rows){
    if(n==rows){
        display(n);
        return true;
    }

    bool res=false;
    for(int i=0; i<n; i++){
        if(isSafe(i, rows, n)){
            grid[rows][i] = 1;
            res = solve(n, rows+1) || res;
            grid[rows][i] = 0;
        }
    }
    return res;
}

int main(){
    
    int n=5; //cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            grid[i][j]=0;
    }
    bool res = solve(n,0);
    if(res == false)
        cout<<"Solution doesnt exist";
}









/*
#include<bits/stdc++.h>
using namespace std;

int grid[10][10];

void display_solution(int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) 
                cout<<grid[i][j]<< " ";   
        cout<<endl;
    }
    cout<<endl;
}

//function for check the position is safe or not
bool isSafe(int col, int row, int n){
    
    //check for same column
    for (int i=0; i<row; i++){
        if (grid[i][col]==1) 
            return false;
    }
    
    //check for upper left diagonal
    for (int i=row, j=col; i>=0 && j>=0; i--, j--){
        if (grid[i][j]==1)
            return false; //queen in left diagonal
    }
    
    //check for upper right diagonal
    for (int i=row, j=col; i>=0 && j<n; j++, i--) {    
        if (grid[i][j]==1) 
            return false;
    }
    return true; // means position is safe to place queen
}

//function to find the position for each queen
bool solve (int n, int row) 				//row is indicates the queen no. and col represents the possible positions
{
    if (n == row){ 		// successfully place queen in n rows
        display_solution(n);
        return true;
    }
    
    //variable res is use for possible backtracking 
    bool res = false;
    for (int i=0; i<n; i++) 
    {
        if(isSafe(i, row, n)){
            grid[row][i] = 1; //place queen 
            //recursive call solve(n, row+1) for next queen (row+1)
            res = solve(n, row+1) || res;//if res ==false then backtracking will occur 
            //by assigning the grid[row][i] = 0
            
            grid[row][i] = 0;  //backtrack
        }
    }
    return res;
}


int main() {

    int n=3;  //cin>>n;      
    for (int i =0; i<n; i++) {
        for (int j=0; j<n; j++)
            grid[i][j] = 0;
    }
    
    bool res = solve(n, 0);
    if(res == false) 
            printf("Solution does not exist");  //if there is no possible solution
}
*/






















