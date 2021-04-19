/*
FILLMTR
Send Feedback
Fill The Matrix
A matrix B (consisting of integers) of dimension N × N is said to be good if there exists an array A (consisting of integers) such that B[i][j] = |A[i] - A[j]|, where |x| denotes absolute value of integer x.

You are given a partially filled matrix B of dimension N × N. Q of the entries of this matrix are filled by either 0 or 1. You have to identify whether it is possible to fill the remaining entries of matrix B (the entries can be filled by any integer, not necessarily by 0 or 1) such that the resulting fully filled matrix B is good.
Input
The first line of the input contains an integer T denoting the number of test cases.

The first line of each test case contains two space separated integers N, Q.

Each of the next Q lines contain three space separated integers i, j, val, which means that B[i][j] is filled with value val.
Output
For each test case, output "yes" or "no" (without quotes) in a single line corresponding to the answer of the problem.
Constraints
1 ≤ T ≤ 10^6
2 ≤ N ≤ 10^5
1 ≤ Q ≤ 10^6
1 ≤ i, j ≤ N
0 ≤ val ≤ 1
Sum of each of N, Q over all test cases doesn't exceed 106
Input
4
2 2
1 1 0
1 2 1
2 3
1 1 0
1 2 1
2 1 0
3 2
2 2 0
2 3 1
3 3
1 2 1
2 3 1
1 3 1
Output
yes
no
yes
no
*/
#include<bits/stdc++.h>
using namespace std;
    

bool biPi(vector<int>* edges, int n) {
    bool* visited = new bool[n]();
    for(int i=0;i<n;i++){
        if(!visited[i]) {
            if(!bipartrite(edges, i, n, visited)){
                return false;
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, q;
        cin>>n>>q;
        vector<int>* edges = new vector<int>[n];
        unordered_set<int> sets[2];
        bool flag = true;
        for(int i=0;i<q;i++) {
            int s, e, val;
            cin>>s>>e>>val;
            s-=1;
            e-=1;
            if(val == 0){
                if((sets[0].count(s)>0 && sets[1].count(e)>0) || (sets[1].count(s)>0&&sets[0].count(e)>0) ){
                    flag = false;
                    continue;
                }
                if(sets[0].count(s) > 0){
                    sets[0].insert(e);
                } else if(sets[1].count(s) > 0){
                    sets[1].insert(e);
                } else if(sets[0].count(e) > 0){
                    sets[0].insert(s);
                } else if(sets[1].count(e) > 0){
                    sets[1].insert(s);
                }   else {
                    sets[0].insert(s);
                    sets[0].insert(e);
                }
            }
            if(val == 1){
                edges[s].push_back(e);
                edges[e].push_back(s);
                // if((sets[0].count(s)>0 && sets[0].count(e)>0) || (sets[1].count(s)>0&&sets[1].count(e)>0) ){
                //     flag = false;
                //     continue;
                // }else {
                    if(sets[0].count(s)>0){
                        sets[1].insert(e);
                    }else if(sets[0].count(e)>0) {
                        sets[1].insert(s);    
                    } else if(sets[1].count(s)>0) {
                        sets[0].insert(e);
                    }else if(sets[1].count(e)>0) {
                        sets[0].insert(s);
                    }
                    {
                        sets[0].insert(s);
                        sets[1].insert(e);
                    }
                // }
            }
        }
        // for(int i=0;i<2;i++) {
        //     unordered_set<int>::iterator it = sets[i].begin();
        //     while(it!=sets[i].end()) {
        //         cout<<*it<<" "<<i<<endl;
        //         it++;
        //     }
        //     cout<<endl;
        // }
        if(biPi(edges,n)&&flag)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
}












