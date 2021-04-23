/*
Help Me Pradyumana!
Send Feedback
Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his auto - correct more times than the auto - correct corrects him. Pradyumn is thinking to make his own app for mobile which will restrict auto - correct feature, instead it will provide auto - completion. Whenever Pradyumn types factorial, auto - correct changes it to fact. Pradyumn's App will show options such as fact, factorial, factory. Now, he can chose from any of these options. As Pradyumn is busy with his front - end work of his App. He asks you to help him. He said "You will be given set of words(words may repeat too but counted as one only). Now, as user starts the app, he will make queries(in lowercase letters only). So, you have to print all the words of dictionary which have the prefix same as given by user as input. And if no such words are available, add this word to your dictionary." As you know, Pradyumn want this app to be as smart as him :P So, implement a program for him such that he can release it on Fun Store.
INPUT CONSTRAINTS
1≤N≤30000
sum(len(string[i]))≤2∗10^5
1≤Q≤10^3
INPUT FORMAT
Single integer N which denotes the size of words which are input as dictionary
N lines of input, where each line is a string of consisting lowercase letter
Single integer Q which denotes the number of queries.
Q number of lines describing the query string on each line given by user
OUTPUT FORMAT
If auto - completions exists, output all of them in lexicographical order else output "No suggestions" without quotes

NOTE: All strings are lowercase
SAMPLE INPUT
3
fact
factorial
factory
2
fact
pradyumn
SAMPLE OUTPUT
fact
factorial
factory
No suggestions
*/
#include<bits/stdc++.h>
using namespace std;

class trieNode {
    public:
        char words;
        trieNode* node[26];
        bool leafNode;
        
    trieNode() {
        for(int i=0;i<26;i++) {
            node[i] = NULL;
        }
        leafNode = false;
    }
};

void insert(trieNode* root, string str) {
    trieNode* curr = root;
    for(int i=0;i<str.length();i++) {
        int temp = str[i] - 'a';
        if(curr->node[temp]) {
            curr = curr->node[temp];
            curr->words = str[i];
        } else {
            curr->node[temp] = new trieNode();
            curr = curr->node[temp];
        }
    }
    curr->leafNode = true;
}

// In this function we keep adding the value until eh leaf ends( or leafNode == true) and at leafs end we print the value
void helper(trieNode *current, string prefix)
{
    if(current -> leafNode) {
        cout<<prefix<<endl;
    }
    for (int i = 0; i < 26; i++)
    {
        trieNode *temp = current;
        if (temp->node[i])
        {
            char suffix = (int)i + (int)'a';
            helper(current->node[i], prefix + suffix);
        }
    }
}
void query(string str, trieNode* root) {
    trieNode* curr = root;
    for(int i=0;i<str.length();i++) {
        int temp = str[i] - 'a';
        if(root->node[temp]){
            root = root->node[temp];
        } else {
            insert(curr, str);
            cout<<"No suggestions\n";
            return;
        }
    }
    helper(root, str);
}

void helpMe(int q, string* str, trieNode* root) {
    for(int i=0;i<q;i++) {
        query(str[i], root);
    }
}

int main() {
    int n;
    cin>>n;
    string str[n];
    trieNode* root = new trieNode();
    for(int i=0;i<n;i++) {
        cin>>str[i];
        insert(root, str[i]);
    }
    int q;
    cin>>q;
    string query[q];
    for(int i=0;i<q;i++) {
        cin>>query[i];
    }
    helpMe(q, query, root);
    return 0;
}




