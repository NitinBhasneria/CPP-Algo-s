#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k=0;
    cin>>n;
    int arr[n];
    map<int, int> C;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        C[arr[i]] = 0; 
    }
    int count=1;
    for(auto i:C) {
        C[i.first] = count++;
    }
    for(auto i:C) {
        cout<<"Number: "<<i.first<<" Rank: "<<i.second<<endl;
    }
}