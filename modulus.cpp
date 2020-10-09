#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
// Code By Nitin Bhasneria

int modOf(int x, int y, int m){
    if(y==0)
        return 1;
    int k=modOf(x,y/2,m);
    if(y%2==0)
        return ((1LL*k*k)%m);
    else
        return (((1LL*k*k)%m)*x)%m; 
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
        int x,y,m;
        cin>>x>>y>>m;
        cout<<modOf(x,y,m);
	}
}

// id m is prime we can do modOf(x,y%(m-1),m);