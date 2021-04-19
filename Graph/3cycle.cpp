/*
3 Cycle
Send Feedback
Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.
Input Format :
The first line of input contains two space separated integers, that denotes the value of N and M.
Each of the following M lines contain two integers, that denote the vertices which have an undirected edge between them. Let us denote the two vertices with the symbol u and v. 
Output Format :
Print the count the number of 3-cycles in the given graph
Constraints :
0 <= N <= 100
0 <= M <= (N*(N-1))/2
0 <= u <= N - 1
0 <= v <= N - 1
Time Limit: 1 sec
Sample Input 1:
3 3
0 1
1 2
2 0
Sample Output 1:
1
*/

#include<bits/stdc++.h>
using namespace std;

// DFS Technique
// Depth First Search                                
// Taking the input 0 to n-1 and the edges

#include<bits/stdc++.h>
using namespace std;

void three_cycle(int** edges,  int n) {

    int ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++){
            if(edges[i][j]){
                for(int k=0;k<n;k++){
                    if(edges[j][k]&&edges[k][i]){
                        ans+=1;
                    }
                }
            }
        }
    }
    cout<<ans/6;     
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
    
    three_cycle(edges, n);

    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}









