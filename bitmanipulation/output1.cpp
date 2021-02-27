#include <iostream>
using namespace std;

int main(){
    int x = -2;
    x = x >> 1;
    cout << x;
    cout<<endl<<~1;
    int n,i;
    cin>>n>>i;
    cout<<endl<<(n|(1<<(i)));
}