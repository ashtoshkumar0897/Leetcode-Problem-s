class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int communicableServerCount = 0;
        vector <int> rowCounts(size(grid[0]), 0),
            lastServerInCol(size(grid), -1);

        // First pass to count servers in the each row and column
        for(int row = 0 ; row < size(grid);++row){
            int serverCountInRow =0;
            for( int col =0;col<size(grid[0]);++col)
            if(grid[row][col]){
                serverCountInRow++;
                rowCounts[col]++;
                lastServerInCol[row]= col;
            }
            //if there is more than one server in the row,increase the count
            if (serverCountInRow != 1)
                communicableServerCount += serverCountInRow,
                    lastServerInCol[row] = -1;
        }
        // second pass to check if servers can communicate
        for(int row = 0;row <size(grid);++row)
            communicableServerCount += lastServerInCol[row] != -1 && rowCounts[lastServerInCol[row]] > 1;
            return communicableServerCount;
        
    }
};