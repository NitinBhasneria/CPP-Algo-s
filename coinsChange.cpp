/*
Coin Change Problem
Send Feedback
For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible.
Input Format
The first line of the input contains an integer value N, which denotes the total number of denominations.

The second line of input contains N values, separated by a single space. These values denote the value of denomination.

The third line of the input contains an integer value, that denotes the value of V.
Output Format
Print the total total number of ways i.e. W.
Constraints :
1 <= n <= 10
1 <= V <= 1000

Time Limit: 1sec
Sample Input 1 :
3
1 2 3
4
Sample Output 1 :
4
Explanation to Sample Input 1 :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
Sample Input 2 :
6
1 2 3 4 5 6
250
Sample Output 2 :
13868903
*/

#include <bits/stdc++.h>
using namespace std;

int countWaysToMakeChange(int* denominations, int numDenominations, int value, map<int, int> out){
	//Write your code here

    if(value == 0)
        return 1;
    if(value < 0)
        return 0;
    if(numDenominations == 0)
        return 0;
    int first, second;
    if((out[value][numDenominations])>-1){
        first = out[value][numDenominations];
    }
    else{
        first = countWaysToMakeChange(denominations, numDenominations, value - denominations[0], out);
        out[value][numDenominations] = first;
    }
    if(out[value][numDenominations]>-1){
        second = out[value][numDenominations];
    }
    else{
        second = countWaysToMakeChange(denominations+1, numDenominations-1, value, out);
        out[value][numDenominations] = second;
    }
                                        
	return first + second;
}

int main()
{

	int numDenominations;
	cin >> numDenominations;
	
	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++)
	{
		cin >> denominations[i];
	}

	int value;
	cin >> value;
    map <int, int> a;
    for(int i=0;i<value;i++){
        for(int j=0;j<numDenominations;j++)
            a[i][j] = -1;
    }
	cout << countWaysToMakeChange(denominations, numDenominations, value, a);
    // for(int i=0;i<value;i++){
    //     delete[] a[i];
    // }
    // delete[] a;
	delete[] denominations;
}