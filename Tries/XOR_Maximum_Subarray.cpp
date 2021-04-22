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
        insert(root, pre_xor);
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