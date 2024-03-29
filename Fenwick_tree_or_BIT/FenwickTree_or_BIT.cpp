#include<bits/stdc++.h>
using namespace std;

/*
input type
8
1 2 3 4 5 6 7 8
*/

void update(int index, int value, int* BIT, int n) {
    for(;index<=n;index+=(index&(-index))){
        BIT[index] += value;
    }    
    // for(int i=1;i<=n;i++) {
    //     cout<<BIT[i]<<" ";
    // }
    // cout<<endl;
}

int query(int index, int* BIT) {
    int sum = 0;
    for(;index>0;index-=(index&(-index))) {
        sum += BIT[index];
    }
    return sum;
}

int main (){ 

    int n;
    cin>>n;
 
    int* arr = new int[n+1]();
    int* BIT = new int[n+1]();

    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        update(i, arr[i], BIT, n);
    }

    cout<<"Sum of first five elements "<<query(5, BIT)<<endl;
    update(4, 10-arr[4], BIT, n);
    cout<<"Sum of elements from 2 index t 6 index "<<query(6, BIT) - query(1, BIT)<<endl;
    return 0;
}