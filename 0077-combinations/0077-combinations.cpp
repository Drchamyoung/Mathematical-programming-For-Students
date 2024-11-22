class Solution {
public:
    int k;
    int n;

    vector<vector<int>> combine(int n, int k) {
        this->k = k;
        this->n = n;
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(curr, 1, ans);
        return ans;
    }

    void backtrack(vector<int>& curr, int firstNum, vector<vector<int>>& ans) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        int need = k - curr.size();
        int remain = n - firstNum + 1;
        int available = remain - need;

        for (int num = firstNum; num <= firstNum + available; num++) {
            curr.push_back(num);
            backtrack(curr, num + 1, ans);
            curr.pop_back();
        }
    }
};