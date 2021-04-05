#include<bits/stdc++.h>
using namespace std;

class tree {
    public:
        int data;
        tree* left;
        tree* right;

    // tree(int val){
    //     data = val;
    //     left = NULL;
    //     right = NULL;
    // }
};

tree* createNode(int element){
    tree* root = new tree();
    root->data = element;
    root->left = root->right =  NULL;
}

void insertNode (tree* root, int element) { //level - order approach
    if(root==NULL){
        root = createNode(element);
        return ;
    }
    queue<tree*> q;
    q.push(root);
    while(!q.empty()){
        tree* temp = q.front();
        q.pop();

        if(temp->left!=NULL){
            q.push(temp->left);
        }
        else
        {
            temp->left = createNode(element);
            return ;
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
        else {
            temp->right = createNode(element);
            return ;
        }
        
    }
}

void postOrder (tree* root){
    if(root==NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void inOrder (tree* root){
    if(root==NULL) {
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder (tree* root){
    if(root==NULL) {
        return;
    }
    cout<<root->data<<" ";

    preOrder(root->left);
    preOrder(root->right);
}

void delete_deepest(tree* root, 
                 tree* d_node) 
{ 
    queue<tree*> q; 
    q.push(root); 
  
    // Do level order traversal until last node 
    tree* temp = new tree(); 
    while (!q.empty()) { 
        temp = q.front(); 
        q.pop(); 
        if (temp == d_node) { 
            temp = NULL; 
            delete (d_node); 
            return; 
        } 
        if (temp->right) { 
            if (temp->right == d_node) { 
                temp->right = NULL; 
                delete (d_node); 
                return; 
            } 
            else
                q.push(temp->right); 
        } 
  
        if (temp->left) { 
            if (temp->left == d_node) { 
                temp->left = NULL; 
                delete (d_node); 
                return; 
            } 
            else
                q.push(temp->left); 
        } 
    } 
} 

tree* deletion (tree* root, int ele) {
    if(root == NULL) {
        return root;
    }
    if(root->left == NULL && root->right == NULL){
        if(root->data == ele)
            return NULL;
        else 
            return root;
    }
    queue<tree*> q;
    q.push(root);
    tree* temp = new tree();
    tree* key_node = new tree();
    tree*  node = new tree();
    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp->data==ele)
            key_node = temp;
        if(temp->left != NULL){
            node = temp;
            q.push(temp->left);}
        if(temp->right){
            node = temp;
            q.push(temp->right);}
    }
    cout<<endl<<node->data<<endl;
    if(key_node!=NULL){
        int x = temp->data;
        if(node->right){
            node->right = NULL;
            delete(node->right);
        }
        else {
            tree* tt = node -> left;
            node->left = NULL;
            delete(tt);
        }
        // delete_deepest(root,temp);
        key_node->data = x;
    }

    /*
    we can use the delete_deepest or we can track the parent node of
    deepest node and set its right or left value to be NULL.
    */
    return root;
}

int main() {
    tree* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    // // root->left->right = new tree(5);
    root->right->left = createNode(4);
    root->right->right = createNode(5);

    // preOrder(root);
    // cout<<endl;
    // postOrder(root);
    // cout<<endl;
    inOrder(root);

    insertNode(root, 6);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    root = deletion(root, 3);
    inOrder(root);
    return 0;
}