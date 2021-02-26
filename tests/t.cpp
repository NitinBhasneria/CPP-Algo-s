#include <iostream>
using namespace std;


int main() {
    int a[4][4];
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            cin>>a[i][j];
        }
    int q=0,w=0,e=3,r=3;
    int where=0;
    while(q<=e||w<=r){
        // cout<<"values are "<<"q="<<q<<" w="<<w<<" e="<<e<<" r="<<r<<endl;
        if(where==0){
            for(int i=w;i<=e;i++){
                cout<<a[q][i]<<" ";
            }
            q++;
        }
        else if(where==1){
            for(int i=q;i<=r;i++){
                cout<<a[i][r]<<" ";
            }
            e--;
        }
        else if(where==2){
            for(int i=e;i>=w;i--){
                cout<<a[r][i]<<" ";
            }
            r--;
        }
        else if(where==3){
            for(int i=r;i>=q;i--){
                cout<<a[i][w]<<" ";
            }
            w++;
        }
        where = (where+1)%4;
    }
}