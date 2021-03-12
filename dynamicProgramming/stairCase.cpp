/*
StairCase Problem
Send Feedback
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.
Input format :
The first and the only line of input contains an integer value, 'n', denoting the total number of steps.
Output format :
Print the total possible number of ways.
 Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1:
4
Sample Output 1:
7
Sample Input 2:
10
Sample Output 2:
274
*/

#include<bits/stdc++.h>
using namespace std;

int ways(int n) {
    long* out = new long[n];
    if(n==0)
        return 1;
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    long w1, w2, w3;
    if(out[n-1]>0){
        w1 = out[n-1];}
    else {
        w1 = ways(n-1);
        out[n-1] = w1;    
    }
    if(out[n-2]>0){
        w2 = out[n-2];}
    else {
        w2 = ways(n-2);
        out[n-2] = w2;
    }

    if(out[n-3]>0)
        w3 = out[n-3];
    else {
        w3 = ways(n-3);
        out[n-3] = w3;
    }
    // cout<<w1<<" "<<w2<<" "<<w3<<endl;
    long way = w1+w2+w3;
    delete[] out;
    return way;
}

int main() {
    int n;
    cin>>n;
    cout<<ways(n);
}