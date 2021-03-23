/*
Subset Sum - Problem
Send Feedback
You are given a set of N integers. You have to return true if there exists a subset that sum up to K, otherwise return false.
Input Format
The first line of the test case contains an integer 'N' representing the total elements in the set.

The second line of the input contains N integers separated by a single space.    

The third line of the input contains a single integer, denoting the value of K.
Output Format
Output Yes if there exists a subset whose sum is k, else output No.
Constraints :
1 <= N <= 10^6
1 <= a[i] <= 10^3, where a[i] denotes an element of the set 
1 <= K <= 10^3

Time Limit: 1 sec
Sample Input 1 :
4
4 3 5 2
13
Sample Output 1 :
No
Sample Input 2 :
5
4 2 5 6 7
14
Sample Output 2 :
Yes
*/
#include <bits/stdc++.h>
using namespace std;

bool solve(int* arr, int n, int sum, int** dp) {
    if(n==0) return false;

    if(dp[n][sum] != -1) return (dp[n][sum] ==1) ? true : false;  

    if((sum-arr[n-1]) == 0) 
        return true;
    
    bool ans  = solve(arr, n-1, sum-arr[n-1], dp) || solve(arr, n-1, sum, dp);

    dp[n][sum] = ans ? 1 : 0;

    return ans;
}

bool isSubsetPresent(int *arr, int n, int sum)
{   if(sum == 0) return true;
    int** dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[sum+1];
        for(int j=0;j<=sum;j++){
            dp[i][j] = -1;
        }
    }
    //Write your code here
    bool ans = solve(arr, n, sum, dp);
    for(int i=0;i<=n;i++){
        delete [] dp[i];
    }
    delete[] dp;
    return ans;
}

int main()
{
    int n, sum;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> sum;

    if (isSubsetPresent(arr, n, sum))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    delete[] arr;
}