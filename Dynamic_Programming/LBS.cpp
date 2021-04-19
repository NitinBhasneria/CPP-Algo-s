/*
Largest Bitonic Subarray
Send Feedback
You are given an array of positive integers as input. Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a subsequence is known as bitonic subsequence. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.
Input Format:
Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array 
Output Format:
Length of Largest Bitonic subsequence
Input Constraints:
1<= N <= 100000
Sample Input 1:
6
15 20 20 6 4 2
Sample Output 1:
5
Sample Output 1 Explanation:
Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.
Sample Input 2:
2
1 5
Sample Output 2:
2
Sample Input 3:
2
5 1
Sample Output 3:
2
*/


#include<bits/stdc++.h>
using namespace std;

void LIS(int* arr, int n, int* increase){
    increase[0] = 1;
    for(int i=1;i<n;i++){
        increase[i] = 1;
        for(int j=i-1;j>=0;j--){
            if(arr[j]>=arr[i]){
                continue;
            }
            else {
                int possibleAns = increase[j]+1;
                if(possibleAns>increase[i])
                    increase[i] = possibleAns;
            }
        }
    }
}

void LDS(int* arr, int n, int* decrease){
    decrease[n-1] = 1;
    for(int i=n-2;i>=0;i--){
        decrease[i] = 1;
        for(int j=i-1;j<n;j++){
            if(arr[j]>=arr[i]){
                continue;
            }
            else {
                int possibleAns = decrease[j]+1;
                if(possibleAns>decrease[i])
                    decrease[i] = possibleAns;
            }
        }
    }
}

int LBS(int* arr, int n){
    int* increase = new int[n];
    int* decrease = new int[n];
    LIS(arr, n, increase);
    LDS(arr, n, decrease);
    for(int i=0;i<n;i++)
        cout<<increase[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<decrease[i]<<" ";
    cout<<endl;
    int best = 0;
    for(int i=0;i<n;i++){
        if(increase[i]==1){
            if(best < decrease[i])
                best = decrease[i];
            continue;
        }
        if(decrease[i]==1){
            if(best < increase[i])
                best = increase[i];
            continue;
        }
        if((increase[i]+decrease[i])>best)
            best = increase[i] + decrease[i];
    }
    delete[] increase;
    delete[] decrease;
    return best-1;
}

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<LBS(arr ,n);
    delete[] arr;
}