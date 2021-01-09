#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;

void powerSet(int arr[], int n){
    int m=pow(2,n);
    for(int i=0;i<m;i++){
        cout<<"{";
        for(int j=0;j<n;j++)
            if(i&(1<<j))
                cout<<arr[j]<<", ";
        cout<<"}, ";
    }
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        powerSet(arr, n);
	}
}