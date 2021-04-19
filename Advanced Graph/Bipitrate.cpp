#include<bits/stdc++.h>
using namespace std;

bool bipartrite(vector<int>* edges, int n) {
    if(n==0)
        return true;

    unordered_set<int> sets[2];
    queue<int> pending;
	pending.push(0);
    sets[0].insert(0); // as vertices are from 0 to n so first element is 0
    
	while (pending.size() > 0) {
		int current = pending.front();
		pending.pop();
		int currentSet = sets[0].count(current) > 0 ? 0 : 1;
		for (int i = 0; i < edges[current].size(); i++) {
			int neighbor = edges[current][i];
			if (sets[0].count(neighbor) == 0 && sets[1].count(neighbor) == 0) {
				sets[1 - currentSet].insert(neighbor);
				pending.push(neighbor);
			} else if (sets[currentSet].count(neighbor) > 0) {
				return false;
			}
		}
	}
	return true;
}

int main() {
    int n;
    while(true) {
        cin>>n;
        if(n==0) break;
        vector<int>* edges = new vector<int>[n];
        int m;
        cin>>m;
        for(int i=0;i<m;i++) {
            int s, e;
            cin>>s>>e;
            edges[s].push_back(e);
            edges[e].push_back(s);
        }
        bool ans = bipartrite(edges, n);
        delete[] edges;
        if(ans) {
            cout<<"BICOLOURABLE"<<endl;
        }
        else {
            cout<<"NOT BICOLOURABLE"<<endl;
        }
    }
}