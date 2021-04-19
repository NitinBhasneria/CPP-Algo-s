#include<bits/stdc++.h>
using namespace std;

int fab (int n){
    if(n==1||n==0)
        return 1;
    return fab(n-1)+ fab(n-2);
}
int fab2 (int n, int* arr){
    if(n==0||n==1)
        return 1;
    if(arr[n]!=0)
        return arr[n];
    int output = fab2(n-1,arr)+fab2(n-2,arr);
    arr[n]=output;
    return output;
}
int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    cout<<fab2(n, arr);
    return 0;
}