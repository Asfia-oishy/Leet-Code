//only functional part

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int r = matrix.size();
        int c = matrix[0].size();

        map <int,int> mpx,mpy;

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j]==0)
                {
                    mpx[i]++;
                    mpy[j]++;

                }
            }

        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(mpx.find(i)!=mpx.end() || mpy.find(j)!=mpy.end())
                {
                    matrix[i][j]=0;

                }
            }

        }


    }
};
