class Solution {
public:
    int distance(string s1, string s2)
    {
        int i,j;
        int diff = 0;
        for(int i = 0 ; i < s1.size(); i++)
        {
            if(s1[i]!=s2[i])
            {
                diff++;
            }
        }

        return diff;

    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        int flag = 0;
        int destination = bank.size();
        int min_ans = INT_MAX;
        bool visited[bank.size() + 1];
        memset(visited,false,sizeof(bool) * (bank.size() + 1));
        //first check if endGene is present in bank or not
        for(int i = 0 ; i < bank.size(); i++)
        {
            if(endGene.compare(bank[i]) == 0)
            {
                flag = 1;
                destination = i+1;
            }
        }

        if(flag == 0)
        {
            return -1;
        }

        //create a adjacency list for 0th node
        //thier will be not edge from neighbours to node
        //their will be only and only if diff between two string is of 1 character
        vector<vector<int>> adj_list(bank.size() + 1);
        for(int i = 0 ; i < bank.size() ; i++)
        {
            if(distance( startGene , bank[i] ) == 1)
            {
                adj_list[0].push_back(i+1);
            }
        }

        //create a adjacency list for all the string in bank
        //each string represents a node
        // we assume node value of index 0 is 1 and so on
        // this is done beacuse 0 node represents the startGene string
        for(int i = 0 ; i < bank.size() ; i++)
        {
            for(int j = 0 ; j < bank.size() ; j++)
            {
                if(i == j)
                continue;

                if(distance(bank[i] , bank[j]) == 1)
                {
                    adj_list[i+1].push_back(j+1);
                }

            }
        }

        //Now run BFS to find the destination node
        queue<pair<int,int>> Q; // node and level
        Q.push(make_pair(0,0));
        visited[0]= true;
        while(!Q.empty())
        {
            int current, level;
            current = Q.front().first;
            level = Q.front().second;
            Q.pop();
            for(int i = 0 ; i < adj_list[current].size();  i++)
            {
                if(visited[adj_list[current][i]] == true)
                continue;
                Q.push(make_pair(adj_list[current][i], level + 1));
                
                if(adj_list[current][i] == destination)
                min_ans = min(min_ans, level + 1);

                visited[adj_list[current][i]] = true;
            }

        }

        if(min_ans == INT_MAX)
        {
            return -1;
        }

        return min_ans;
    }
};
