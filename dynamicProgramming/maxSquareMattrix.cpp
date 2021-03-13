/*
Maximum Square Matrix With All Zeros
Send Feedback
Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.
Input format :
The first line of the test case contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively.

Second-line onwards, the next 'N' lines or rows represent the ith row values.

Each of the ith rows constitutes column values separated by a single space (Either 0 or 1).
Output Format:
Print the size of maximum square sub-matrix.
 Constraints :
0 <= N <= 10^4
0 <= M <= 10^4

Time Limit: 1 sec
Sample Input 1:
3 3
1 1 0
1 1 1
1 1 1
Sample Output 1:
1
Sample Input 2:
4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
Sample Output 2:
4
*/

#include <iostream>
using namespace std;

int fill_dp(int** arr, int n, int m, int si, int sj, int** dp){ 
	if(si==0||sj==0){
		int a = (arr[si][sj]==1 ? 0 : 1);
		dp[si][sj] = a;
		return a;
	}
	if(si>n||sj>m){
		return -1;
	}
	if(dp[si][sj]!=-1)
		return dp[si][sj];
	
	int ans;
	if(arr[si][sj] == 1){
		ans = 0;
	}
	else {
		ans= min(fill_dp(arr,n,m,si-1,sj-1,dp),(min(fill_dp(arr,n,m,si-1,sj,dp),fill_dp(arr,n,m,si,sj-1,dp))));
		if(ans == 0)
			ans = (arr[si][sj]==1 ? 0 : 1);
		else	
			ans+=1;
	}// cout<<si<<" "<<sj<<" "<<ans<<endl;

	dp[si][sj] = ans;
	
	return ans;
}

int findMaxSquareWithAllZeros(int **arr, int n, int m)
{	if(n==0&&m==0)
		return 0;
	int** dp = new int* [n];
	for(int i=0;i<n;i++){
		dp[i] = new int[m];
		for(int j=0;j<m;j++){
			dp[i][j] = -1;
		}
	}
	fill_dp(arr,n, m, n-1,m-1,dp);
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }
	int max = -1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(dp[i][j]>max)
				max = dp[i][j];
		}
	}
	for(int i=0;i<n;i++)
		delete[] dp[i];
	delete[] dp;
	return max;
}

int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}