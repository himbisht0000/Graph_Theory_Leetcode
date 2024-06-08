class Solution {
public:

    void bfs(vector<vector<int>> red_edge, vector<vector<int>> blue_edge, int color, vector<int>& answer)
    {   
        int current,level, i, flag;
        queue<vector<int>> Q;

        int red_visited[blue_edge.size()];
        memset(red_visited, 0 , sizeof(int) * blue_edge.size());

        int blue_visited[blue_edge.size()];
        memset(blue_visited, 0 , sizeof(int) * blue_edge.size());
       
        Q.push({0,0,color});
        red_visited[0] = 1;
        blue_visited[0] = 1;

        while(!Q.empty())
        {
            current = Q.front()[0];
            level = Q.front()[1];
            color = Q.front()[2];

            Q.pop();
            flag = 0;
            if(color == 0)
            {
                 cout<<"RED color current --->"<<current<<endl;
            }
            else
            {
                cout<<"Blue color current --->"<<current<<endl;
            }
            //RED color
            if(color == 0)
            {
                for( i = 0; i < red_edge[current].size();i++ )
                {
                    if(red_visited[red_edge[current][i]] == 1)
                    continue;

                    flag = 1;
                    cout<<"neighbour "<<red_edge[current][i]<<" ";
                    Q.push({red_edge[current][i], level + 1 , 1 });

                    red_visited[red_edge[current][i]] = 1;
                    if(answer[red_edge[current][i]] == -1)
                    {
                        answer[red_edge[current][i]] = level + 1;
                    }
                    else
                    {
                        answer[red_edge[current][i]] = min(answer[red_edge[current][i]] , level + 1);
                    }
                }
                cout<<endl;

            }
            else //BLUE
            {
                for( i = 0; i < blue_edge[current].size();i++ )
                {
                    if(blue_visited[blue_edge[current][i]] == 1)
                    continue;
                    flag = 1;
                    cout<<"neighbour "<<blue_edge[current][i]<<" ";
                    Q.push({blue_edge[current][i], level + 1,0});
                    blue_visited[blue_edge[current][i]] = 1;
                    if(answer[blue_edge[current][i]] == -1)
                    {
                        answer[blue_edge[current][i]] = level + 1;
                    }
                    else
                    {
                        answer[blue_edge[current][i]] = min(answer[blue_edge[current][i]] , level + 1);
                    }
                }

                cout<<endl;
                
            }

        }

    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        int src,dest;
        vector<int> answer(n);
        fill(answer.begin(), answer.end() , -1);
        answer[0] = 0;
        vector<vector<int>> red_edge(n);
        vector<vector<int>> blue_edge(n);
        //0 --> RED 
        //1 --> BLUE
        
        for(int i = 0 ; i < redEdges.size(); i++)
        {
            src = redEdges[i][0];
            dest = redEdges[i][1];
            red_edge[src].push_back(dest);
        }

        for(int j = 0 ; j < blueEdges.size(); j++)
        {
            src = blueEdges[j][0];
            dest = blueEdges[j][1];
            blue_edge[src].push_back(dest);
        }
        cout<<" RED BFS called "<<endl;
        bfs(red_edge,blue_edge,0,answer);
        cout<<" BLUE BFS called "<<endl;
        bfs(red_edge,blue_edge,1,answer);

        return answer;
    }
};
