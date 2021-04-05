#include<bits/stdc++.h>
using namespace std;

vector<int>* getPath(int** edges, int n, int v1, int v2) {

    queue<int> pendingVertices;
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i] = 0;
    visited[v1] = 1;
    pendingVertices.push(v1);
    
    map<int, int> parent;
    bool flag = false;
    while(!pendingVertices.empty() && !flag) {
        int current = pendingVertices.front();
        pendingVertices.pop();
        for(int i=0;i<n;i++){
            if(edges[current][i] == 1 && !visited[i]) {
                parent[i] = current;
                pendingVertices.push(i);
                visited[i] = true;

                if(i == v2){
                    flag = true;
                    break;
                }
            }
        }
    }
    delete[] visited;
    if(!flag) {
        return NULL;
    } else {
        vector<int>* ans = new vector<int>();
        int current = v2;
        ans->push_back(v2);
        while(current != v1) {
            current = parent[current];
            ans->push_back(current);
        }
        return ans;
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
    
    int v1, v2;
    cin>>v1>>v2;
    if(v1==v2){
        cout<<v1;
    }
    else{
        vector<int>* ans = getPath(edges, n, v1, v2);
        if(ans != NULL) {
            for(int i=0;i<ans->size();i++){
                cout<<ans->at(i)<<" ";
            }
        }
    }
    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}
