/*
Shortest Subsequence
Send Feedback
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.
Note: The input data will be such that there will always be a solution.
Input Format :
The first line of input contains a string, that denotes the value of S. The following line contains a string, that denotes the value of V.
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Constraints:
1 <= N <= 1000
1 <= M <= 1000 
Time Limit: 1 second
Sample Input 1:
babab
babba
Sample Output 1:
3
Explanation:
"aab" is the shortest subsequence which is present in S and absent in V.
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 1005
#include<bits/stdc++.h>
#define MAX 1005
int solve2(char *S, char *T, int m, int n, int** dp)
{	
    if(dp[m][n]!=-1)
        return dp[m][n];
    // S string is empty
    if (m == 0)
        return MAX;
 
    // T string is empty
    if (n <= 0)
        return 1;
 
    // Loop to search for current character
    int k;
    for (k=0; k < n; k++)
        if (T[k] == S[0])
            break;
 
    // char not found in T
    if (k == n)
        return 1;
 
    // Return minimum of following two
    // Not including current char in answer
    // Including current char
    int ans = min(solve2(S+1, T, m-1, n, dp),
            1 + solve2(S+1, T+k+1, m-1, n-k-1, dp));
    dp[m][n] = ans;
    return ans;
}

int solve(string s, string v) {
    int n = s.length();
    int m = v.length();
    
    int** dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[m+1];
        for(int j=0;j<=m;j++)
            dp[i][j] = -1;
    }
    char str[n];
    strcpy(str,s.c_str());
    char str2[m];
    strcpy(str2, v.c_str());
    int ans = solve2(str, str2, n, m, dp);
    for(int i=0;i<=n;i++){
        delete[] dp[i];
    }
    delete[] dp;
    return ans;
}

int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}