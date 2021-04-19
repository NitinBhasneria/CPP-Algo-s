#include<bits/stdc++.h>
using namespace std;

string isPossicle(int a[], int n){
    for(int i=0;i<n;i++){
        if((a[i]-i)>3){
            // cout<<a[i];
            return "NO";
        }
    }
    return "YES";
}

int main() {
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    string result = isPossicle(a,n);
    cout<<result<<endl;
    if(result == "YES"){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=abs(a[i]-(i+1));
        }
        cout<<sum/2;
    }
}