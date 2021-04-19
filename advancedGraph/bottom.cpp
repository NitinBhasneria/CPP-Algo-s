/*
BOTTOM
Send Feedback
We will use the following (standard) definitions from graph theory. Let V be a non-empty and finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.

Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such that ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1). Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).

Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.
Input Specification
The input contains several test cases, each of which corresponds to a directed graph G. Each test case starts with an integer number v, denoting the number of vertices of G=(V,E) where the vertices will be identified by the integer numbers in the set V={1,…,v}. You may assume that 1≤v≤5000. That is followed by a non-negative integer e and, thereafter, e pairs of vertex identifiers v1,w1,…,ve,we with the meaning that (vi,wi)∈E. There are no edges other than specified by these pairs. The last test case is followed by a zero.
Output Specification
For each test case output the bottom of the specified graph on a single line. To this end, print the numbers of all nodes that are sinks in sorted order separated by a single space character. If the bottom is empty, print an empty line.
Sample Input
3 3
1 3 2 3 3 1
2 1
1 2
0
Sample Output
1 3
2
*/

#include<bits/stdc++.h>
using namespace std;
#define max 5001

void dfs(vector<int>* edges, int n, int start, stack<int> &finishedVertices, bool* visited) {
    visited[start] = true;
    for (int i =0;i<edges[start].size();i++){
        int adj = edges[start][i];
        if(!visited[adj]){
            dfs(edges, n, adj, finishedVertices, visited);
        }
    }
    finishedVertices.push(start);
}

void dfs2(vector<int>* edgesT, int n, int start, map<int, int> &mp, bool* visited, int comp, unordered_set<int>* ans) {
    
    visited[start] = true;
    ans->insert(start);
    for(int i=0;i<edgesT[start].size();i++){
        int adj = edgesT[start][i];
        if(!visited[adj]){
            dfs2(edgesT, n, adj, mp, visited, comp, ans);
        }
    }
    mp[start] = comp;
}

void bottom(vector<int>* edges, vector<int>* edgesT, int n) {
    bool* visited = new bool[n]();
    stack <int> finishedVertices;
    for(int i=0;i<n;i++) {
        if(!visited[i]){
            dfs(edges, n,i,finishedVertices,visited);
        }
    }
    map<int, int> mp;
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    memset(visited,false,n);
    int comp = 1;
    while(finishedVertices.size() != 0) {
        int element = finishedVertices.top();
        finishedVertices.pop();
        if(!visited[element]){
            unordered_set<int>* ans = new unordered_set<int>();
            dfs2(edgesT, n, element, mp, visited, comp, ans); //getting number of ele in components;
            comp+=1;
            output->insert(ans);
        }
    }
    unordered_set<unordered_set<int>*>::iterator it = output->begin();
    vector<int> vc;
    while(it != output->end()) {
        unordered_set<int>* component = *it;
        unordered_set<int>::iterator it2 = component->begin();
        int flag = 1;
        while(it2 != component->end()) {
            for(int i=0;i<edges[*it2].size();i++){
                int adj = edges[*it2][i];
                if(mp[*it2]!=mp[adj]){
                    flag = 0;
                }
            }
            it2++;
        }
        it2 = component->begin();
        if(flag == 1) {
            while(it2 != component->end()) {
                vc.push_back(*it2);
                it2++;
            }
        }
        it++;
    }
    sort(vc.begin(), vc.end());
    for(int i=0;i<vc.size();i++) {
        cout<<vc[i]+1<<" ";
    }
    cout<<endl;
}

int main() {
    int n, m;
    bool flag = true;
    while(flag){
        cin>>n;
        if(n==0){
            flag = false;
            continue;    
        }
        vector<int> edges[n];
        vector<int> edgesT[n];
        cin>>m;
        for(int i=0;i<m;i++) {
            int s, e;
            cin>>s>>e;
            s-=1;
            e-=1;
            edges[s].push_back(e);
            edgesT[e].push_back(s);
        }
        bottom(edges, edgesT, n);
    }
}