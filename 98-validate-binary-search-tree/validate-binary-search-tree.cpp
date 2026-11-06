class Solution {
    TreeNode* prev = nullptr;                      // last node visited in inorder
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;                    // empty tree has no violations
        if (!isValidBST(root->left)) return false; // 1. left subtree
        if (prev && root->val <= prev->val)        // 2. this node must exceed the previous one
            return false;
        prev = root;
        return isValidBST(root->right);            // 3. right subtree decides the rest
    }
};