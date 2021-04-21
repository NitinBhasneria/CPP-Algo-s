#include<bits/stdc++.h>
using namespace std;

void buildZ(int* Z, string str) {
    int l = 0;
    int r = 0;

    int n = str.length();

    for(int i=0;i<n;i++) {
        if(i>r){  //    Out of range. It means we dont have answers OR We dont have checked it yet
            // i dont lie between l and r
            // Z for this doesn't exist
            l = i;  //  
            r = i;
            while(r<n && str[r] == str[r-l]) {
                r++;
            }
            Z[i] = r-l;
            r--;
        } else {    // In the range of checked range
            int k = i-l;
            if(Z[k] <= r-i){    // In the range
                // i is in range od l and r 
                // Z of this exist previously
                Z[i] = Z[k];
            } else {            // Out of range

                // some part of Z is already included 
                // You hvae to start matching further
                l = i;  // l changes while r remains same
                while(r<n && str[r] == str[r-l]){
                    r++;
                }
                Z[i] = r-l;
                r--;
            }
        }
        
    }
}

void searchPattern(string str, string pattern) {
    string temp = pattern + "$" + str;
    int n = temp.length();
    int* Z = new int[n]();
    buildZ(Z, temp);
    for(int i=0;i<n;i++) {
        if(Z[i] == pattern.length()) {
            cout<<i-pattern.length()-1<<endl;
        }
    } 

}

int main() {
    string s, p;
    cin>>s>>p;
    searchPattern(s, p);
    return 0;
}