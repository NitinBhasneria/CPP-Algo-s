#include <string>
#include<iostream>
using namespace std;
string key[12] = {"", "", "abc", "def", "ghi", "kjl", "mno", "pqrs", "tuv", "wxyz"};
int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
   if(num==0){
        output[0]="";
        return 1;
    }
    int smallNum = num%10;
    int remaining = num/10;
    int smallOutput = keypad(remaining, output);
    for(int i=0;i<smallOutput*key[smallNum].size();i++){
        output[i]=output[i%smallOutput];
        // cout<<output[i]<<" ";
    }
    // cout<<endl;
    int j=0;
    for(int i=0;i<smallOutput*key[smallNum].size();i++){
        if(i%smallOutput==0 && i!=0)
            j++;
        output[i]=output[i]+key[smallNum][j];
    }
    return key[smallNum].size() * smallOutput; 
}


int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
