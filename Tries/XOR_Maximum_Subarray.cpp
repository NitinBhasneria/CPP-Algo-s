/*
Maximum XOR Subarray
Send Feedback
Given
.0 an array of n integers, find subarray whose xor is maximum.
Input Format
First line contains single integer n (1<=n<=1000000).
Next line contains n space separated integers.
Output Format
Print xor of the subarray whose xor of all elements in subarray is maximum over all subarrays.
Constraints
1 <= n <= 1000000
1 <= A[i] <=100000 
Sample Input
4
1 2 3 4
Sample Output
7
*/
// Remember if x^y=z then z^y=x;
#include<bits/stdc++.h>
using namespace std;
 
struct trieNode
{
    int value;  
    trieNode *left;
    trieNode* right;
};
 

void insert(trieNode *root, int pre_xor)
{
    trieNode *curr = root;
 
    for (int i=31; i>=0; i--)
    {
        int b = (pre_xor>>i)&1;
 

        if(b==0) {
            if(!curr->left){
                curr->left = new trieNode();
            }
            curr = curr->left;
        } else {
            if(!curr->right){
                curr->right = new trieNode();
            }
            curr = curr->right;
        }
    }
 
    curr->value = pre_xor;
}
 
int maxSubarrayXOR(int arr[], int n)
{
    trieNode *root = new trieNode();
    insert(root, 0);
 
    int result = INT_MIN, pre_xor =0;
 
    for (int i=0; i<n; i++)
    {
        pre_xor = pre_xor^arr[i];
        
        trieNode* curr = root;
        for (int i=31; i>=0; i--)
        {
            int b = (pre_xor>>i)&1;
            if(b==0){
                if(curr->right){
                    curr = curr->right;
                } else {
                    curr = curr->left;
                }   
            }else {
                if(curr->left){
                    curr = curr->left;
                }else {
                    curr = curr->right;
                }
            }
        }
        insert(root, pre_xor);
        result = max(result, pre_xor^(curr->value));
    }
    return result;
}
 
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)        
        cin>>arr[i];
    cout <<maxSubarrayXOR(arr, n);
    return 0;
}