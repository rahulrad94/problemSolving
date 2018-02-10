/*  Binary Tree Max path sum
 *  Time: O(n^2)
 *
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxVal;
    int maxPathSum(TreeNode* root){
        maxVal = INT_MIN;
        calc(root);
        return maxVal;
    }

    int calc(TreeNode* root) {
        if(!root) return 0;

        int leftSum = max(0, calc(root->left));
        int rightSum = max(0,calc(root->right));

        maxVal = max(maxVal, root->val+leftSum+rightSum);

        return root->val + max(leftSum, rightSum);
    }
};
