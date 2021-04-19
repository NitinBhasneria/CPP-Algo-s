/*
Maximum Sum In Subarray
Send Feedback
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.
Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.
Output
Your program should output the results of the M queries, one 
query per line.
Sample Input:
3 
-1 2 3 
1
1 2
Sample Output:
2
*/

#include<bits/stdc++.h>
using namespace std;

struct node {
    int maxSum;
    int BPS;
    int BSS;
    int sum;
};

void buildTree (int* arr, node* tree, int start, int end, int treeNode) {
    if(start == end) {
        tree[treeNode].sum = arr[start];
        tree[treeNode].maxSum = arr[start];
        tree[treeNode].BSS = arr[start];
        tree[treeNode].BPS = arr[start];
        return;
    }

    int mid = (start+end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    node L = tree[2*treeNode];
    node R = tree[2*treeNode+1];
    tree[treeNode].sum = (L.sum + R.sum);
    tree[treeNode].BPS = max(L.BPS, L.sum+R.BPS);
    tree[treeNode].BSS = max(R.BSS, R.sum+L.BSS);
    tree[treeNode].maxSum = max(max(L.maxSum, R.maxSum), max(L.sum+R.BPS, max(R.sum + L.BSS, L.BSS + R.BPS)));
}

node query(node* tree, int start, int end, int treeNode, int left, int right) {
    // cout<<start<<" "<<end<<" "<<left<<" "<<right<<endl;
    if(start > right || end < left) {
        node n;
        n.sum = 0;
        n.maxSum =0;
        n.BSS = 0;
        n.BPS = 0;
        return n;
    }
    if(start >= left && end <= right) {
        return tree[treeNode];
    }
    int mid = (start+end)/2;
    node L = query(tree, start, mid, 2*treeNode, left, right);
    node R = query(tree, mid+1, end, 2*treeNode+1, left, right);
    node ans;
    ans.sum = (L.sum + R.sum);
    ans.BPS = max(L.BPS, L.sum+R.BPS);
    ans.BSS = max(R.BSS, R.sum+L.BSS);
    ans.maxSum = max(max(L.maxSum, R.maxSum), max(L.sum+R.BPS, max(R.sum + L.BSS, L.BSS + R.BPS)));
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    node* tree = new node[4*n];
    buildTree(arr, tree, 0, n-1, 1);
    int q;
    cin>>q;
    while(q--) {
        int left, right;
        cin>>left>>right;
        cout<<query(tree, 0, n-1, 1, left-1, right-1).maxSum<<endl;
    }

}













