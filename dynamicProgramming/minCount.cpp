/*
Minimum Count
Send Feedback
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
Input format :
The first and the only line of input contains an integer value, 'N'.
 Output format :
Print the minimum count of numbers required.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1)

B) (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1)  + (2 ^ 2)

C) (1^1) + (1^1) + (1^1) + (1^1) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
*/

#include<bits/stdc++.h>
using namespace std;

int getHigh(int n, int curr) {
    int ans= n/curr;
    ans = ans / curr;
    // cout<<n<<" "<<curr<<" "<<ans<<" high"<<endl;
    return ans;
}



int solve(int n, int curr, int* dp) {
    if(n==1 || n==0)
        return n;
    if(curr == 1)
        return n;
    if(curr == 0)
        return INT_MAX;
    if(pow(curr,2) == n)
        return 1;
    if(dp[n] != -1)
        return dp[n];
    // Taking curr
    int c = getHigh(n, curr); //finding the highest factor;
    int r = n - (c * pow(curr, 2));
    int option1 = c + solve(r, sqrt(r), dp);
    // not taking curr
    int option2 = solve(n, curr-1, dp);
    
    int ans =  min(option1, option2);
    // cout<<n<<" "<<curr<<" "<<ans<<endl;
    dp[n] = ans;
    return ans;
}   

int minCount(int n)
{       
    // cout<<(int)sqrt(n)<<endl;
    int* dp = new int[n+1];
    for(int i=0;i<n+1;i++)
        dp[i] = -1;
    int ans =  solve(n, (int)sqrt(n), dp);
    // for(int i=0;i<n+1;i++)
    //     cout<<dp[i]<<" ";
    // cout<<endl;
    delete[]  dp;
    return ans;
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}