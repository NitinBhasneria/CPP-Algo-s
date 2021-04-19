/*
Horrible Queries
Send Feedback
World is getting more evil and it's getting tougher to get into the Evil League of Evil. Since the legendary Bad Horse has retired, now you have to correctly answer the evil questions of Dr. Horrible, who has a PhD in horribleness (but not in Computer Science). You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -
0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.

1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
Input
In the first line you'll be given T, number of test cases.

Each test case will start with N (N <= 100 000) and C (C <= 100 000). After that you'll be given C commands in the format as mentioned above. 1 <= p, q <= N and 1 <= v <= 10^7.
Output
Print the answers of the queries.
Input:
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8 
0 5 7 14
1 4 8
Output:
80  
508
*/

#include<bits/stdc++.h>
using namespace std;

void updateSegmentTreeLazy(long long* tree, long long* lazy, int start, long end, int treeNode, int left, int right, int value) {
    if(start > end){
        return;
    }
    // check and update through lazy tree
    if(lazy[treeNode] != 0){
        tree[treeNode] += (end-start+1)*lazy[treeNode];
        if(start != end){
            lazy[2*treeNode] += lazy[treeNode];
            lazy[2*treeNode+1] += lazy[treeNode];
        }
        lazy[treeNode] = 0;
    }

    // No overlap
    if(start > right || end < left) {
        return;
    }

    // Complete overlap
    if(left <= start && end <= right) {
        tree[treeNode] += (end-start+1)*value;
        if(start != end){
            lazy[2*treeNode] += value;
            lazy[2*treeNode+1] += value;
        }
        return;
    }

    // Partial overlap
    int mid = (start + end)/2;
    updateSegmentTreeLazy(tree, lazy, start, mid, 2*treeNode, left, right, value);
    updateSegmentTreeLazy(tree, lazy, mid+1, end, 2*treeNode+1, left, right, value);
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

long long query(long long* tree, long long* lazy, int start, long  end, int treeNode, int left, int right) {
    if(start > end)
        return 0;
    // check and update through lazy tree
    if(lazy[treeNode] != 0){
        tree[treeNode] += (end-start+1)*lazy[treeNode];
        if(start != end){
            lazy[2*treeNode] += lazy[treeNode];
            lazy[2*treeNode+1] += lazy[treeNode];
        }
        lazy[treeNode] = 0;
    }
    
    if(left > end || right < start)
        return 0;

    if(left <= start && right >= end) {
        return tree[treeNode];
    }
    int mid = (start+end)/2;
    long long ans1 = query(tree, lazy, start, mid, 2*treeNode, left, right);
    long long ans2 = query(tree, lazy, mid+1, end, 2*treeNode+1, left, right);

    return ans1 + ans2;
}

int main () {
    int t;
    cin>>t;
    while(t--) {
        int n, c;
        cin>>n>>c;
        int arr[n] = {0};
        long long* tree = new long long[3*n];
        long long* lazy = new long long[3*n]; 
        while(c--) {
            int type;
            cin>>type;
            if(type == 0) {
                int left, right, value;
                cin>>left>>right>>value;
                updateSegmentTreeLazy(tree, lazy, 0, n-1, 1, left-1, right-1, value);
            }
            else {
                int left, right;
                cin>> left >> right;
                cout<<query(tree, lazy, 0, n-1, 1, left-1, right-1)<<endl;
            }
        }
    }
}












