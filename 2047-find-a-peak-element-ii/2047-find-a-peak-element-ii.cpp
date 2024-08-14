class Solution {
public:
    int maxElement(vector<vector<int>> &mat, int n, int m, int col)
    {
        int maxVal = -1;
        int ind = -1;

        for(int i = 0; i < n; i++)
        {
            if(mat[i][col] > maxVal)
            {
                maxVal = mat[i][col];
                ind = i;
            }
        }
        return ind;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m - 1;

        while(low <= high)
        {
            int midCol = low + (high - low) / 2;
            int row = maxElement(mat, n, m, midCol);
            int left = midCol - 1 >= 0 ? mat[row][midCol - 1] : -1;
            int right = midCol + 1 < m ? mat[row][midCol + 1] : -1;

            if(mat[row][midCol] > left && mat[row][midCol] > right)
                return {row, midCol};
            
            else if(mat[row][midCol] < left)
                high = midCol - 1;
            
            else
                low = midCol + 1;
        }
        return {-1, -1};
    }
};
