class Solution {
    bool search(int index,int i,int j, int m,int n,vector<vector<char>>& board,string word)
    {
        if(index==word.size())
        return true;
        if(i<0||j<0||i==m||j==n||board[i][j]!=word[index]||board[i][j]=='.')
        return false;
        char c = board[i][j];
        board[i][j]='.';
        bool top = search(index+1,i-1,j,m,n,board,word);
        bool down = search(index+1,i+1,j,m,n,board,word);
        bool right = search(index+1,i,j+1,m,n,board,word);
        bool left = search(index+1,i,j-1,m,n,board,word);
        board[i][j]=c;
        return top||down||right||left;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int i,j,index=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
               if(board[i][j]==word[index])
               {
                  if (search(index,i,j,m,n,board,word))
                  {
                     return true;
                  }
               }
            }
        }
        return false;
    }
};