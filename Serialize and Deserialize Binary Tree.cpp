// Problem: Serialize and Deserialize Binary Tree
// Time Complexity: O(N), where N is the number of nodes in the binary tree.
// Space Complexity: O(N), where N is the number of nodes in the binary tree.
// Did this code run on LeetCode? Yes

// Approach:
// 1. Use a queue to perform a level order traversal of the binary tree.
// 2. For each node, append its value to the result string, and push its left and right children into the queue.
// 3. If a node is null, append "null" to the result string.
// 4. For deserialization, split the string by commas and reconstruct the tree using a queue to manage nodes.
// 5. Create a new TreeNode for each non-null value and link it to its parent node's left or right child as appropriate.
// 6. Return the root of the reconstructed tree.

#include <string>
#include <queue>
#include <sstream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return "";
        }
        string result;
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr != nullptr){
                result += to_string(curr -> val) + ",";
                q.push(curr -> left);
                q.push(curr -> right);
            } else{
                result += "null,";
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()){
            return nullptr;
        }
        stringstream ss(data);
        string val;
        getline(ss, val, ',');

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(getline(ss, val, ',')){
                if(val != "null"){
                    curr -> left = new TreeNode(stoi(val));
                    q.push(curr -> left);
                }
            }

            if(getline(ss, val, ',')){
                if(val != "null"){
                    curr -> right = new TreeNode(stoi(val));
                    q.push(curr -> right);
                }
            }
        }
        return root;
    }
};