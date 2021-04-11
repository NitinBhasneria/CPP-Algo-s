#include<bits/stdc++.h>
using namespace std;

int main() {
    int num = 10;
    int *p = &num;
    int *v = p;
    cout<<*p<<" "<<*v<<endl;

    return 0;
}