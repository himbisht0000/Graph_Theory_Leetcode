class Solution {
public:
    typedef pair<int,int> pairType;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        bool visited[n+1];
        int weight[n+1];
        vector<pairType>adj_list[n+1];
        int time_taken = -1;
        // <weight , node> , min heap is created based on first element
        priority_queue<pairType , vector<pairType> , greater<pairType> > pq;

        for(int i = 0; i <= n ; i++)
        {
            visited[i] = false;
            weight[i] = 200;
        }
        
        //create adjacency list
        for(int i = 0 ; i < times.size() ; i++)
        {
            int x , y, dist;
            x = times[i][0];
            y = times[i][1];
            dist = times[i][2];
            adj_list[x].push_back( make_pair(y , dist) );
        }

        pq.push(make_pair(0 , k));
        visited[k] = true;

        weight[k] = 0;
        while(!pq.empty())
        {
            int node , node_weight;
            node = pq.top().second;
            node_weight = pq.top().first;
            pq.pop();
            visited[node] = true;
            //visit all the adjacents node
            for(int i = 0; i < adj_list[node].size(); i++)
            {
                int x, d, new_weight;
                x = adj_list[node][i].first;
                d = adj_list[node][i].second;
                if(visited[x] == false)
                {
                    new_weight = weight[node] + d;
                    if(new_weight < weight[x])
                    {
                        pq.push(make_pair(new_weight,x));
                        weight[x] = new_weight;
                    }
                }

            }
        }

        // find the max time to reach any node
        for(int i = 1; i <= n ;i++)
        {
           
            time_taken = max(time_taken , weight[i]);
            //if a node is not visited then return -1
            if(weight[i] == 200)
            return -1;
        }
        return time_taken;
    }
};
