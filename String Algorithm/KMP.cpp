#include<bits/stdc++.h>
using namespace std;

bool kmpSearch(string s, string p, int* lps) {
    
    int sLen = s.length();
    int pLen = p.length();
     
    int i=0, j=0;
    while(i<sLen && j<pLen) {
        if(s[i]==p[j]) {
            i++;
            j++;
        } else {
            if(j != 0) {
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }
    if(j == pLen) 
        return true;
    return false;
}

int* getLps(string p) { // returns array
    
    int len = p.length();
    int* lps = new int[len];

    lps[0] = 0;
    int i=1, j=0;
    while(i<len) {

        if(p[i] == p[j]){
            lps[i] = j+1;
            j++;
            i++;
        } else {
            if(j!=0){
                j = lps[j-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int main() {
    string s, p;
    cin>>s>>p;
    int *lps = getLps(p);
    if(kmpSearch(s, p, lps))
        cout<<"Patern Found!";
    else 
        cout<<"Not Found";
}