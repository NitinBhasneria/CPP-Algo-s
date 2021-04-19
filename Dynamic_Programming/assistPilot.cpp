/*
Charlie and Pilots
Send Feedback
Charlie acquired airline transport company and to stay in business he needs to lower the expenses by any means possible. There are N pilots working for his company (N is even) and N/2 plane crews needs to be made. A plane crew consists of two pilots - a captain and his assistant. A captain must be older than his assistant. Each pilot has a contract granting him two possible salaries - one as a captain and the other as an assistant. A captain's salary is larger than assistant's for the same pilot. However, it is possible that an assistant has larger salary than his captain. Write a program that will compute the minimal amount of money Charlie needs to give for the pilots' salaries if he decides to spend some time to make the optimal (i.e. the cheapest) arrangement of pilots in crews.
Input
The first line of input contains integer N, 2 ≤ N ≤ 10,000, N is even, the number of pilots working for the Charlie's company. The next N lines of input contain pilots' salaries. The lines are sorted by pilot's age, the salaries of the youngest pilot are given the first. Each of those N lines contains two integers separated by a space character, X i Y, 1 ≤ Y < X ≤ 100,000, a salary as a captain (X) and a salary as an assistant (Y).
Output
The first and only line of output should contain the minimal amount of money Charlie needs to give for the pilots' salaries. 
Sample Input
4 
5000 3000 
6000 2000 
8000 1000 
9000 6000 
Sample Output
19000 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve2 (int* a, int* p, int n, int x, int**dp) {
    if(dp[n][x] != -1)
        return dp[n][x];
    if(n==1){
        return p[0];
    }
    if(x==0){
        // cout<<a[0]<<endl;
        return (a[0] + solve2(a+1, p+1, n-1, 1, dp));
    }
    if(x==n){
        // cout<<p[0]<<endl;
        return (p[0] + solve2(a+1, p+1, n-1, x-1, dp));
    }
    ll ans;
    ll option1 = a[0] + solve2(a+1, p+1, n-1, x+1, dp);
    ll option2 = p[0] + solve2(a+1, p+1, n-1, x-1, dp);

    ans = min(option1, option2);
    dp[n][x] = ans;
    // cout<<ans<<" "<<option1<<" "<<option2<<" "<<n<<endl;
    return ans;
}

ll solve1(int* a, int* p, int n){
    ll x = 0;  // number of assitant and captain difference
    int** dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[n];
        for(int j=0;j<n;j++)
            dp[i][j] = -1;
    }
    ll ans =  solve2(a,p,n,x, dp);
    return ans;
}

int main() {
    int n;cin>>n;
    int* a = new int[n];
    int* p = new int[n];
    for(int i=0;i<n;i++){    
        cin>>p[i];
        cin>>a[i];
    }
    cout<<solve1(a,p,n);

    delete[] a;
    delete[] p;
}