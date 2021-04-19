#include <bits/stdc++.h>
using namespace std;

class pB {
    public: 
        int fees;
        int fun;
    pB(int fees = 0, int fun = 0) {
        this->fees = fees;
        this->fun = fun;
    }
    
};

pB add(pB f2, pB f3) {   
    int fe = f2.fees + f3.fees;
    int fu = f2.fun + f3.fun;
    pB ans(fe, fu);
    return ans;
}

pB solve2(pB party[], int n, int b, pB dp[][505]) {
    if(n<=0){
        return pB(0, 0);
    }
    if(((dp[n][b].fees) != -1)){
        return dp[n][b];}

    pB ans;
    pB option1;
    pB a1;
    if((b-(party[n-1].fees))>=0){
        option1 = solve2(party, n-1, b-(party[n-1].fees), dp);
        a1 = add(option1, party[n-1]);
    }
    pB option2 = solve2(party, n-1, b, dp);

    if(a1.fun > option2.fun) {
        ans = a1;
    }
    else if(a1.fun == option2.fun) {
        if(a1.fees < option2.fees) {
            ans = a1;
        }
        else {
            ans = option2;
        }
    }
    else {
        ans = option2;
    }
    // ans = ((a1.fun > option2.fun)&&(a1.fees < option2.fees)) ? a1 : option2;
    dp[n][b] = ans;
    return ans;
}

void solve(pB party[], int n, int b){
    pB dp[n+1][505];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=b;j++){
            dp[i][j] = pB(-1, -1);
        }
    }
    pB p = solve2(party, n, b, dp);
    cout<<p.fees<<" "<<p.fun<<"\n";
}

int main()
{
    int b, n;
    cin>>b>>n;
    while(b&&n){
        pB party[n];
        int a,g;
        for(int i=0;i<n;i++){
            cin>>a>>g;
            party[i] = pB(a,g);
        }          
        solve(party, n, b);

        cin>>b>>n;
    }
    return 0;
}
