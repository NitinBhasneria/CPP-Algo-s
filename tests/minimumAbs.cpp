#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    
        cin>>arr[i];
    int min = arr[0], max = arr[n-1], mini = 0, maxi = n-1;
    for(int i=0;i<n;i++){
        if(arr[i] < min) {
            int Old = abs(min - max) + abs(maxi - mini);
            int New = abs(arr[i] - max) + abs(maxi - i);
            cout<<mini+1<<" "<<maxi+1<<" "<<New<<" "<<Old<<endl;
            if(Old < New) {
                min = arr[i];
                mini = i;
            }

        }
        if(arr[i] > max) {
            int Old = abs(min - max) + abs(maxi - mini);
            int New = abs(min - arr[i]) + abs(i - mini);

            cout<<mini+1<<" h "<<maxi+1<<" "<<New<<" "<<Old<<endl;
            if(Old < New) {
                max = arr[i];
                maxi = i;
            }
        }
    }
    cout<<mini+1<<" "<<maxi+1<<" "<<abs(min - max) + abs(maxi - mini)<<endl;
}