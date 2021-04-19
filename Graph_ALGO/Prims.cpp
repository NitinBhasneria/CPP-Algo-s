#include<bits/stdc++.h>
using namespace std;

int getMinVertex(bool* visited, int* weight, int n) {
    int minVertex = -1;

    for(int i=0;i<n;i++) {
    
        if(!visited[i]){
            if(minVertex == -1)
                minVertex = i;
            else if(weight[minVertex] > weight[i])
                minVertex = i;
        }
    }
    return minVertex;
}

void prims(int** edge, int n){
    bool* visited = new bool[n];
    int* parent = new int[n];
    int* weight = new int[n];

    for(int i=0;i<n;i++) {
        weight[i] = INT_MAX;
    }
    weight[0] = 0;
    parent[0] = -1;

    for(int i=0;i<n-1;i++) {
        
        // Get min Vertex that is vertex with minimum weight in unvisited
        
        int minVertex = getMinVertex(visited, weight, n);
        visited[minVertex] = true;

        // Explore all neighbours of minVertex 
        for(int j=0;j<n;j++) {
            if(edge[minVertex][j] != 0 && !visited[j]) {
                if(weight[j] > edge[minVertex][j]) {
                    weight[j] = edge[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }  
    }

    for(int i=1;i<n;i++) {
        if(parent[i] < i) {
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }else {
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }
    
    delete[] parent;
    delete[] visited;
    delete[] weight;  
}

int main (){
    // n is number of vertices from 0 to n-1;
    int n, E;
    cin>>n>>E;
    int** edges = new int*[n];

    for(int i=0; i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }

    for(int i=0;i<E;i++){
        int s,d,w;
        cin>>s>>d>>w;
        edges[s][d] = w;
		edges[d][s] = w;
    }

    prims(edges, n);
    
    for(int i=0;i<n;i++)    
        delete[] edges[i];
	delete [] edges;
    return 0;
}