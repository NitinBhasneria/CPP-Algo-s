#include<bits/stdc++.h>
using namespace std;
int N = pow(10,9)+7;

int balancedBTs(int n) {
    // Write your code here
    if(n==2)
        return 3;
    if(n==1)
        return 1;
    int x = balancedBTs(n-1);
    int y = balancedBTs(n-2);
    long res1 = (long)x*x;
    long res2 = (long)2*x*y;
    int ans1 = (int)(res1%N);
    int ans2 = (int)(res2%N);
    return (ans1+ans2)%N;
}
int main() {
    int n;
    cin>>n;
    cout<<balancedBTs(n);
}