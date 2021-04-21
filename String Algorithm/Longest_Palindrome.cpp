// TC: O(n^2)
#include<bits/stdc++.h>
using namespace std;

int longestPalindrome(string s) {
    
    int max = 0;
    int n = s.length();
    
    for(int i=0;i<n;i++) {

        // Odd length 

        int l = i;
        int r = i;
        while(l>=0 && r<n &&s[l]==s[r]){
            int curr = r-l+1;
            if(curr>max) 
                max = curr;
            l--;
            r++;
        }

        // Even length

            l = i;
            r = i+1;
        while(l>=0 && r<n &&s[l]==s[r]){
            int curr = r-l+1;
            if(curr>max)
                max = curr;
            l--;
            r++;
        }
    }

    return max;
}

int main() {
    string str;
    cin>>str;
    cout<<longestPalindrome(str);
}