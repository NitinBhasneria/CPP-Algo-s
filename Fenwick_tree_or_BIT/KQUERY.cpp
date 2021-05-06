/*
KQUERY
Send Feedback
Given a sequence of n numbers a1, a2, ..., an and a number of k- queries. A k-query is a triple (i, j, k) (1 ≤ i ≤ j ≤ n). For each k-query (i, j, k), you have to return the number of elements greater than k in the subsequence ai, ai+1, ..., aj.
Input Format
Line 1: n (1 ≤ n ≤ 30000).

Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 10^9).

Line 3: q (1 ≤ q ≤ 200000), the number of k- queries.

In the next q lines, each line contains 3 numbers i, j, k representing a k-query (1 ≤ i ≤ j ≤ n, 1 ≤ k ≤ 10^9).
Output Format
For each k-query (i, j, k), print the number of elements greater than k in the subsequence ai, ai+1, ..., aj in a single line.
Sample Input
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2 
Sample Output
2
0
3 
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 30002
struct input {
    int value, index;
} arr[MAX];
struct node {
    int left, right, k, index;
} query[200005];

bool compare(node a, node b) {
    return a.k>b.k;
}
bool compare2(input a, input b) {
    return a.value>b.value;
}
int bit[MAX];

void update(int i,int n)
{
    for(;i<=n;i+=(i&(-i))){
        bit[i]++;
    }
}

int output(int index) {
    int res = 0;
    for(;index>0;index-= index & (-index)){
        res += bit[index];
    }
    return res;
}

int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].value;
        arr[i].index = i;
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>query[i].left>>query[i].right>>query[i].k;
        query[i].index = i;
    }

    sort(query, query+q,compare);
    arr[0].value = INT_MAX;
    arr[0].index = INT_MAX;
    
    sort(arr, arr+n+1, compare2);
    
    int j=1;
    int* ans = new int[q]();
    for(int i=0;i<q;i++) {
        while(j<=n) {
            if(arr[j].value > query[i].k){
                // cout<<query[i].k<<" "<<arr[j].value<<"\n";
                // cout<<"added"<<arr[j].value<<endl;
                update(arr[j].index, n);
                j++;
            } else{
                break;
            }
        }
        int temp = output(query[i].right) - output(query[i].left-1);
        // cout<<query[i].left<<" "<<query[i].right<<" "<<temp<<endl;
        ans[query[i].index] = temp;
    }
    for(int i=0;i<q;i++) {
        cout<< ans[i] <<"\n";
    }

    delete[] ans;
    return 0;
}


















