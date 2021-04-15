#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>* edges = new vector<int>[n];
    vector<int>* edgesT = new vector<int>[n]; // Transpose 

    int m;
    cin>>m;
    for(int i=0;i<m;i++) {
        int j,k;
        cin>>j>>k;
        edges[j-1].push_back(k-1);
        edgesT[k-1].push_back(j-1);
    }
    
    delete[] edges;
    delete[] edgesT;
}