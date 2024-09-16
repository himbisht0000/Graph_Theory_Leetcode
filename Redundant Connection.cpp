class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // create adj matrix
        // number of nodes in a tree = edge + 1
        vector<int> adj_list[edges.size() + 1];
        int degree[edges.size() + 1];
        int i;
        
        memset(degree, 0 , sizeof(int) * ( edges.size() + 1 ) );

        for(int i = 0 ; i <edges.size() ; i++)
        {
            int x,y;
            x = edges[i][0];
            y = edges[i][1];
            adj_list[x].push_back(y);
            adj_list[y].push_back(x);


        }
        

        //now we find the degree of each node
        for(int i = 0 ; i <edges.size() ; i++)
        {
            int x,y;
            x = edges[i][0];
            y = edges[i][1];

            degree[x]++;
            degree[y]++;

        }

        //put all the nodes with degree 1 to queue
        // we want to remove all the nodes which are not part of cycle
        queue<int> q;
        for(int i = 1 ; i <= edges.size() ; i++ )
        {
           // cout<<" i -> "<<i<<" degree = "<<degree[i]<<endl;
            if(degree[i] == 1)
            {
                q.push(i);
            }
        }


        // remove all the edges which are not in cycle
        while(!q.empty())
        {
            int node;
            node = q.front();
            q.pop();
            for(int i = 0 ; i < adj_list[node].size(); i++)
            {
                degree[adj_list[node][i]]--;
                //cout<<"node ->"<<node<<" neighbour -> "<<adj_list[node][i]<< " size() "<< adj_list[node].size() <<endl;
                if(degree[adj_list[node][i]] == 1)
                {
                    q.push(adj_list[node][i]);
                }
            }
        }

        // now we only have a cycle and in a cycle degree of both the node in a edge should be 2
        for( i = edges.size()-1; i >= 0 ; i--)
        {
            int degree_1,degree_2;
        
            degree_1 = degree[edges[i][0]];
            degree_2 = degree[edges[i][1]];

            if(degree_1 == 2 && degree_2 == 2 )
            {
                break;
            }
        }

        return edges[i];
    }
};
