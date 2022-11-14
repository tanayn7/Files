#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high){
    
    int pivot = arr[high];
    int i = low-1;
    for(int j=low; j<=high; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

int r_partition(int arr[], int l, int h){
    
    srand(time(NULL));
    int random = l + rand()%(h-l);
    swap(arr[random], arr[h]);
    return partition(arr,l,h);
}

void quickSort(int arr[], int l, int h){
    
    if(l<h){
        int p = r_partition(arr,l,h);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,h);
    }
}


int main(){
    int arr[]={92,7,12,52,18,37,22,69};
    int n=sizeof(arr)/sizeof(int);
    quickSort(arr,0,n-1);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}