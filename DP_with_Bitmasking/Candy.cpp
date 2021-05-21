/*
Candy
Send Feedback
Gary is a teacher at XYZ school. To reward his N students he bought a packet of N candies all with different flavours. But the problem is some students like certain flavour while some doesn't. Now Gary wants to know the number of ways he can distribute these N candies to his N students such that every student gets exactly one candy he likes.
Input Format :
Line 1 : An integer N (1<= N <= 16) denoting number of students and candies.
Next N lines : N integers describing the preferences of one student. 1 at i'th (0 <= i < N) position denotes that this student likes i'th candy , 0 means he doesn't.
Assume input to be 0-indexed based.
Output Format :
Return the number of ways Gary can distribute these N candies to his N students such that every student gets exactly one candy he likes.``
Sample Input:
3
1 1 1
1 1 1
1 1 1
Sample Output:
6
*/

#include<bits/stdc++.h>
using namespace std;

int noOfCandy(int n, int** arr,int candy, int mask, int* dp) {
    if(candy>=n){
        return 1;
    }
    int ans = 0;
    if(dp[mask]!=-1){
        return dp[mask];
    }
    for(int i=0;i<n;i++) {
        if(!(mask&(1<<i))&&(arr[i][candy])){
            ans += noOfCandy(n, arr, candy+1, (mask|(1<<i)), dp);
        }
    }
    dp[mask] = ans;
    return ans;
}

int main(){
    int n;
    cin>>n;
    int **arr = new int*[n];
    for(int i=0;i<n;i++) {
        arr[i] = new int[n];
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }
    int *dp = new int[(1<<n)-1];
    for(int i=0;i<((1<<n)-1);i++) {
            dp[i] = -1;
    }
    int answer = noOfCandy(n,arr,0,0,dp);
    cout<< answer<<"\n";
    return 0;
}