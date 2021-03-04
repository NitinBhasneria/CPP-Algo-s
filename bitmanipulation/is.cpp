#include<bits/stdc++.h>
using namespace std;
int main() {

	int n,k,l;
    cin>>n>>k>>l;
    int a[n];
    float avg=0.0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        avg+=a[i];    
    }
    avg=ceil(avg/n);
    int sum=-1;
    for(int j=avg;;j++){
        int m=0,le=0;
        for(int i=0;i<n;i++){
        if((a[i]-j)>0)
            m += (a[i]-j);
        if((a[i]-j)<0)
            le+= (j-a[i]);
        }
        int r = m;
        m=le-m;
        int temp=r*k+l*m;
                cout<<j<<" "<<temp<<" "<<r<<" "<<m<<" "<<sum<<endl;
        if(temp<sum||sum==-1){
            sum=temp;
        }
        if(temp>sum&&sum!=-1)
            break;
    }
    cout<<sum;
}