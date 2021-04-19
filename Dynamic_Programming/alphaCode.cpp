/* 
AlphaCode-Question
Send Feedback
Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”

Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”

Alice: “How many different decodings?”

Bob: “Jillions!”
For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.
Input
Input will consist of multiple input sets. Each set will consist of a single line of at most 5000 digits representing a valid encryption (for example, no line will begin with a 0). There will be no spaces between the digits. An input line of ‘0’ will terminate the input and should not be processed.
Output
For each input set, output the number of possible decodings for the input string. Print your answer taking modulo "10^9+7"
Sample Input:
25114
1111111111
3333333333
0
Sample Output:
6
89
1
*/





#include<bits/stdc++.h>
using namespace std;
int N = pow(10,9)+7;

int num_code1(int* n, int size) {
	 if (size == 1) {
		 return 1;
	 }
	 if (size == 0) {
		 return 1;
	 }
	 int output = num_code1(n, size - 1);
	 if (n[size - 2] * 10 + n[size - 1] <= 26) {
		 output += num_code1(n, size -2);
	 }
	 return output;
}

//Dynamic
int num_code2(int* n, int size, int* out) {
	 if (size == 1) {
		 return 1;
	 }
	 if (size == 0) {
		 return 1;
	 }
     if(out[size]>0)
        return out[size];
	 int output = num_code2(n, size - 1, out);
	 if (n[size - 2] * 10 + n[size - 1] <= 26) {
		 output += num_code2(n, size -2, out);
	 }
     out[size]=output;
	 return output;
}


//iterative
int num_code3(int * input, int size) {
	int* output = new int[size + 1];
	output[0] = 1;
	output[1] = 1;

	for (int i = 2; i <= size; i++) {
		output[i] = (output[i - 1]%N);
		if (input[i-2] *10 + input[i - 1] <= 26) {
			output[i] += (output[i - 2]%N);
		}
	}
	int ans = output[size];
	delete [] output;
	return ans;
}

int main() {
    string str;
    while(cin>>str){
        int* arr = new int[str.size()+1];
        for(int i=0;i<str.size();i++){
            arr[i] = (str[i]-48);
        }
        int *out = new int[str.size()+1];
        cout<<num_code3(arr,str.size())<<endl;
    }
}