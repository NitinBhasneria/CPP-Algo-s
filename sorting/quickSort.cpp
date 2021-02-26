#include<iostream>
using namespace std;

int partition (int a[], int si, int ei) {
    int x=a[si];
    int count=0;
    for(int i=si+1;i<ei;i++){
        if(a[i]<x)
            count++;
    }
    int sw = a[si];
    a[si]=a[count+si];
    a[count+si]=sw;
    int i=si, j=ei-1;
    // for(int i=si;i<ei;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    while(i<(count+si) && j>(count+si)){
        if(a[i]<x){
            i++;
            // cout<<"one";
        }
        if(a[j]>x){
            j--;
            // cout<<"two";    
        }
        if(a[i]>x&&a[j]<x){
            // cout<<"three";
            int sw = a[i];
            a[i]=a[j];
            a[j]=sw;
        }
    }
    // cout<<endl;
    return count+si;
}

void quicksort(int a[], int si, int ei){
    if(si>=ei)
        return;
    // for(int i=si;i<ei;i++)
    //     cout<<a[i]<<" ";
    int c = partition(a, si, ei);
    // for(int i=si;i<ei;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    quicksort (a, si, c);
    quicksort (a, c+1, ei);
}


int main (){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a,0,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}