#include<iostream>
using namespace std;

void selectionSort(int a[], int n){
    // int start=0, min,ind;
    for(int j=0;j<n-1;j++){
        int min=a[j], ind=j;
        for(int i=j;i<n;i++){
            if(a[i]<min){
                min=a[i];
                ind=i;}
        }
        cout<<a[ind]<<" "<<a[j]<<endl;
        int c = a[ind];
        a[ind]=a[j];
        a[j]=c;
    }
}

int main (){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    selectionSort(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}