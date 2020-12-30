#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <numeric>


typedef long long ll;
const unsigned int uinfinity = std::numeric_limits<unsigned int>::max();
const int infinity = std::numeric_limits<int>::max();
using namespace std;


int minDepth(Node *root) 
{ 
    // Corner case. Should never be hit unless the code is  
    // called on root = NULL 
    if (root == NULL) 
        return 0; 
  
    // Base case : Leaf Node. This accounts for height = 1. 
    if (root->left == NULL && root->right == NULL) 
    return 1; 
  
    // If left subtree is NULL, recur for right subtree 
    if (!root->left) 
    return minDepth(root->right) + 1; 
  
    // If right subtree is NULL, recur for left subtree 
    if (!root->right) 
    return minDepth(root->left) + 1; 
  
    return min(minDepth(root->left), minDepth(root->right)) + 1; 
} 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //optimize code

    
}

/**
 * BFS find the distance to all other nodes from a node. the shorted distance cannot be the answer
 *      because it may not be a leaf node.
 * DFS finds all possible paths from a node. the path's end is one path's last 'leaf' node.
 *      But it assumes it has a adj[n];
 *          it creates a work to create a adj list
 * 
 * Solution
 *      find the shortest height. In binary tree structure, a path's end is determined by the lead nodes.
 *      minimum height is the shortest; 2nd min height i sthe 2nd shorest and etc...
 *      what makes a height a minimum? the node next to the root node can be the minimum but it may not have leafs
 *          Therefore, a min height is the height or distance between the node and the shortest path node
 *          if we visit all possible leafs and remember their path from the root, we know the shortest one   
 * 
 *      recursively visit all leafs (sounds like DFS)
 *          recursing the binary tree visits all nodes including all leafs.
 *          the recursing does not stop in the middle of node, therefore if we calculate the height
 *          the height it gives is the height from the root to a leaf.
 * 
 *      I thought that i had to check whether im in the leaf and remeber the height only i am at a leaf is complex
 *      But simply recursion must have to check the base (leaf case) it checks it anyway
 *      And simply remembering the min value by constantly comparing the ongoing min height is enough
 *      Because it will not stop recursing in the middle there is no way it will remmber the middle node height
 *      Because recursion wants to keep going untill it sees a leaf from the root throgh the middle node to their leaf node.
 *      
 * */