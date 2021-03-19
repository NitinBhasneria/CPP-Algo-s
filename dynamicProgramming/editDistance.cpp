/*
Edit Distance - Problem
Send Feedback
You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note :
Strings don't contain spaces in between.
 Input format :
The first line of input contains the string S of length M.

The second line of the input contains the String T of length N.
Output format :
Print the minimum 'Edit Distance' between the strings.
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1 :
abc
dc
Sample Output 1 :
2
 Explanation to the Sample Input 1 :
 In 2 operations we can make string T to look like string S.
First, insert character 'a' to string T, which makes it "adc".

And secondly, replace the character 'd' of string T with 'b' from the string S. This would make string T as "abc" which is also string S. 

Hence, the minimum distance.
Sample Input 2 :
whgtdwhgtdg
aswcfg
Sample Output 2 :
9
*/

#include<bits/stdc++.h>
using namespace std;

int editDistance2(string s1, int m, string s2, int n, int** dp){
    if(m==0)
        return n;
    if(n==0)    
        return m;
    if(dp[m][n] > -1)
        return dp[m][n];
    
    int ans;
    if(s1[m-1]==s2[n-1]){
        ans = editDistance2(s1, m-1, s2, n-1, dp);
    }
    else {
        int option1 = 1 + editDistance2(s1, m-1, s2, n-1, dp);
        int option2 = 1 + editDistance2(s1, m, s2, n-1, dp);
        int option3 = 1 + editDistance2(s1, m-1, s2, n, dp);
        ans = min(option1, min(option2, option3));
    }
    dp[m][n] = ans;
    return ans;
}

int editDistance(string s1, string s2)
{
	int m = s1.size();
    int n = s2.size();
    int** dp = new int*[m+1];
    for(int i=0;i <= m; i++) {
        dp[i] = new int[n+1];
        for(int j=0;j<=n; j++){
            dp[i][j] = -1;
        }
    }
    int ans = editDistance2(s1, m, s2, n, dp);
    for(int i=0;i <= m; i++) {
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2) << endl;
}