class Solution {
public:
    void bfs(int i , int j, vector<vector<char>>& grid)
    {
        queue<pair<int,int>> Q;
        int X[4] = {-1,0,1,0};
        int Y[4] = {0,1,0,-1};
        Q.push(make_pair(i,j));
        grid[i][j] = '2';
        while(!Q.empty())
        {
            int x,y;
            x = Q.front().first;
            y = Q.front().second;
            Q.pop();

            for(int i = 0 ; i<4 ; i++)
            {
                int x_axis,y_axis;
                x_axis = x + X[i];
                y_axis = y + Y[i];

                if(x_axis < 0 || x_axis >= grid.size() || y_axis < 0 || 
                   y_axis >= grid[0].size() )
                {
                    continue;
                }
                else if(grid[x_axis][y_axis] == '1')
                {
                    Q.push(make_pair(x_axis , y_axis));
                    grid[x_axis][y_axis] = '2';
                }
            }

        }
    }
    int numIslands(vector<vector<char>>& grid){
        int count = 0;
        for(int i = 0 ; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    bfs(i,j,grid);
                    cout<<"ok"<<endl;
                    count++;
                }
            }
        }

        return count;
    }
};
