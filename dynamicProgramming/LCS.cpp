/*
LCS - Problem
Send Feedback
Given two strings, S and T with lengths M and N, find the length of the 'Longest Common Subsequence'.
For a string 'str'(per se) of length K, the subsequences are the strings containing characters in the same relative order as they are present in 'str,' but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to K.
Example :
Subsequences of string "abc" are:  ""(empty string), a, b, c, ab, bc, ac, abc.
Input format :
The first line of input contains the string S of length M.

The second line of the input contains the String T of length N.
Output format :
Print the length of the 'Longest Common Subsequence'.
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1sec
Sample Input 1 :
adebc
dcadb
Sample Output 1 :
3
Explanation of the Sample Input 1 :
Both the strings contain a common subsequence 'adb', which is the longest common subsequence with length 3. 
Sample Input 2 :
ab
defg
Sample Output 2 :
0
Explanation of the Sample Input 2 :
The only subsequence that is common to both the given strings is an empty string("") of length 0.
*/

#include<bits/stdc++.h>
using namespace std;

int lcs1 (string s, int m, string t, int n, int** dp) {
    if(m==0||n==0)
        return 0;
    if(dp[m][n] > -1)
        return dp[m][n];

    int ans;    
    if(s[m-1] == t[n-1])    
        ans = 1 + lcs1(s, m-1, t, n-1, dp);
    else {
        int option1 = lcs1(s, m, t, n-1, dp);
        int option2 = lcs1(s, m-1, t, n, dp);
        ans = max(option1, option2);
    }
    dp[m][n] = ans;
    return ans;
}

int lcs(string s, string t) {
    int m = s.size();
    int n = t.size();
    int** dp = new int *[m+1];
    for(int i=0;i<=m;i++){
        dp[i] = new int[n+1];
        for(int j = 0;j <= n; j++) {
            dp[i][j] = -1;
        }
    }
    int ans = lcs1 (s, m, t, n, dp);
    // for(int i=0;i<=m;i++){
    //     for(int j = 0;j <= n; j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<m+1;i++){
        delete[] dp[i];
    }
    delete[] dp;
    return ans;
}

int main()
{
	string s; 
	string t;

	cin >> s;
	cin >> t;

	cout << lcs(s, t) << endl;
}