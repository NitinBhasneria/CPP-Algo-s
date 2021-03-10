#include<iostream>
using namespace std;
int main(){
    int* r = new int();
    *r = 10;
    cout<<*r<<endl;
    int* ad = new int();
    ad = r;
    cout<<*ad<<" "<<*r<<endl;
    delete(ad);
    cout<<*ad<<" "<<*r<<endl;
}