class Solution {
public:
    void life(vector<vector<int>> board,vector<vector<int>>& next,int i,int j,int r,int c)
    {
       int src  = board[i][j];

         if(src==0)
            {
                int cnt = 0;

            if(i-1>=0)
                    cnt+=board[i-1][j];
                if(j-1>=0)
                    cnt+=board[i][j-1];
                if(i+1<r)
                    cnt+=board[i+1][j];
                if(j+1<c)
                    cnt+=board[i][j+1];
                if(i-1>=0 && j-1>=0)
                    cnt+=board[i-1][j-1];
                if(i+1<r && j+1<c)
                    cnt+=board[i+1][j+1];
                if(i-1>=0 && j+1<c)
                    cnt+=board[i-1][j+1];
                if(i+1<r && j-1>=0)
                    cnt+=board[i+1][j-1];
                
                if(cnt==3) next[i][j]=1;
            }
            else
            {
                int cnt = 0;

                if(i-1>=0)
                    cnt+=board[i-1][j];
                if(j-1>=0)
                    cnt+=board[i][j-1];
                if(i+1<r)
                    cnt+=board[i+1][j];
                if(j+1<c)
                    cnt+=board[i][j+1];
                if(i-1>=0 && j-1>=0)
                    cnt+=board[i-1][j-1];
                if(i+1<r && j+1<c)
                    cnt+=board[i+1][j+1];
                if(i-1>=0 && j+1<c)
                    cnt+=board[i-1][j+1];
                if(i+1<r && j-1>=0)
                    cnt+=board[i+1][j-1];


                if(cnt<2 || cnt>3)
                next[i][j]=0;
                else
                next[i][j]=1;
            }
    }
    
    void gameOfLife(vector<vector<int>>& board) {

        int r = board.size();
        int c = board[0].size();


        vector<vector<int>> next(r,vector<int> (c,0));

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                life(board,next,i,j,r,c);
            }
        }

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                board[i][j]=next[i][j];
            }
        }


        
    }
};