class Solution {
public:
    int X[4]={0,-1,0,1};// left up right down
    int Y[4]={-1,0,1,0};
    
    //calculate edit distance bwteen all the nodes in island1 and island2
    int calculate_path(vector<pair<int,int>> island_1, vector<pair<int,int>> island_2)
    {
        int min_distance = INT_MAX;
        for(int i = 0 ; i < island_1.size() ; i++)
        {
            for(int j = 0 ; j < island_2.size() ; j++)
            {
                min_distance = min(min_distance, abs(island_1[i].first - island_2[j].first) +
                abs(island_1[i].second - island_2[j].second) );
            }
        }
        
        return min_distance - 1;
    }

    void dfs(int i, int j, vector<vector<int>>& grid, vector<pair<int,int>> &island)
    {
        stack<pair<int,int>> st;
        int x_length,y_length;
        int current_x,current_y,temp_x,temp_y;
        st.push(make_pair(i,j));
        grid[i][j] = 2;
        x_length = grid.size();
        y_length = grid[0].size();
        island.push_back(make_pair(i,j));
        while(!st.empty())
        {
            current_x = st.top().first;
            current_y = st.top().second;
            //cout<<"source -->"<<current_x<<"-"<<current_y<<endl;
            st.pop();
            for(int i = 0; i < 4; i++)
            {
                temp_x = current_x + X[i];
                temp_y = current_y + Y[i];

                if(temp_x < 0 )
                {
                    temp_x = 0;
                }
                else if(temp_x >= x_length)
                {
                    temp_x = x_length - 1;
                }

                if(temp_y < 0 )
                {
                    temp_y = 0;
                }
                else if(temp_y >= y_length)
                {
                    temp_y = y_length - 1;
                }

               

                if( grid[temp_x][temp_y] == 1 )
                {   
                    grid[temp_x][temp_y] = 2;
                    st.push(make_pair(temp_x,temp_y));
                    //store node of each island in respective vector
                    island.push_back(make_pair(temp_x , temp_y));
                }

            }
            
        

        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        vector<pair<int,int>> island_1, island_2;
        //first dfs to find the first island
        int i,j;
        int flag = 0;
        for( i = 0; i < grid.size() ; i++)
        {
            for( j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(i,j,grid,island_1); // store island1 nodes in island_1
                    flag = 1;
                    break;
                }
            }
            if(flag)
            break;
        }
        flag = 0;
        //second dfs to find second island
        for( i = 0; i < grid.size() ; i++)
        {
            for( j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(i,j,grid,island_2);// store island2 nodes in island_2
                    flag = 1;
                    break;
                }
            }
            if(flag)
            break;
        }

       


        cout<<"first island \n";
        for(int i = 0 ; i < island_1.size() ; i++)
        {
            cout<<island_1[i].first<<" "<<island_1[i].second<<endl;
        }

        cout<<"second island \n";
        for(int i = 0 ; i < island_2.size() ; i++)
        {
            cout<<island_2[i].first<<" "<<island_2[i].second<<endl;
        }

        // calculate minimum edit distance
        return calculate_path(island_1,island_2);
    }
};
