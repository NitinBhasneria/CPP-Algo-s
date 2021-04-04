    /*
    2 vs 3
    Send Feedback
    The fight for the best number in the globe is going to finally come to an end.The top two contenders for the best number are number 2 and number 3.It's the final the entire world was waiting for. Expectorates from all across the globe came to witness the breath taking finals.
    The finals began in an astonishing way.A common problem was set for both of them which included both these number.The problem goes like this.
    Given a binary string (that is a string consisting of only 0 and 1). They were supposed to perform two types of query on the string.
    Type 0: Given two indices l and r.Print the value of the binary string from l to r modulo 3.

    Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.
    The problem proved to be a really tough one for both of them.Hours passed by but neither of them could solve the problem.So both of them wants you to solve this problem and then you get the right to choose the best number in the globe.
    Input:
    The first line contains N denoting the length of the binary string .
    The second line contains the N length binary string.Third line contains the integer Q indicating the number of queries to perform.
    This is followed up by Q lines where each line contains a query.
    Output:
    For each query of Type 0 print the value modulo 3.
    Constraints:
    1<= N <=10^5

    1<= Q <= 10^5

    0 <= l <= r < N
    Sample Input
    5
    10010
    6
    0 2 4
    0 2 3
    1 1
    0 0 4
    1 1
    0 0 3
    Sample Output
    2
    1
    2
    1
    */

    #include<bits/stdc++.h>
    using namespace std;

    void buildTree(int* str, int* tree, int start, int end, int treeNode, int* dp) {
        if(start == end) {
            tree[treeNode] = str[start];
            return;
        }
        int mid = (start+end)/2;
        buildTree(str, tree, start, mid, 2*treeNode, dp);
        buildTree(str, tree, mid+1, end, 2*treeNode+1, dp);
        tree[treeNode] = ((tree[2*treeNode]*dp[end-mid])%3 + tree[2*treeNode+1]%3)%3;
    }

    void update(int* str, int* tree, int start, int end, int treeNode, int index, int*  dp) {
        if(start == end) {
                str[start] = 1;
                tree[treeNode] = 1;   
            return; 
        }

        int mid = (start+end)/2;
        if(index > mid){
            update(str, tree, mid+1, end, 2*treeNode+1, index, dp);
        }
        else {
            update(str,tree, start, mid, 2*treeNode, index, dp);
        }
        tree[treeNode] = ((tree[2*treeNode]*dp[end-mid])%3 + tree[2*treeNode+1]%3)%3;
    }

    int query(int* tree, int start, int end, int treeNode, int left, int right, int* dp) {
        if(left > end || right < start) {
            return 0;
        }
        if(left <= start && right >= end) {
            return (tree[treeNode]*dp[right-end])%3;
        }
        int mid = (start+end)/2;
        int ans1 = query(tree, start, mid, 2*treeNode, left, right, dp);
        int ans2 = query(tree, mid+1, end, 2*treeNode+1, left, right, dp);

        // cout<<ans1<<" "<<ans2<<" "<<start<<" "<<end<<" "<<abs(right - end)<<endl;
        int ans = (ans1%3 + ans2%3)%3;

        return ans;
    }

    int main() {
        int n = 0;
        cin>>n;
        string str;
        cin>>str;
        int* arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = str[i]-'0';
        }
        
        int* dp = new int[n+1];
        dp[0] = 1;
        for(int i=1; i<=n; i++){
            dp[i] = (2*dp[i-1])%3;
        }
        int* tree = new int[4*n];
        buildTree(arr, tree, 0, n-1, 1, dp);
        int q;
        cin>>q;
        while(q--) {
            int type, left, right;
            cin>>type;
            if(type==1){
                cin>>left;
                if(arr[left]==0)
                update(arr, tree, 0, n-1, 1, left, dp);
            } else {
                cin>>left>>right;
                cout<<query(tree, 0, n-1, 1, left, right, dp)<<endl;
            }
        }
        delete[] dp;
        delete[] tree;
        return 0;
    }




















