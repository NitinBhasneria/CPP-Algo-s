/*
Search Engine
Send Feedback
Let us see how search engines work. Consider the following simple auto complete feature. When you type some characters in the text bar, the engine automatically gives best matching options among it's database. Your job is simple. Given an incomplete search text, output the best search result.
Each entry in engine's database has a priority factor attached to it. We consider a result / search suggestion best if it has maximum weight and completes the given incomplete search query. For each query in the input, print the maximum weight of the string in the database, that completes the given incomplete search string. In case no such string exists, print -1.
INPUT
First line contains two integers n and q, which represent number of database entries and number of search queries need to be completed. Next n lines contain a string s and an integer weight, which are the database entry and it's corresponding priority.

Next q lines follow, each line having a string t, which needs to be completed.
OUTPUT
Output q lines, each line containing the maximum possible weight of the match for given query, else -1, in case no valid result is obtained.
CONSTRAINTS
1 ≤ n, weight, len(s), len(t) ≤ 10^6
1 ≤ q ≤ 10^5
total length of all strings in database entries ≤ 10^6
total length of all query strings ≤ 10^6
SAMPLE INPUT
2 1
hackerearth 10
hackerrank 9
hacker
SAMPLE OUTPUT
10
*/

#include<bits/stdc++.h>
using namespace std;

class trieNode {
    public:
        int weight;
        trieNode* node[26];
    
    trieNode() {
        weight = 0;
        for(int i=0;i<26;i++){
            node[i] = NULL;
        }
    }
};

void insert(trieNode* root, string str, int weight) {   
    trieNode* curr = root;
    for(int i=0;i<str.length();i++) {
        int temp = str[i]-'a';
        if(root->node[temp]){
            root = root->node[temp];
        } else {
            root->node[temp] = new trieNode();
            root = root->node[temp];
        }
        if((root->weight) < weight) 
            root->weight = weight;
    }
}

int query(trieNode* root, string str) {
    trieNode* curr = root;
    int value = -1;
    for(int i=0;i<str.length();i++) {
        int temp = str[i] - 'a';
        if(root->node[temp]) {
            root = root->node[temp];
            value = root->weight;
        } else {
            value = -1;
            break;
        }
    }
    return value;
}

void searchEngine (string* str, int n, int q, int* weight, string* search) {
    trieNode* root = new trieNode();
    
    for(int i=0;i<n;i++) {
        insert(root, str[i], weight[i]);
    }

    for(int i=0;i<q;i++) {
        cout<<query(root, search[i])<<"\n";
    }
}

int main() {
    int n, q;
    cin>>n>>q;
    string given[n], query[q];
    int weight[n];
    for(int i=0;i<n;i++) {
        cin>>given[i]>>weight[i];
    }
    for(int i=0;i<q;i++) {
        cin>>query[i];
    }
    searchEngine(given, n, q, weight, query);
    return 0;
}















