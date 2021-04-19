#include<bits/stdc++.h>
using namespace std;
struct job{
    int st, fn, p;
};
bool sortJob(job a, job b){
    return a.fn < b.fn;
}
int solve2(job* val, int n, int lastFinish, int** dp){
    if(dp[n][lastFinish] != -1) 
        return dp[n][lastFinish];
    if(n==0){return 0;}
    int ans;
    if(lastFinish <= val[0].st){
        int option1 = val[0].p + solve2(val+1, n-1, val[0].fn, dp);
        int option2 = solve2(val+1, n-1, lastFinish, dp);
        ans = max(option1, option2);
    } else {
        int option1 = solve2(val+1, n-1, lastFinish, dp);
        ans = option1;
    }
    dp[n][lastFinish] = ans;
    return ans;
}

int solve(job* val, int n){
    int inc[n];
    inc[0] = val[0].p;
    for(int i=1;i<n;i++){
        int include = val[i].p;
        int conflict = -1;
        for(int j=i-1;j>=0;j--){
            if(val[j].fn<=val[i].st){
                conflict = j;
                break;
            }
        }
        if(conflict!=-1){
            include+=inc[conflict];
        }
        inc[i] = max(include, inc[i-1]);
    }
    return inc[n-1];
    // int** dp = new int*[n+1];
    // int m = val[n-1].fn;
    // for(int i=0;i<=n;i++){
    //     dp[i] = new int[m+1];
    //     for(int j=0;j<m+1;j++)
    //         dp[i][j] = -1;
    // }
    // int ans = solve2(val, n, 0, dp);
    // return ans;
}

int main () {
    int n;
    cin>>n;
    job val[n];
    for(int i=0;i<n;i++){
        int a, b, c;
        cin>>a>>b>>c;
        val[i].st = a; val[i].fn = b; val[i].p = c;
    }
    sort(val,val+n,sortJob);
    cout<<solve(val, n);
    return 0;
}