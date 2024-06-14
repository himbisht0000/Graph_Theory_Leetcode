/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void bfs(TreeNode* source,int target, vector<int>& answer , map<TreeNode* , TreeNode*>& parent)
    {
        bool visited[502];
        memset(visited,false,sizeof(bool) * 502);

        if(source == NULL)
        return;
    
        queue<pair<TreeNode*,int>> Q;
        Q.push(make_pair(source,0));
        visited[source->val] = true;

        while(!Q.empty())
        {
            TreeNode* current;
            int dist;
            current = Q.front().first;
            dist = Q.front().second;
            Q.pop();
            if(dist == target)
            {
                
                answer.push_back(current->val);
                continue;
            }
            
            if(current->left != NULL && visited[current->left->val] == false)
            {
                Q.push(make_pair(current->left , dist+1));
                visited[current->left->val] = true;
            }

            if(current->right != NULL && visited[current->right->val] == false)
            {
                Q.push(make_pair(current->right , dist + 1));
                visited[current->right->val] = true;
            }

            if(parent[current] != NULL && visited[parent[current]->val] == false)
            {
                Q.push(make_pair(parent[current] , dist + 1));
                visited[parent[current]->val] = true;
            }
        }
    }

    void traverse_tree(TreeNode* root , TreeNode* previous ,map<TreeNode* , TreeNode*>& parent)
    {
        if(root == NULL)
        return;

        parent[root] = previous;
        if(root->left != NULL)
        {
            traverse_tree(root->left,root , parent);
        }

        if(root->right != NULL)
        {
            traverse_tree(root->right,root, parent);
        }
        return;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode* , TreeNode*> parent;
        vector<int> answer;
        //convert directed grah to undirected graph
        traverse_tree(root,NULL,parent);
        bfs(target,k,answer,parent);

        return answer;
    }
};
