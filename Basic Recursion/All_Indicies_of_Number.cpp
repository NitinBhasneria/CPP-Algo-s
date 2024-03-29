/*
Send Feedback
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
indexes where x is present in the array (separated by space)
Constraints :
1 <= N <= 10^3
Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4
*/

#include<iostream>
using namespace std;

int findFirstIndex(int input[], int size, int x){
    if(size==0)
        return -1;
    if(input[0]==x){
        input[0]=x+1;
    	return 0;
    }
	int index = findFirstIndex(input+1, size-1, x);
    return index==-1?-1:index+1;
}

int allIndexes(int input[], int size, int x, int output[]) {
    int i=0,index=findFirstIndex(input, size, x);
    while(index!=-1){
        // cout<<index<<endl;
     	output[i++]=index;   
        index=findFirstIndex(input, size, x);
    }
    return i;
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}
