#include<iostream>
using namespace std;

void printSubs (string input, string output){
    if(input.size()==0){
        cout<<output<<endl;
        return;
    }
    string temp = input.substr(1);
    printSubs(temp, output);
    printSubs(temp, output+input[0]);

}

int main(){
    string s;
    cin>>s;
    string ss;
    printSubs(s,ss);

    return 0;
}