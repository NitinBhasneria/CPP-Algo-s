// BFS Adjancency Matrix
// Breadth First Search 
// Disconnected Graph
// Will use queue// DFS Technique

#include<bits/stdc++.h>
using namespace std;

void printBFS(int** edges, int n, int sv, bool* visited) {

    queue<int> pendingVertices;
    visited[sv] = 1;
    pendingVertices.push(sv);

    vector<int>* ans = new vector<int>(); 

    while(!pendingVertices.empty()) {
        int current = pendingVertices.front();
        pendingVertices.pop();
        ans->push_back(current);
        for(int i=0;i<n;i++){
            if(edges[current][i] == 1 && !visited[i]) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    sort(ans->begin(), ans->end());
    for(int i = 0; i<ans->size();i++){
        cout<<ans->at(i)<<" ";
    }
    delete ans;
}

void BFS(int** edges,  int n) {
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i] = false;

    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            printBFS(edges, n, i, visited);
            cout<<endl;
        }
    }

    delete[] visited;       
}

int main() {
    int n; // number of vertices
    int e; // number of edges;
    cin>>n>>e;
    if(n==0)
        return 0;
    if(e==0){
        for(int i=0;i<n;i++)
        	cout<<i<<"\n";
        return 0;
    }
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
    

    BFS(edges, n);

    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}
