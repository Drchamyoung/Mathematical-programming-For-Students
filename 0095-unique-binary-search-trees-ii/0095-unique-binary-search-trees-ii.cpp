class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>> memo(n, vector<vector<TreeNode*>>(n));
        return buildAllTree(1, n, memo);
    }

    vector<TreeNode*> buildAllTree(int start, int end, vector<vector<vector<TreeNode*>>> &memo) {
        if(end < start) return {NULL};
        if(memo[start - 1][end - 1].size()) return memo[start - 1][end - 1];

        vector<TreeNode*> res;
        for(int i = start; i <= end; ++i) {
            auto left = buildAllTree(start, i - 1, memo);
            auto right = buildAllTree(i + 1, end, memo);
            
            for(auto l : left) {
                for(auto r : right) {
                    auto node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    res.push_back(node);
                }
            }
        }
        memo[start - 1][end - 1] = res;
        return res;
    }
};