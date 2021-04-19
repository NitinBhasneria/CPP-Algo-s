#include<iostream>
using namespace std;

void insertionSort(int a[], int n){
    // int start=0, min,ind;
    for(int i=1;i<n;i++){
        int pos=i;
        for(int k=i-1;k>=0;k--){
            if(a[i]<a[k])
                pos=k;
        }
        for(int j=i;j>pos;j--){
            swap(a[j],a[j-1]);
        }
    }
}

int main (){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    insertionSort(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}