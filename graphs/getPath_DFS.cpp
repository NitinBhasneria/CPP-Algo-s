#include<bits/stdc++.h>
using namespace std;

vector<int> print(int** edges, int n, int sv, bool* visited, int v2) {
    // sv is for tracking the vertices
    // visited is the vertices we have already seen
    vector<int> ans;
    if(sv == v2){
        ans.push_back(v2);
        return ans;    
    }
    visited[sv] = 1;
    for(int i=0;i<n;i++) {
        if(i == sv){
            continue;
        }
        if(edges[sv][i] == 1){
            if(visited[i]){
                continue;
            }
            ans = print(edges, n, i, visited, v2);
            if(ans.empty())
                return ans;
            ans.push_back(sv);
            return ans;
        }
    }
}

int main() {
    int n; // number of vertices
    int e; // number of edges;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++)
            edges[i][j] = 0;
    }

    for(int i=0;i<e;i++){
        int f, s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i] = 0;

    int v1, v2;
    cin>>v1>>v2;

    vector<int> ans = print(edges, n, v1, visited, v2);
    for(auto i : ans) {
        cout<<i<<" ";
    }

    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}
