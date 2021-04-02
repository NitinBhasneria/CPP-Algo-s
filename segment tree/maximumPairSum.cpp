#include<bits/stdc++.h>
using namespace std;

struct answer {
    int max;
    int secMax;
};

void buildTree(int* arr, answer* tree, int start ,int end, int treeNode) {
    if(start == end) {
        tree[treeNode].max = arr[start];
        tree[treeNode].secMax = 0;
        return; 
    }
    int mid = (start+end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    tree[treeNode].max = max(tree[2*treeNode].max, tree[2*treeNode+1].max);
    tree[treeNode].secMax = min(max(tree[2*treeNode].max, tree[2*treeNode+1].secMax), max(tree[2*treeNode].secMax, tree[2*treeNode+1].max));
}

void updateTree (int* arr, answer* tree, int start, int end, int treeNode, int index, int value) {
    if(start == end){
        arr[index] = value;
        tree[treeNode].max = value;
        tree[treeNode].secMax = 0;
        return;
    }

    int mid = (start+end)/2;
    if(index > mid){
        updateTree(arr, tree, mid+1, end, 2*treeNode+1, index, value);
    } else {
        updateTree(arr, tree, start, mid, 2*treeNode, index, value);
    }

    tree[treeNode].max = max(tree[2*treeNode].max, tree[2*treeNode+1].max);
    tree[treeNode].secMax = min(max(tree[2*treeNode].max, tree[2*treeNode+1].secMax), max(tree[2*treeNode].secMax, tree[2*treeNode+1].max));
}

answer query(answer* tree, int start, int end, int treeNode, int left, int right) {
    if(start > right || end < left){
        answer r;
        r.max = 0;
        r.secMax = 0;
        return r;
    } 
    if(start >= left && end <= right) {
        return tree[treeNode];
    }
    int mid = (start + end)/2;
    answer ans1 = query(tree, start, mid ,2*treeNode, left, right);
    answer ans2 = query(tree, mid+1, end, 2*treeNode+1, left, right);

    answer ans;
    ans.max = max(ans1.max, ans2.max);
    ans.secMax = min(max(ans1.max, ans2.secMax), max(ans1.secMax,ans2.max));

    return ans;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    answer* tree = new answer[4*n];
    buildTree(arr, tree, 0, n-1, 1);
    int q;
    cin>>q;
    while(q--){
        char what;
        int left, right;
        cin>>what>>left>>right;
        if(what == 'Q'){
            answer ans = query(tree, 0, n-1, 1, left-1, right-1);
            cout<<ans.max+ans.secMax<<"\n";
        }
        else if(what == 'U'){
            updateTree(arr, tree, 0, n-1, 1, left-1, right);
        }
    }
    delete[] tree;
}