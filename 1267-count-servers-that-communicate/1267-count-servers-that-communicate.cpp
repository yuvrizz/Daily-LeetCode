class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        int ans = 0; 

        int row = grid[0].size();
        int col = grid.size();

        vector<int> row_1s;
        vector<int> col_1s;

        for(int i=0; i<col; i++){
            int count = 0;
            for(int j=0; j<row; j++){
                if(grid[i][j] == 1){
                    count ++;
                }
            }
            row_1s.push_back(count);
        }

        for(int i=0; i<row; i++){
            int count = 0;
            for(int j=0; j<col; j++){
                if(grid[j][i] == 1){
                    count ++;
                }
            }
            col_1s.push_back(count);
        }

        for(int i=0; i<col; i++){
            for(int j=0; j<row; j++){

                if(grid[i][j] == 1){
                    if(row_1s[i] > 1 || col_1s[j] > 1){
                        ans++;
                    }
                }

            }
        }

        return ans;
    }
};