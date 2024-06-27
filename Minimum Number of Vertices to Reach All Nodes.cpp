class Solution {
public:

    void bfs( int source, vector<int> *adj_list , int *node_set , int *visited)
    {
        queue<int> Q;
        // push source to queue
        Q.push(source);

        // mark source as visited
        visited[source] = 1;
        //marks source node to be included in output set
        node_set[source] = 1;


        //run the loop till queue has elements
        while(!Q.empty())
        {
            int current;
            //get the front node
            current = Q.front();
            //pop the current node
            Q.pop();

            // visit all the neighbout of current node
            for(int i = 0 ; i < adj_list[current].size() ; i++)
            {
                // if neighbour is not visited then only push it to queue
                if( visited[adj_list[current][i]] == 0 ) 
                {
                    Q.push(adj_list[current][i]);
                    visited[adj_list[current][i]] = 1;
                }
                else
                {
                    // if source node can be visit this neighbour node 
                    // then we do not need to include this neighbout node in output set
                    // unmark the set 
                    node_set[adj_list[current][i]] = 0 ;
                    
                }
            }

        }

    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        //node_set is used to mark node which will be included in output
        int node_set[n];

        //visited array to track the nodes already visited
        int visited[n];
        vector<int> output;
        memset(node_set , 0, sizeof(node_set));
        memset(visited , 0, sizeof(visited));


        vector<int> adj_list[n];

        //create adjacency list
        for(int i = 0 ; i< edges.size() ; i ++)
        {
            adj_list[edges[i][0]].push_back(edges[i][1]);
        }

        //apply bfs to nodes which are not visted yet
        for(int i = 0 ;i < n ; i++)
        {

            if(visited[i] == 0)
            {
                bfs(i , adj_list , node_set ,  visited);
            }
        }

        // node which are set to one will only be included in minimal answer.
        for(int i = 0 ; i < n ; i++ )
        {
            if(node_set[i])
            {
                output.push_back(i);
            }
        }
        return output;
    }
};
