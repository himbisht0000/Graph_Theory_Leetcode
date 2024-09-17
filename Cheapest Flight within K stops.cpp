class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector< pair<int,int> > adj_list[n];
        int weight[n];
        for(int i = 0 ; i < n ; i++)
        {
            weight[i] = INT_MAX;
        }
        //memset(weight , INT_MAX, sizeof(int) * n);

        //adjacency list
        for(int i = 0 ; i < flights.size() ; i++)
        {
            int x,y,d;
            x = flights[i][0];
            y = flights[i][1];
            d = flights[i][2];

            adj_list[x].push_back(make_pair(y,d));
        }

        //apply bfs 
        queue<pair<int,int>> q; //< node , weight>
        q.push(make_pair(src , 0));

        while(!q.empty() && k >=0)
        {
            int queue_size = q.size();
            // process all th current element in queue
            while(queue_size--)
            {
                int node , dist;
                node = q.front().first;
                dist = q.front().second;
                q.pop();

                for(int i = 0 ; i < adj_list[node].size();i++)
                {
                   int x , d;
                    x = adj_list[node][i].first;
                    d = adj_list[node][i].second;
                    //relax the neighbouring edges
                    if( ( dist + d ) < weight[x])
                    {
                       q.push(make_pair(x , dist + d));
                       weight[x] = dist + d ;
                   }
                }
            }
            // we have processed all the current stop nodes, decrease the stop count now
            k--;
        }


        if(weight[dst] == INT_MAX)
        return -1;

        return weight[dst];



    }
};
