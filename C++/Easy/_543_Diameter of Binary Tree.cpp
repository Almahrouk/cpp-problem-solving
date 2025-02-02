/*
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1

*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // Define a helper function to calculate the diameter recursively
        int res = 0;
        diameter(root, res);
        return res;
    }

private:
    int diameter(TreeNode* curr, int& res){
        // Base case: if the current node is null, return 0
        if (!curr) return 0;

        // Recursively calculate the diameter of left and right subtrees
        int left = diameter(curr->left, res);
        int right = diameter(curr->right, res);

        // Update the maximum diameter encountered so far
        res = std::max(res, left + right);

        // Return the depth of the current node
        return std::max(left, right) + 1;
    }
};