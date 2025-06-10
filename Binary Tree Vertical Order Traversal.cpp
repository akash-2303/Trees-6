/**
 Problem: Binary Tree Vertical Order Traversal
 Time Complexity: O(NlogN), where N is the number of nodes in the binary tree.
 Space Complexity: O(N), where N is the number of nodes in the binary tree.
 Did this code run on LeetCode? Yes

 Approach: 
  1. Use a queue to perform a level order traversal of the binary tree.
  2. Maintain a map to store nodes in each vertical column.
  3. For each node, record its column index and add it to the corresponding list in the map.
  4. Finally, extract the lists from the map and return them as a vector of vectors.
 */
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
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        //column node to list of nodes in that column
        map<int, vector<int>> columnTable;
        //node and column index
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while(!q.empty()) {
            auto [node, col] = q.front();
            q.pop();
            columnTable[col].push_back(node -> val);

            if(node -> left != nullptr){
                q.push({node -> left, col - 1});
            }
            if(node -> right != nullptr){
                q.push({node -> right, col + 1});
            }
        }
        vector<vector<int>> result;
        for(auto& [col, values] : columnTable) {
            result.push_back(values);
        }
        return result;
    }
};