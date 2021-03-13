/*
Count BSTs
Send Feedback
Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.
Input Format :
Integer n 
Output Format :
Count of BSTs
Contraints :
1<= N <=1000
Sample Input 1:
8
Sample Output 1:
1430
Sample Input 2:
3
Sample Output 2:
5
*/

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int nBST(int n, int* dp) {
    if(n==0 || n==1)
        return n;
    if(dp[n] != -1)
        return dp[n];
    long ans = 0;
    for(int i=1;i<=n;i++){
        long a = (nBST(i-1, dp)) % MOD;
    	if(a==0)
            a=1;
        long b = (nBST(n-i, dp)) % MOD;
        if(b==0)
            b=1;
        ans += ((a * b) % MOD);
    }
    // cout<<n<<" "<<ans<<endl;
    ans = ans % MOD;
    int l = (int)ans;
    dp[n] = l;
    return dp[n];
} 

int countBST (int n){
    int* dp = new int[n+1];
    for(int i=0;i<n+1;i++)
        dp[i] = -1;
    int count = 0;
    count = nBST(n, dp);

    // for(int i=0;i<n+1;i++)
    //     cout<<dp[i]<<" ";
    //  cout<<endl;

    delete[] dp;
    return count;
}

int main() {
    int n ;
	cin>>n;
	cout<<countBST(n);
	return 0;
}