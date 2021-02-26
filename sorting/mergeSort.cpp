#include<iostream>
using namespace std;

void mergeSort(int a[], int si, int ei){
    // for(int i=si;i<=ei;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    if(si>=ei)
        return;
    
    int mid = (si+ei)/2;
    mergeSort(a, si, mid);
    mergeSort(a, mid+1, ei);
    
    int arr[ei-si+1];
    int k=si, j=mid+1;
    // cout<<endl;
    // for(int i=si;i<=ei;i++){
    //     cout<<a[i]<<" ";
    // }
    for(int i=0;i<(ei-si+1);i++){
        if(k>mid){
            while(i<ei-si+1){
                arr[i++]=a[j++];
            }
            // cout<<"one";
        }
        else if(j>ei){
            while(i<ei-si+1){
                arr[i++]=a[k++];
            }
            // cout<<"two";
        }
        else if(a[k]<=a[j]){
            // cout<<"three";
            arr[i]=a[k++];  
        }
        else{
            // cout<<"four";
            arr[i]=a[j++];
        }    
    }
    // cout<<endl;
    // for(int i=0;i<ei-si+1;i++)
    //     cout<<arr[i]<<" ";
    int l=0;
    for(int i=si;i<=ei;i++){
        a[i]=arr[l++];
    }
    // cout<<endl;
    // for(int i=si;i<=ei;i++){
    //     cout<<a[i]<<" ";
    // }
}

int main() {
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    mergeSort(a,0,n-1);
     cout<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
   
    return 0;
}