// Time Complexity O{n^3}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll M[101][101];
ll kadane(vector<ll> v){
    int n = v.size();
    int i, j;
    ll ret = 0, me = INT_MIN, csum = 0;
    for(i=0;i<n;i++) {
        csum += v[i];
        if(csum < 0)
            csum = 0;
        ret = max(ret, csum);
        me = max(me, v[i]);
    }
    if(me < 0)
        return me;
    else    
        return ret;
}

int main() {
    ll mxsum = INT_MIN, sum, i, j, k, n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>M[i][j];
    
    for(int l=0;l<m; l++){
        vector<ll> v(n, 0);
        for(int r=l; r<m; r++){
            for(i=0;i<n;i++)
                v[i] += M[i][r];
            mxsum = max(kadane(v), mxsum);
        }
    }
    cout<<mxsum<<endl;
}