/**
 *   Definition for binary tree
 *   struct TreeNode {
 *       int val;
 *       TreeNode *left;
 *       TreeNode *right;
 *       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *   };
 */

class Solution {
    public:
    int maxDepth(TreeNode *root) {
        return root? max( maxDepth(root->left)+1, maxDepth(root->right)+1 ) : 0;
        }
};
