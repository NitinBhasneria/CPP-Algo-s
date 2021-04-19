/*
Dominos
Send Feedback
Domino
Dominos are lots of fun. Children like to stand the tiles on their side in long lines. When one domino falls, it knocks down the next one, which knocks down the one after that, all the way down the line.
However, sometimes a domino fails to knock the next one down. In that case, we have to knock it down by hand to get the dominos falling again.
Your task is to determine, given the layout of some domino tiles, the minimum number of dominos that must be knocked down by hand in order for all of the dominos to fall.
Input
The first line of input contains one integer specifying the number of test cases to follow.Each test case begins with a line containing two integers,each no larger than 100 000. The first integer n is the number of domino tiles and the second integer m is the number of lines to follow in the test case. The domino tiles are numbered from 1 to n.
Each of the following lines contains two integers x and y indicating that if domino number x falls, it will cause domino number y to fall as well.
Output
For each test case, output a line containing one integer, the minimum number of dominos that must be knocked over by hand in order for all the dominos to fall.
Sample Input
1
3 2
1 2
2 3
Sample Output
1
*/

#include<bits/stdc++.h>
using namespace std;
#define mxsize 100005
bool visited[mxsize];
vector<int> adj[mxsize];
void dfs2(int sv,stack<int>&st){
    visited[sv]=true;
    for(int i=0;i<adj[sv].size();i++){
        if(!visited[adj[sv][i]]){
            dfs2(adj[sv][i],st);
        }
    }
    st.push(sv);
}
void dfs(int sv){
    visited[sv]=true;
    for(int i=0;i<adj[sv].size();i++){
        if(!visited[adj[sv][i]]){
            dfs(adj[sv][i]);
        }
    }
    // st.push(sv);
}
int getscc(int n){
    stack<int> st;
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs2(i,st);
        }
    }
    memset(visited,false,sizeof(visited));
    int ans=0;
    while(st.size()!=0){
        int top=st.top();
        st.pop();
        if(!visited[top]){
            ans++;
            dfs(top);
        }
    }
    return ans;
    
}
int main()
{
	//code
    int t;cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<mxsize;i++){
            adj[i].clear();
        }
        for(int i=0;i<m;i++){
			int x,y;
        	cin>>x>>y;
        	adj[x].push_back(y);
        }
        cout<<getscc(n)<<endl;
    }
	return 0;
}