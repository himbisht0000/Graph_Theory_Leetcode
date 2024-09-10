class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int degree[n];
        bool visited[n];
        int node;
        int largest_path_len = 0;
        vector<int> adj_list[n];
        vector<int> output;


        // if their is no edge in tree , then each node has minimum height
        if(edges.size() == 0)
        {
            for(int i = 0 ; i < n; i++)
            {
                output.push_back(i);
            }
            return output;
        }

        //reset arrays
        memset(degree , 0 , sizeof(int) * n);
        memset(visited , false , sizeof(bool) * n);
        
        //store indegree + outdegree
        for(int i = 0 ; i < edges.size() ; i++)
        {
            degree[ edges[i][0] ]++;
            degree[ edges[i][1] ]++;
        }

        //adjacency list
        for(int i = 0 ; i < edges.size() ; i++)
        {
            int x = edges[i][0] ;
            int y = edges[i][1] ;

            adj_list[x].push_back(y);
            adj_list[y].push_back(x);

        }

        queue<int> q;
        // push all the node with degree 1 in queue
        for(int i = 0 ; i < n ; i++ )
        {
            if(degree[i] == 1)
            {
                q.push(i);
                output.push_back(i);
                visited[i] = true;
            }
        }

        // while q is not empty keep on removing leaf node from the tree until we reach middle of tree
        // middle of tree will have either one or two nodes only
        while(!q.empty())
        {
            int size = q.size();
            // clear the ouput as these nodes are not middle of tree
            output.clear();
            while(size--)
            {
                int node;
                node = q.front();
                q.pop();
                // push these node as these nodes might be middle of tree
                output.push_back(node);
                for(int i = 0 ; i < adj_list[node].size() ; i++)
                {
                    degree[ adj_list[node][i] ]--;
                    
                    // node has become leaf node
                    if(degree[ adj_list[node][i] ] == 1 && visited[ adj_list[node][i] ] == false)
                    {
                        q.push(adj_list[node][i]);
                        visited[ adj_list[node][i] ] = true;
                    }

                }

            }

        }

        return output;

    }
};
