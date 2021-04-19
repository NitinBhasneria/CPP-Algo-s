#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli countOne(string a, lli n) {
    lli count=0;
    char prev=a[0], current,next;
    for(lli i=1;i<n;i++){
        current=a[i];
        if(prev=='0'&&current=='1'&&a[i+1]=='0'){
            count++;
            prev = a[i+1];
            i++;
        }
        if(prev=='1'&&current=='0'){
            prev='0';
        }
    }
    // cout<<count<<endl;
    return count;
}

int main() {
    lli n,x,y;
    cin>>n>>x>>y;
    string a;
    cin>>a;
    lli sum=-1;
    lli count = countOne(a,n);
    cout<<count<<endl;
    lli c = count+1;
    if(count==0){
        sum=0;
        bool flag = false;
        for(lli i=0;i<n;i++){
            if(a[i]=='0')
                flag = true;
        }
        if(flag)
            sum+=y;
        cout<<sum;
    }
    else{
        for(lli r=0;r<=count;r++){
            lli temp = x*r+y*c;
            cout<<r<<" "<<c<<" "<<temp<<endl;
            if(temp<sum||sum==-1)
                sum=temp;
            c--;
        }
        cout<<sum;
    }
}