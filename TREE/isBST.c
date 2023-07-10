
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
    int find_max(TreeNode* root)
    {
        if (root == nullptr)
            return INT_MIN;
        
        int result = root->val;
        int left = find_max(root->left);
        int right = find_max(root->right);

        if (left > result)
            result = left;
        if (right > result)
            result = right;
        return result;
    }
    int find_min(TreeNode* root)
    {
        if (root == nullptr)
            return INT_MAX;

        int result = root->val;
        int left = find_min(root->left);
        int right = find_min(root->right);

        if (left < result)
            result = left;
        if (right < result)
            result = right;
        return result;
    }
    bool isValidBST(TreeNode* root) {
    if (root == nullptr)
    {
        return true;
    }
    if (root->left != nullptr && find_max(root->left) >= root->val) {
        return false;
    }
    if (root->right != nullptr && find_min(root->right) <= root->val) {
        return false;
    }
    // check recursively
    if (!isValidBST(root->left) || !isValidBST(root->right))
        return false;
    return true;
    }
};
