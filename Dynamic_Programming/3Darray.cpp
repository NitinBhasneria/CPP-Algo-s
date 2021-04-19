#include<bits/stdc++.h>
using namespace std;

int main() {
    // int arr[2][2][2];
    // for(int i=0;i<2;i++)
    //     for(int j=0;j<2;j++)
    //         for(int k=0;k<2;k++)    
    //             cin>>arr[i][j][k];

    
    // for(int i=0;i<2;i++)
    //     for(int j=0;j<2;j++)
    //         for(int k=0;k<2;k++)    
    //             cout<<arr[i][j][k];


    // Vector
    // it will give error
    // vector<int,int,int> arr;

    // Dynamic
    int*** dp = new int**[2];
    for(int i=0;i<2;i++){
        dp[i] = new int*[2];
        for(int j=0;j<2;j++){
            dp[i][j] = new int[2];
        }
    }

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)    
                cin>>dp[i][j][k];

    
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)    
                cout<<dp[i][j][k];

    return 0;    
}