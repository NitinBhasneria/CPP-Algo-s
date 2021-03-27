/*
Distinct Subsequences
Send Feedback
Given a string, count the number of distinct subsequences of it ( including empty subsequence ). For the uninformed, A subsequence of a string is a new string which is formed from the original string by deleting some of the characters without disturbing the relative positions of the remaining characters.
For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.
Input
First line of input contains an integer T which is equal to the number of test cases. You are required to process all test cases. Each of next T lines contains a string s.
Output
Output consists of T lines. Ith line in the output corresponds to the number of distinct subsequences of ith input string. Since, this number could be very large, you need to output ans%1000000007 where ans is the number of distinct subsequences. 
Constraints and Limits
T ≤ 100, length(S) ≤ 100000

All input strings shall contain only uppercase letters.
Sample Input
3
AAA
ABCDEFG
CODECRAFT
Sample Output
4
128
496
*/

#include<bits/stdc++.h>
using namespace std;
#define N 1000000007;
typedef long l;

int solve2(string str, int n, int* mp) {
    if(n==1){
        mp[(char)str[0]] = 1;
        return 2;
    }
    
    l ans = solve2(str, n-1, mp);
    l temp = ans;
    l aa = (2*ans - mp[str[n-1]])%N;
    int final = (int)aa%N;
    mp[str[n-1]] = temp;
    if(final < 0) final += N;
    
    // cout<<temp<<" "<<final<<endl;
    return final;
}

int main() {
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        cout<<s.length()<<endl;
        int mp[140] = {0};
        int ans = solve2(s, s.length(), mp);
        cout<<ans<<"\n";
    }
}