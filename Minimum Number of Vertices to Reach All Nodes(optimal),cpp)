class Solution {
public:
	vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& v) {
		
        //output answer 
        vector<int> output;
        
        //reverse adjcency matrix
        vector<int> adj_list[n];
		
        //create reverse adjacency matrix
        for(int i = 0 ; i < v.size() ; i++)
        {
            adj_list[v[i][1]].push_back(v[i][0]);
        }

        //node which do not have any nodes in reverse adj_list are the source node
        //which can traverse all the other nodes in DAG
        for(int i = 0 ; i < n; i++)
        {
            if(adj_list[i].size() == 0)
            {
                output.push_back(i);
            }
        }


        return output; 
	}
};
