/ CPP program to construct binary  
// tree from given array in level 
// order fashion Tree Node 
#include <bits/stdc++.h> 
using namespace std; 
  
/* A binary tree node has data,  
pointer to left child and a 
pointer to right child */
struct Node 
{ 
    int data; 
    Node* left, * right; 
}; 
  
/* Helper function that allocates a 
new node */
Node* newNode(int data) 
{ 
    Node* node = (Node*)malloc(sizeof(Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
  
// Function to insert nodes in level order 
Node* insertLevelOrder(int arr[], Node* root, 
                       int i, int n) 
{ 
    // Base case for recursion 
    if (i < n) 
    { 
        Node* temp = newNode(arr[i]); 
        root = temp; 
  
        // insert left child 
        root->left = insertLevelOrder(arr, 
                   root->left, 2 * i + 1, n); 
  
        // insert right child 
        root->right = insertLevelOrder(arr, 
                  root->right, 2 * i + 2, n); 
    } 
    return root; 
} 
  
// Function to print tree nodes in 
// InOrder fashion 
void inOrder(Node* root) 
{ 
    if (root != NULL) 
    { 
        inOrder(root->left); 
        cout << root->data <<" "; 
        inOrder(root->right); 
    } 
} 
int maxPathSum(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    if(root->left == NULL && root->right == NULL) return root->val;
    return root->val + maxPathSum(root->left) + maxPathSum(root->right);
}
// Driver program to test above function 
int main() 
{ 
    int arr[] = { -10,9,20,null,null,15,7 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    Node* root = insertLevelOrder(arr, root, 0, n); 
    inOrder(root); 
    //cout << maxPathSum(root);


    return 0;
} 
  
// This code is contributed by Chhavi 
Java