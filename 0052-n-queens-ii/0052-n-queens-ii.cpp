class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        vector<int> board(n, -1); 
        solveNQueensUtil(board, 0, result); 
        return result;
    }

private:
    bool isSafe(vector<int>& board, int row, int col) {
        for (int prevRow = 0; prevRow < row; ++prevRow) {
            if (board[prevRow] == col) {
                return false;
            }
        }
        for (int prevRow = 0; prevRow < row; ++prevRow) {
            if (abs(row - prevRow) == abs(col - board[prevRow])) { 
                return false;
            }
        }
        return true;
    }

    void solveNQueensUtil(vector<int>& board, int row, int& result) {
        int n = board.size();
        if (row == n) {
            result++; 
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (isSafe(board, row, col)) {
                board[row] = col;
                solveNQueensUtil(board, row + 1, result);
                board[row] = -1; 
            }
        }
    }
};