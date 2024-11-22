class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return validate(root, prev);
    }

    bool validate(TreeNode* node, TreeNode* &prev)
    {
        if(node == nullptr) return true;
        if(!validate(node->left, prev)) return false;
        if(prev != nullptr && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev); 
    }
};