class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> output;
               
        if(prerequisites.size() == 0)
        {
            //if their is no pre-requite we simple return all the courses
            for(int i = 0 ; i < numCourses ; i++)
            output.push_back(i);
            return output;
        }    
        
        bool visited[numCourses];
        int  inorder[numCourses];

        memset(visited,false,sizeof(bool) * numCourses);
        memset(inorder,0,sizeof(int) * numCourses);

        vector<int> adj_list[numCourses];

        //create adjacency list and inorder array
        for(int i = 0 ; i < prerequisites.size() ; i++)
        {
            //x-->y
            int x , y;
            x = prerequisites[i][1];
            y = prerequisites[i][0];
            adj_list[x].push_back(y);
            inorder[y]++;
        }

        queue<int> q;

        for(int i = 0 ; i< numCourses ; i++)
        {
            if(inorder[i] == 0 && visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
                while(!q.empty())
                {
                    int node; 
                    //order in which node is removed is the 
                    //topogogical order to choose courses 
                    node = q.front();
                    q.pop();
                    output.push_back(node);

                    for(int i = 0 ; i < adj_list[node].size() ; i++)
                    {
                        //decrease the inorder
                        inorder[adj_list[node][i]]--;
                        //if inorder become zer then push it to queue
                        if(inorder[adj_list[node][i]] == 0)
                        {
                            q.push(adj_list[node][i]);
                            visited[adj_list[node][i]] = true;
                        }
                    }

                }
            }
        }

        if(output.size() != numCourses)
        {
            output.clear();
            return output;
        }

        return output;



    }
};
