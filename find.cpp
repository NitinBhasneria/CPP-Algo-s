#include<bits/stdc++.h> 
using namespace std;
  
int main () 
{
    int n;
    cin>>n;
    int arr[n];
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        v.push_back(arr[i]);    
    }
    auto pos = find(arr, arr+n, 5);
    if(pos!=(arr+n))
        cout<<pos-arr<<endl;
    vector<int>::iterator itr;
    itr = find(v.begin(), v.end(), 5);
    if(itr!=end(v))
        cout<<itr-v.begin()<<endl;
    
}