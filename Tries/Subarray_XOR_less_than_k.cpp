/* A straightforward question. Given an array of positive integers you have to print the number of subarrays whose XOR is less than K. Subarrays are defined as a sequence of continuous elements Ai, Ai+1, ..., Aj . XOR of a subarray is defined as Ai ^ Ai+1 ^ ... ^ Aj. Symbol ^ is Exclusive Or.
Input Format
First line contains T, the number of test cases. 
Each of the test case consists of N and K in one line, followed by N space separated integers in next line.
Output Format
For each test case, print the required answer.
Constraints:
1 ≤ T ≤ 5
1 ≤ N ≤ 10^5
1 ≤ A[i] ≤ 10^5
1 ≤ K ≤ 10^6
Sample Input
1
5 2
4 1 3 2 7   
Sample Output
3 */

#include <iostream>
using namespace std;

class trieNode {
    public:
        trieNode* left;
        trieNode* right;
        int rightCount;
        int leftCount;
    trieNode() {
        leftCount = 0;
        rightCount = 0;
        left = NULL;
        right = NULL;
    }
};

void insert(trieNode* head, int n) {
    trieNode* curr = head;
    for(int i=31;i>=0;i--) {
        int b = (n>>i)&1;
        if(b==0) {
            curr->leftCount++;
            if(!curr->left){
                curr->left = new trieNode();
            }
            curr = curr->left;
        } else {
            curr->rightCount++;
            if(!curr->right) {
                curr->right = new trieNode();
            }
            curr = curr->right;
        }
    }
}

int smallResult(trieNode* root, int k, int pre_xor){
    trieNode* curr = root;
    int res = 0;
    for(int i=31;i>=0;i--) {
        int kBit = (k>>i)&1;            // current bit of k
        int cBit = (pre_xor>>i)&1;      // current bit of pre_xor
        if(kBit ==0){
            if(cBit == 0) {
                if(curr->left) {
                    curr = curr->left;
                } else {
                    return res;
                }
            }else {
                if(curr->right){
                    curr= curr->right;
                } else {
                    return res;
                }
            }
        } else {
            if(cBit == 0) {
                res += curr->leftCount;
                if(curr->right){
                    curr = curr->right;
                } else {
                    return res;
                }
            }else {
                res += curr->rightCount;
                if(curr->left){
                    curr = curr->left;
                } else {
                    return res;
                }
            }
        }
    }
    return res;
}

long long maxSubarrayXORK(int* arr, int n, int k) {
    trieNode* root = new trieNode();
    insert(root, 0);
    long long res = 0;
    int pre_xor = 0;
    for(int i=0;i<n;i++) {
        pre_xor = pre_xor^arr[i];
        res += smallResult(root, k, pre_xor);
        insert(root, pre_xor);
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<maxSubarrayXORK(arr,n,k)<<endl;
    }
    return 0;
}