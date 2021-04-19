/*
Boredom
Send Feedback
Gary is bored and wants to play an interesting but tough game . So he figured out a new board game called "destroy the neighbours" . In this game there are N integers on a board. In one move, he can pick any integer x from the board and then all the integers with value x+1 or x-1 gets destroyed .This move will give him x points.
He plays the game until the board becomes empty . But as he want show this game to his friend Steven, he wants to learn techniques to maximise the points to show off . Can you help Gary in finding out the maximum points he receive grab from the game ?
Input Format :
Line 1 : Integer N 
Line 2 : A list of N integers
Output Format :
Maximum points Gary can recieve from the Game setup
Constraints :
1<=N<=10^5
1<=A[i]<=1000
Sample Input :
2
1 2
Sample Output :
2
*/

#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>A;

int solve_more (vector<int> num, int m, unordered_map<int,int> num_counts, int* dp){
    if(m==0)
        return 0;
    if(m==1)
        return num[m-1]*num_counts[num[m-1]];
    if(dp[m-1] != -1)
        return dp[m-1];
    int ans;
    if(num[m-1] == (num[m-2]+1)){
        int option1 = num[m-1]*num_counts[num[m-1]] + solve_more(num, m-2, num_counts, dp);
        int option2 = solve_more(num, m-1, num_counts, dp);
        // cout<<num[m-1]<<" "<<option1<<" "<<option2<<endl;
        ans = max(option1, option2);
    }
    else{
        ans = num[m-1]*num_counts[num[m-1]] + solve_more(num, m-1, num_counts, dp);
    }
    // cout<<m<<" "<<ans<<endl;
    dp[m-1] = ans;
    return ans;
}

int solve(int n, vector<int> A){
    sort(A.begin(), A.end());
    
    vector<int> num;
    unordered_map<int, int> num_counts;

    int p = A[0];
    int c = 1, m=1;
    num.push_back(p);
    for(int i=1;i<n;i++){
        if(p!=A[i]){
            num.push_back(A[i]);
            num_counts[p] = c;
            m++;
            c = 1;
            p = A[i];
        }
        else {
            c++;
        }
    }
    if(p!=A[n-1]){
        num.push_back(A[0]);
        num_counts[p] = c;
        m++;
    }
    else {
        num_counts[p] = c;
    }
    int* dp = new int[m+1];
    for(int i=0;i<m;i++)
        dp[i] = -1;
    // for(int i=0;i<m;i++)
    //     cout<<num[i]<<" "<<num_counts[num[i]]<<endl;
    //     cout<<endl;
    int ans = solve_more(num, m, num_counts, dp);
    delete[] dp;
    return ans;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		A.push_back(x);
	}
	cout<<solve(n,A)<<endl;
}