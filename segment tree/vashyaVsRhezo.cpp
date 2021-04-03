/* 
Vasya vs Rhezo
Send Feedback
Queen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line. Let us number the warriors by numbers from 1 to N. She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
For each warrior, we know 2 values associated with him, let us call these A and B. Each day Vasya can choose her warrior from a range Li to Ri, she must choose the warrior with maximum A value. If there is more than 1 warrior having the same maximum A value, she chooses the warrior with minimum B value. If still there is more than 1 warrior with same maximum A value and same minimum B value, she chooses the one with lower index in line.
You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.
Input:
First line contains a single integer N, denoting the number of warriors Queen Vasya has. 
Second line contains N space separated integers Ai. Third line contains N space separated integers Bi.
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
Each of the next Q lines contains 2 integers Li and Ri.
Output:
For each Li and Ri, print the index of the warrior that Queen Vasya should choose.
Constraints:
1≤ N,Q ≤10^6
1≤ Ai,Bi ≤10^9
1≤Li≤Ri
Sample Input
5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5
Sample Output
2
2
4
5
*/
#include<bits/stdc++.h>
using namespace std;

struct node {
    int A;
    int B;
    int index;
};
void buildTree(int* A, int* B, node* tree, int start, int end, int treeNode) {
    if(start == end) {
        tree[treeNode].A = A[start];
        tree[treeNode].B = B[start];
        tree[treeNode].index = start;
        return;
    }
    
    int mid = (start + end)/2;
    
    buildTree(A, B, tree, start, mid, 2*treeNode);
    buildTree(A, B, tree, mid+1, end, 2*treeNode+1);
    node L = tree[2*treeNode];
    node R = tree[2*treeNode+1];

    if(L.A > R.A){
        tree[treeNode] = L;
    } else if(L.A < R.A){
        tree[treeNode] = R;
    } else {
        if(L.B < R.B){
            tree[treeNode] = L;
        } else if(L.B > R.B){
            tree[treeNode] = R;
        }
        else {
            if(L.index < R.index) {
                tree[treeNode] = L;
            } else if(L.index > R.index){
                tree[treeNode] = R;
            } 
        }
    }
}

node query(node* tree, int start, int end, int treeNode, int left, int right){
    if(left > end || right < start) {
        return {0,0,0};
    }
    if(left <= start && right >= end) {
        return tree[treeNode];
    }
    int mid = (start + end)/2;
    node L = query(tree, start, mid, 2*treeNode, left, right);
    node R = query(tree, mid+1, end, 2*treeNode+1, left, right);

    node ans;
    if(L.A > R.A){
        ans = L;
    } else if(L.A < R.A){
        ans = R;
    } else {
        if(L.B < R.B){
            ans = L;
        } else if(L.B > R.B){
            ans = R;
        }
        else {
            if(L.index < R.index) {
                ans = L;
            } else if(L.index > R.index){
                ans = R;
            } 
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)    
        cin>>A[i];
    int B[n];
    for(int i=0;i<n;i++)    
        cin>>B[i];
    node* tree = new node[4*n];
    buildTree(A, B, tree, 0, n-1, 1);
    int q;
    cin>>q;
    while(q--) {
        int L, R;
        cin>>L>>R;
        cout<<query(tree, 0, n-1, 1, L-1, R-1).index+1<<endl;
    }
}
















