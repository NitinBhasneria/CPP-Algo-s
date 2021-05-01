/*
OrderSet - Problem
Send Feedback
In this problem, you have to maintain a dynamic set of numbers which support the two fundamental operations
INSERT(S,x): if x is not in S, insert x into S
DELETE(S,x): if x is in S, delete x from S
and the two type of queries
K-TH(S) : return the k-th smallest element of S
COUNT(S,x): return the number of elements of S smaller than x
Input Format
Line 1: Q (1 ≤ Q ≤ 200000), the number of operations
In the next Q lines, the first token of each line is a character I, D, K or C meaning that the corresponding operation is INSERT, DELETE, K-TH or COUNT, respectively, following by a whitespace and an integer which is the parameter for that operation.

If the parameter is a value x, it is guaranteed that ≤ |x| ≤ 10^9. If the parameter is an index k, it is guaranteed that 1 ≤ k ≤ 10^9.`
Output
For each query, print the corresponding result in a single line. In particular, for the queries K-TH, if k is larger than the number of elements in S, print the word 'invalid'.
Input Format
8
I -1
I -1
I 2
C 0
K 2
D -1
K 1
K 2
Output Format
1
2
2
invalid
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 200005

struct node {
    int count = 0;
    bool visited = false;
} bit[MAX];
char C[MAX];

void update(int index, int value) {
    if(value == 1 && bit[index].visited){
        // cout<<"already inserted\n";
        return;
    } else if(value == -1 && !bit[index].visited) {
        // cout<<"Does not exist \n";
        return;
    }
    // cout<<"process\n";
    bit[index].visited = (value==1) ? true:false;
    index+=1;
    for(;index<MAX;index += (index&(-index))) {
        bit[index].count += value;
    }
}
int get_count(int idx)
{
    if (idx == 0 || idx == -1)
        return 0;
    ll sum = 0;
    while (idx > 0)
    {
        //printf("BIT: %d\n", BIT[idx]);
        sum += bit[idx].count;
        idx -= idx & (-idx);
    }
    return sum;
}
int main() {
    int q;
    cin>>q;
    int arr[q];
    map<ll, ll> M;
    for(int i=0;i<q;i++) {
        cin>>C[i];
        cin>>arr[i];
        if(C[i] == 'I'){
            M[arr[i]] = 0;
        }
    }
    int count = 1;
    int rankArr[q];
    int j = 0;
    for(auto i:M) {
        M[i.first] = count++;
        rankArr[j++] = i.first;
    }
    for(int i=0;i<q;i++) {
        if(C[i] == 'I') {
            int rank = M[arr[i]];
            // cout<<"insert "<<arr[i]<<" "<<rank<<"\n";
            update(rank, 1);
        } else if(C[i] == 'D') {
            int rank = M[arr[i]];
            update(rank, -1);
        }
        else if(C[i] == 'C') {
            int x = lower_bound(rankArr, rankArr+j, arr[i]) - rankArr;
            if(arr[i] == rankArr[x]) {
                cout<<get_count(x+1)<<"\n";
            } else {
                cout<<get_count(x+1)<<"\n";
            }
        }
        else if (C[i] == 'K'){
            int k = arr[i];
            int lo = 1;
            int hi = MAX - 1;
            int mid;
            bool mno = 0;
            int rank;
            while (lo <= hi)
            {
                mid = (lo + hi) >> 1;
                if (get_count(mid) == k && get_count(mid - 1) != k)
                {
                    mno = 1;
                    rank = mid;
                    break;
                }
                else if (get_count(mid) < k) //! 1 based indexing
                {
                    rank = mid;
                    lo = mid + 1;
                }
                else
                    hi = mid - 1;
            }
            if (!mno)
                cout<<"invalid"<<"\n";
            else
                cout<<rankArr[rank-2]<<"\n";
        }        
    }
}



















