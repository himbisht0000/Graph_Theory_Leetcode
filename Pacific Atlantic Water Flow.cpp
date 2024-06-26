class Solution {
public:
    
    int X[4] = {-1,0,1,0};
    int Y[4] = {0,1,0,-1};
    void bfs(vector<vector<int>>& heights , vector<vector<int>>& visited , int i, int j, int ocean)
    {
        //Queue for BFS
        queue<pair<int,int>> q;

        // Push the first source cell from matrix in queue
        q.push(make_pair(i,j));
        visited[i][j] = 1;

        while(!q.empty())
        {
            int x , y ;
            x = q.front().first;
            y = q.front().second;
            q.pop();

            // for a source check in four different direction
            for(int h = 0; h < 4; h++)
            {
                int temp_x,temp_y;
                temp_x = x + X[h];
                temp_y = y + Y[h];
                // we only go to new cell if height of new cell is equal to or same as current cell
                if( temp_x >=0 && temp_x < heights.size() && temp_y >=0 && temp_y < heights[0].size() && 
                    (heights[temp_x][temp_y] >= heights[x][y] )
                    && visited[temp_x][temp_y] == 0)
                {
                    q.push(make_pair(temp_x,temp_y));
                    visited[temp_x][temp_y] = 1;
                }
            }
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        //run dfs/dfs from nodes connected to pacific ocean
        // marks all the notes visited as 1
        //run dfs or bfs from nodes connected to atlantic ocean
        // add 1 to nodes visited
        // traverse the visited array if any node has value 2 
        // then we include it in our answer

        // visited matrix
        vector<vector<int>> pacific_visited( heights.size() , vector<int> (heights[0].size()));  
        vector<vector<int>> atlantic_visited( heights.size() , vector<int> (heights[0].size()));  


        //output vector
        vector<vector<int>> output;

        
        //fill(pacific_visited.begin(), pacific_visited.end(), 0);
        //fill(atlantic_visited.begin(), atlantic_visited.end(),0);

        //first row
        for(int i = 0 ; i < heights[0].size() ; i++)
        {
            if(pacific_visited[0][i] == 0)
            bfs(heights , pacific_visited , 0 , i , 1);
        }
        
        
        //first column
        for(int i = 1 ; i < heights.size() ; i++)
        {
            if(pacific_visited[i][0] == 0)
            bfs(heights , pacific_visited , i , 0 , 1);
        }

        
        //last row
        for(int i = 0 ; i < heights[0].size() ; i++)
        {
            if(atlantic_visited[heights.size()-1][i] == 0)
            bfs(heights , atlantic_visited , heights.size()-1 , i , 1);
        }
       
        //last column
        for(int i = 0 ; i < heights.size() ; i++)
        {
            if(atlantic_visited[i][heights[0].size()-1 ] == 0)
            bfs(heights , atlantic_visited , i ,  heights[0].size()-1 , 1);
        }

        
        // traverse both the visited vector and if in both the vector is visited for a value of i and j
        // that means water can go to both the oceans from that cell
        for(int i = 0 ; i < heights.size() ; i++)
        {
            for(int j = 0; j < heights[0].size() ; j++)
            {
                if(pacific_visited[i][j] == 1 && atlantic_visited[i][j] == 1)
                {
                    vector <int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    output.push_back(temp);
                }
            }
        }

        return output;

    }
};
