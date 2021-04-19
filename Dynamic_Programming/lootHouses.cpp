/*
Loot Houses
Send Feedback
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input format :
The first line of input contains an integer value of 'n'. It is the total number of houses.

The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.
Output format :
Print the the maximum money that can be looted.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110
Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90
Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.
*/

#include <iostream>
using namespace std;

int answer(int* arr, int n , int* dp) {
    if(n<=0)
        return 0;
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    
    int option1, option2;

    option1 = arr[n-1] + answer(arr, n-2, dp);
    option2 = answer(arr, n-1, dp);

    dp[n]= max(option1, option2);
    return dp[n];
}
//iterative
int maxMoneyLoot(int* arr, int n) {
    int* maxMoney = new int[n];
    maxMoney[0] = arr[0];
    if(n>1){
        maxMoney[1] = max(arr[1], arr[0]);
    }
    for(int i=2;i<n;i++){
        maxMoney[i] = max(maxMoney[i-2]+arr[i], maxMoney[i-1]);
    }
    int result = maxMoney[n-1];

    for(int i=0;i<n;i++){
        cout<<maxMoney[i]<<" ";
    }
    cout<<endl;
    delete[] maxMoney;
    return result;
}

int maxMoneyLooted(int* arr, int n) {
    int* dp = new int [n+1];
    for(int i=0;i<n+1;i++){
            dp[i]=-1;
    }
    int sum = 0;
    sum = answer(arr, n, dp);  
    return sum;
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}