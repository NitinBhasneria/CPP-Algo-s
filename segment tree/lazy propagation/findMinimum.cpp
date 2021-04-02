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

void updateSegmentTreeLazy(int* tree, int* lazy, int start, int end, int treeNode, int left, int right, int value) {
    if(start > end){
        return;
    }
    // check and update through lazy tree
    if(lazy[treeNode] != 0){
        tree[treeNode] += lazy[treeNode];
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
        tree[treeNode] += value;
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
    tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode+1]);
}

int main() {
    int arr[] = {1, 3, -2, 4};
    int* tree = new int[12];
    buildTree(arr, tree, 0, 3, 1);
    int* lazy = new int[12];
	updateSegmentTreeLazy(tree,lazy,0,3,1,0,3,3);
	updateSegmentTreeLazy(tree,lazy,0,3,1,0,1,2);


    cout<< "Segment Tree" <<endl;
	for(int i=1;i<12;i++){
		cout<<tree[i]<< endl;
	}

	cout<< "Lazy Tree" <<endl;
	for(int i=1;i<12;i++){
		cout<<lazy[i]<< endl;
	}

    return 0;
}