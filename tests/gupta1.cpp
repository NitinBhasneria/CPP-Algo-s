#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<string> str;
    string order;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>str[i];
    }
    unordered_map<char, int> mapa;
    cin>>order;
    for(int i=0;i<26;i++){
        mapa[order[i]] = i;
    }
    for(auto i=str.begin();i!=str.end();i++) {

    }
}