/*
Minimum In SubArray
Send Feedback
Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.
Input:
First line of the test case contains two integers, N and Q, size of array A and number of queries.
Second line contains N space separated integers, elements of A.
Next Q lines contain one of the two queries.
Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].
Contraints:
1≤N,Q,y≤10^5
1≤l,r,x≤N
Sample Input :
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5
Sample Output :
1
1
2
1
*/
#include<bits/stdc++.h>
using namespace std;

void buildTree(int* arr, int* tree, int start, int end, int treeNode) {
    if(start == end){
        tree[treeNode] = arr[start];
        return;
    }

    int mid = (start + end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);

    tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode+1]);
}

void updateTree(int*arr, int* tree, int start, int end, int treeNode, int index, int value) {
    if(start == end){
        arr[index] = value;
        tree[treeNode] = value;
        return;
    }

    int mid = (start + end)/2;
    if(index > mid){
        updateTree(arr, tree, mid+1, end, 2*treeNode+1, index, value);
    }
    else {
        updateTree(arr, tree, start, mid, 2*treeNode, index, value);
    }
    tree[treeNode] = min(tree[2*treeNode] , tree[2*treeNode+1]);
}

int query(int* tree, int start, int end, int treeNode, int left, int right){
    if(left > end || right < start){
        return INT_MAX;
    }
    if(left <= start && right >= end){
        return tree[treeNode];
    }
    int mid = (start + end)/2;
    int ans1 = query(tree, start, mid, 2*treeNode, left, right);
    int ans2 = query(tree, mid+1, end, 2*treeNode+1, left, right);
    return min(ans1, ans2);
}

int main() {
    int n, q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int* tree = new int[4*n];
    buildTree(arr, tree, 0, n-1, 1);
    while(q--){
        char f;
        int left, right;
        cin>>f>>left>>right;
        if(f=='q')
            cout<<query(tree, 0, n-1, 1, left-1, right-1)<<"\n";
        else if(f=='u')
            updateTree(arr, tree, 0, n-1, 1, left-1, right);
    }
    delete[] tree;
}

















