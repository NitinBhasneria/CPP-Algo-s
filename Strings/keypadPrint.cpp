#include <iostream>
#include <string>
using namespace std;
string key[12]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void print (int num, string output){
    if(num==0){
        cout<<output<<"\n";
        return;
    }
    int rem = num%10;
    int left = num/10;
    for(int i=0;i<key[rem].size();i++){
        print(left, output+key[rem][i]);
    }
    
}

void printKeypad(int num){
    string output;
    print(num, output);
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
