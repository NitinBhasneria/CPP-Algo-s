#include<bits/stdc++.h>
using namespace std;

int solve2 (string str1, string str2, int n, int m, int** dp) {
    if(n==0&&m==0)  return 0;
    if(n==0) return m;
    if(m==0) return n;
    if(dp[n][m] != -1){
        return dp[n][m];
    }
    int ans;
    if(str1[n-1] == str2[m-1]){
        ans = 1 + solve2(str1, str2, n-1, m-1, dp);
    }
    else {
        int option1 = 1 + solve2(str1, str2, n-1, m ,dp);
        int option2 = 1 + solve2(str1, str2, n, m-1, dp);

        ans = min(option1, option2);
    }
    dp[n][m] = ans;
    return ans;
}

int smallestSuperSequence(string str1, string str2)
{   int n = str1.length();
    int m = str2.length();
	int** dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[m+1];
        for(int j=0;j<=m;j++){
            dp[i][j] = -1;
        }
    }
    int ans = solve2(str1, str2, str1.length(), str2.length(), dp);
    for(int i=0;i<=n;i++){
        delete[] dp[i];
    }
    delete[] dp;

    return ans;
}

int main()
{
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << smallestSuperSequence(str1, str2);
    return 0;
}