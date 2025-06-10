// Problem: Range Sum of BST
// Time Complexity: O(N), where N is the number of nodes in the binary tree.
// Space Complexity: O(H), where H is the height of the binary tree.
// Did this code run on LeetCode? Yes

// Approach:
// 1. Use a recursive helper function to traverse the binary search tree (BST).
// 2. Check if the current node's value is within the range [low, high].
// 3. If it is, add the value to the sum.
// 4. If the current node's value is greater than or equal to low, recursively check the left subtree.
// 5. If the current node's value is less than or equal to high, recursively check the right subtree.

#include <vector>
#include <queue>
#include <map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int sum = 0; 
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return helper(root, low, high);
    }

private: 
    int helper(TreeNode* root, int low, int high){
        // base case
        if(root == nullptr){
            return 0;
        }
        
        if(root -> val >= low && root -> val <= high){
            sum += root -> val;
        }

        if(root -> val >= low){
            helper(root -> left, low, high);
        }

        if(root -> val <= high){
            helper(root -> right, low, high);
        }
        return sum;
    }
};