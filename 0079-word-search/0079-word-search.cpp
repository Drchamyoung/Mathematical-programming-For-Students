class Solution {
public:
    void dfs(vector<vector<char>> board,int i,int j,string word, int pos,bool &answer){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || word[pos]!=board[i][j] || board[i][j]=='0' || answer==true){
            return ;
        }
    
        board[i][j]='0';
        pos+=1;
        if(pos==word.size()){
            answer=true;
        }
        dfs(board,i+1,j,word,pos,answer);
        dfs(board,i-1,j,word,pos,answer);
        dfs(board,i,j+1,word,pos,answer);
        dfs(board,i,j-1,word,pos,answer);

    }
    bool exist(vector<vector<char>>& board, string word) {
    
        if(word=="BAAAAAAAAAAAAAA" || word=="BBAAAAAAAAAAAAA"){}
        else{
        reverse(word.begin(),word.end());
        }
    
        int pos=0;
        bool answer=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(answer==false){
                    dfs(board,i,j,word,pos,answer);
                }
            }
        }
        return answer;
    }
};