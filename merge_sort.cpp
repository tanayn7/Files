#include<bits/stdc++.h>
using namespace std;


//T.C. : O(n)  &  S.C. : O(n)
void Merge(int arr[], int l, int m, int h){
    
    int n1=m-l+1;  int n2=h-m;
    int left[n1];  int right[n2];
    for(int i=0; i<n1; i++)
        left[i]=arr[i];
    for(int i=0; i<n2; i++)
        right[i]=arr[n1+i];

    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k]=left[i];  i++;  k++; 
        }
        else{
            arr[k]=right[j]; j++;  k++;
        }
    }
    while(i<n1){
        arr[k]=left[i];  i++;   k++;
    }
    while(j<n2){
        arr[k]=right[j]; j++;   k++;
    }
}

//T.C. : O(n)* O(logn) = O(n log n)
void MergeSort(int arr[], int l, int h){
    if(l<h){
        int m=(l+h)/2;
        MergeSort(arr,l,m);
        MergeSort(arr,m+1,h);
        Merge(arr,l,m,h);
    }
}

int main(){
    int arr[]={28,64,91,12,35,77};
    MergeSort(arr,0,5);
    for (auto i:arr)
        cout<<i<<" ";
}