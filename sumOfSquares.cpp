/*
Sum Of Squares
Send Feedback
Segment trees are extremely useful. In particular "Lazy Propagation" (i.e. see here, for example) allows one to compute sums over a range in O(lg(n)), and update ranges in O(lg(n)) as well. In this problem you will compute something much harder:
The sum of squares over a range with range updates of 2 types:
1) increment in a range
2) set all numbers the same in a range.
Input
There will be T (T <= 25) test cases in the input file. First line of the input contains two positive integers, N (N <= 100,000) and Q (Q <= 100,000). 
The next line contains N integers, each at most 1000. Each of the next Q lines starts with a number, which indicates the type of operation:

2 st nd -- return the sum of the squares of the numbers with indices in [st, nd] {i.e., from st to nd inclusive} (1 <= st <= nd <= N).

1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).

0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).
Output
For each test case output the “Case <caseno>:” in the first line and from the second line output the sum of squares for each operation of type 2. Intermediate overflow will not occur with proper use of 64-bit signed integer.
Input:
2
4 5
1 2 3 4
2 1 4
0 3 4 1
2 1 4
1 3 4 1
2 1 4
1 1
1
2 1 1
Output:
Case 1:
30
7
13
Case 2:
1
*/
#include<bits/stdc++.h>
using namespace std;

struct node {
    long long s;
    long long sos;
};
struct lazyNode {
    int value = 0;
    int type = 0; // 1 for add, 2 for set;
};
void buildTree(int* arr, node* tree, int start, int end, int treeNode) {
    if(start == end) {
        node r;
        r.s = arr[start];
        r.sos = pow(arr[start], 2);
        return;
    }
    int mid = (start + end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);

    tree[treeNode].s = tree[2*treeNode].s + tree[2*treeNode+1].s;
    tree[treeNode].sos = tree[2*treeNode].sos + tree[2*treeNode+1].sos;
}
void updateSegmentTreeLazy(node* tree, lazyNode* lazy, int start, int end, int treeNode, int left, int right, int value, int type) {
    if(start > end){
        return;
    }
    if(lazy[treeNode].type != 0){
        if(lazy[treeNode].type == 1){
            tree[treeNode].sos += (2*lazy[treeNode].value*tree[treeNode].s);
            tree[treeNode].s += lazy[treeNode].value*(end-start+1);

            if(start!=end){

                
                    lazy[2*treeNode].value += lazy[treeNode].value;
                    lazy[2*treeNode].type = lazy[treeNode].type;
                    
                    lazy[2*treeNode+1].value += lazy[treeNode].value;
                    lazy[2*treeNode+1].type = lazy[treeNode].type;
            }
        }
        else {
            tree[treeNode].sos = lazy[treeNode].value*lazy[treeNode].value*(end-start+1);
            tree[treeNode].s = lazy[treeNode].value*(end-start+1);

            if(start!=end) {
                    lazy[2*treeNode].value = lazy[treeNode].value;
                    lazy[2*treeNode].type = lazy[treeNode].type;
                    
                    lazy[2*treeNode+1].value = lazy[treeNode].value;
                    lazy[2*treeNode+1].type = lazy[treeNode].type;
            }
        }
        lazy[treeNode].value = 0;
        lazy[treeNode].type = 0;
    }
    if(start > right || end < left) {
        return;
    }
    if(left<=start && right>=end) {
        tree[treeNode].sos = 2*value*tree[treeNode].s + value*value*(end-start+1);
        tree[treeNode].s = value*(end-start+1);
        if(start!=end){
            if(type == 2) {
                lazy[2*treeNode].value = value;
                lazy[2*treeNode].type = type;
                
                lazy[2*treeNode+1].value = value;
                lazy[2*treeNode+1].type = type;
            }
            else {

                lazy[2*treeNode].value += value;
                lazy[2*treeNode].type = type;
                
                lazy[2*treeNode+1].value += value;
                lazy[2*treeNode+1].type = type;
            }  
        } 
    }
    // Partial overlap
    int mid = (start + end)/2;
    updateSegmentTreeLazy(tree, lazy, start, mid, 2*treeNode, left, right, value, type);
    updateSegmentTreeLazy(tree, lazy, mid+1, end, 2*treeNode+1, left, right, value, type);
    tree[treeNode].s = tree[2*treeNode].s + tree[2*treeNode+1].s;
    tree[treeNode].sos = tree[2*treeNode].sos + tree[2*treeNode+1].sos;
}

node query(node* tree, int start, int end, int treeNode, int left, int right) {
    if(left > end || right < left){
        node r;
        r.s= 0;
        r.sos = 0;
        return r;
    }
    if(left <= start && right >=end){
        return tree[treeNode];
    }
    int mid = (start+end)/2;
    node ans1 = query(tree, start, mid, 2*treeNode, left, right);
    node ans2 = query(tree, mid+1, end, 2*treeNode+1, left, right);

    node ans;
    ans.s = ans1.s + ans2.s;
    ans.sos = ans1.sos + ans2.sos;

    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, q;
        cin>>n>>q;
        int arr[n];
        for(int i=0;i<n;i++)    
            cin>>arr[i];
        node* tree = new node[4*n];
        buildTree(arr, tree, 0, n-1, 1);
        lazyNode* lazy = new lazyNode[4*n];
        updateSegmentTreeLazy(tree, lazy, 0, n-1, 1, 0, 1, 5, 2);
        // for(int i=1;i<2*n;i++)
        //     cout<<tree[i].sos<<" ";
    }
}