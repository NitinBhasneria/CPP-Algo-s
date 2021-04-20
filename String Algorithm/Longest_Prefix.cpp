#include<bits/stdc++.h>
using namespace std;

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
    string p;
    cin>>p;
    int* answer = getLps(p);
    for(int i=0;i<p.length();i++){
        cout<<answer[i]<<" ";
    }
}