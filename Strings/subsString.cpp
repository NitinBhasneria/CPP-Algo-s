#include<iostream>
using namespace std;

int subs(string input, string output[]){
    if(input.empty()){
        output[0] = "";
        return 1;
    }
    string small_string = input.substr(1);
    int smallOutput = subs(small_string, output);
    for(int i=0;i<smallOutput;i++){
        output[i+smallOutput]=input[0]+output[i];
    }
    return 2*smallOutput;
}

int main(){
    string s;
    cin>>s;
    string *ss = new string[1000];
    int size = subs(s, ss);
    for(int i=0;i<size;i++)
        cout<<ss[i]<<"\n";
}