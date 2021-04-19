#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int src;
    int dest;
    int weight;
};

bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

int getParent(int current, int* parent) {
    if(parent[current] == current)  
        return current;
    
    getParent(parent[current], parent); 
}

Edge* kruskals(Edge* edges, int n, int E) {
    // Sorted Edges Array
    sort(edges, edges+E, compare);

    Edge* output = new Edge[n-1];
    int* parent = new int[n];
    for(int i=0;i<n;i++) {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    while(count<n-1) {
        // Check the topmost parent of v1 and v2. v1 and v2 are vertices of current edge

        Edge currentEdge = edges[i];
        // Union and Find Operations
        int srcParent = getParent(currentEdge.src, parent);
        int destParent = getParent(currentEdge.dest, parent);
        
        if(srcParent != destParent){
            output[count] = currentEdge;
            count += 1;
            parent[srcParent] = destParent;
        }
        i+=1;
    }
    
    return output;
}

int main (){
    // n is number of vertices from 0 to n-1;
    int n, E;
    cin>>n>>E;
    Edge* edges = new Edge[E];
    for(int i=0;i<E;i++){
        int s,d,w;
        cin>>s>>d>>w;
        edges[i].src = s;
        edges[i].dest = d;
        edges[i].weight = w;
    }

    Edge* output = kruskals(edges, n, E);
    for(int i=0;i<n-1;i++) {
        if(output[i].src < output[i].dest){
            cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<"\n";
        }else {
            cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight<<"\n";
        }
    }
    delete[] output;
    return 0;
}