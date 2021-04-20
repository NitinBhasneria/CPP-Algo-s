#include<bits/stdc++.h>
using namespace std;

bool match(string s, string p) {
    int sLen = s.length();
    int pLen = p.length();

    for(int i=0;i<=(sLen-pLen);i++) {
        for(int j=0;j<pLen;j++) {
            if(p[j] == s[i+j]){
                if(j == pLen-1)
                    return true;
                continue;
            } else break;
        }
    }
    return false;
}

int main() {
    string s, p;
    cin>>s>>p;

    if(match(s,p))
        cout<<"PATTERN FOUND!"<<endl;
    else
        cout<<"PATTERN NOT FOUND"<<endl;
}