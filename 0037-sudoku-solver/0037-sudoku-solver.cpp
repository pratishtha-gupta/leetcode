class Solution {
public:
    bool isSafe(vector<vector<char>>&board,int row,int col,char digit){
    //vertical
    for(int i=0;i<=8;i++){
        if(board[i][col]==digit){
            return false;
        }
    }
    //horizontal
    for(int j=0;j<=8;j++){
        if(board[row][j]==digit){
            return false;
        }
    }
    //3x3 grid
    int startrow=(row/3)*3;
    int startcol=(col/3)*3;
    for(int i=startrow;i<=startrow+2;i++){
        for(int j=startcol;j<=startcol+2;j++){
            if(board[i][j]==digit){
                return false;
            }
        }
        
    }
    return true;
}

    bool helper(vector<vector<char>>&board,int row,int col){
        if(row==9){
            return true;
        }
        int nextrow=row;
        int nextcol=col+1;
        if(col+1==9){
            nextrow=row+1;
            nextcol=0;
        }
        if(board[row][col]!='.'){
            return helper(board,nextrow,nextcol);
        }
        for(char digit='1';digit<='9';digit++){
            if(isSafe(board,row,col,digit)){
                board[row][col]=digit;
                if(helper(board,nextrow,nextcol)){
                    return true;
                }
                board[row][col]='.';
            }
        
        }
         return false;
    }
        
    
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};