#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,k;
        long long int sum,summ=0,SUM=0;
        cin>>n>>k;
        long long int a[n];
        for(long long int i=0;i<n;i++){
          cin>>a[i];
          SUM+=a[i];
        }
        if(2*k>SUM) {cout<<"-1"<<endl;continue;}
        if(n==1) {cout<<"-1"<<endl;continue;}
        if( (n==2) && ( (a[0]<k)||(a[1]<k) ) ) {cout<<"-1"<<endl;continue;}
        if( (n==2) && ( (a[0]>=k)||(a[1]>=k) ) ) {cout<<"2"<<endl;continue;}
        sort(a,a+n,greater<long long int>());
        long long int j=2,count=1,u=2,r,l=0;
        sum=a[0];
        while(j<n){
          sum+=a[j];
          if(sum>k){sum=sum-a[j];break;}
          j=j+2;
          u=j;
          count++;
        }
        j=u+1;
        while((k-sum<=a[j])&&(j<n)){
          j++;
          r=j-1;
          l=1;
        }
        if(l){
          sum+=a[r];
          count=count+1;
        }
        if(sum<k){cout<<"-1"<<endl;continue;}     
        a[r]=0;
        long long int CounT=0,h=1,Count=0;
        while((summ<=k)&&(h<u)){
          summ+=a[h];
          h=h+2;
          Count++;
        }
        while((summ<=k)&&(u<n)){
          summ+=a[u];
          u++;
          CounT++;
          if(a[u]==0) CounT--;
        }
        if(summ<k) cout<<"-1"<<endl;
        else cout<<count+Count+CounT<<endl;
    }
  return 0;
}