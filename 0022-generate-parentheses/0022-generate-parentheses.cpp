class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        backtrack(n,res,curr,0,0);
        return res;
    }
private:
    void backtrack(int n, vector<string>& res, string& curr, int open, int closed){
        if(curr.size() == (n*2)){
            res.push_back(curr);
            return;
        }
        for(int i = 0; i<2; i++){
            if (i == 0 && open < n){
                curr.push_back('(');
                backtrack(n, res, curr, open + 1, closed);
                curr.pop_back();
            }
            if (i == 1 && closed < open){
                curr.push_back(')');
                backtrack(n,res,curr,open,closed + 1);
                curr.pop_back();
            }
        }
    }
};