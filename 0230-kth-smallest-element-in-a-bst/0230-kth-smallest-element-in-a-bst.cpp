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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;   // To keep track of the number of elements visited
        int result = -1; // To store the k-th smallest element
        inorderTraversal(root, k, count, result);
        return result;
    }

private:
    void inorderTraversal(TreeNode* node, int k, int& count, int& result) {
        if (!node) return; // Base case: if the node is null, return

        // Traverse the left subtree
        inorderTraversal(node->left, k, count, result);

        // Visit the current node
        count++;
        if (count == k) {
            result = node->val; // If the current element is the k-th, store it
            return;             // Early exit once we find the k-th element
        }

        // Traverse the right subtree
        inorderTraversal(node->right, k, count, result);
    }
};
