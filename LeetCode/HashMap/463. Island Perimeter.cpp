class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        //计算周长，感觉可以直接从这个元素下手，判断有几个元素相邻，挨着几个元素则单个周长减少几个
        int row = grid.size();
        int col = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < row;i++)
            for(int j = 0; j < col;j++)
            {
                //此处有元素
                if(grid[i][j] == 1)
                {
                    //判断左边,注意边界
                    if(j == 0 || j > 0 && grid[i][j-1] == 0)
                        cnt++;
                    //判断右边
                    if(j == col - 1 || j < col -1 && grid[i][j+1] == 0)
                        cnt++;
                    //判断上边
                    if(i == 0 || i > 0 && grid[i-1][j] == 0)
                        cnt++;
                    if(i == row -1 || i < row - 1 && grid[i+1][j] == 0)
                        cnt++;
                }
            }
        return cnt;
    }
};
//这个思维不错，计算所有的点*4为总周长，如果有邻居则会相连，那么减去2条边，
public class Solution {
    public int islandPerimeter(int[][] grid) {
        int islands = 0, neighbours = 0;

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1) {
                    islands++; // count islands
                    if (i < grid.length - 1 && grid[i + 1][j] == 1) neighbours++; // count down neighbours
                    if (j < grid[i].length - 1 && grid[i][j + 1] == 1) neighbours++; // count right neighbours
                }
            }
        }

        return islands * 4 - neighbours * 2;
    }
}
//dfs,有点牛批，看它隔壁的是否是0，是的话则返回1，
public class Solution {
    public int islandPerimeter(int[][] grid) {
        if (grid == null) return 0;
        for (int i = 0 ; i < grid.length ; i++){
            for (int j = 0 ; j < grid[0].length ; j++){
                if (grid[i][j] == 1) {
                    return getPerimeter(grid,i,j);
                }
            }
        }
        return 0;
    }
    
    public int getPerimeter(int[][] grid, int i, int j){
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length) {return 1;}
        if (grid[i][j] == 0) {
            return 1;
        }
        if (grid[i][j] == -1) return 0;
        
        int count = 0;
        grid[i][j] = -1;
        
        count += getPerimeter(grid, i-1, j);
        count += getPerimeter(grid, i, j-1);
        count += getPerimeter(grid, i, j+1);
        count += getPerimeter(grid, i+1, j);
        
        return count;
        
    }
}