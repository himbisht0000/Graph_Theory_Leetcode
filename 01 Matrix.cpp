class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<pair<int,int>> zero;
        vector<pair<int,int>> other;
        vector<vector<int>> answer;
        answer = mat;
        int i,j;
        // store cells where zero is stored and where other number are stored
        for(int i = 0; i < mat.size(); i++)
        {
            for(int j = 0 ; j < mat[i].size(); j++)
            {
                if(mat[i][j] == 0 )
                {
                    zero.push_back(make_pair(i,j));
                }
                else
                {
                    other.push_back(make_pair(i,j));
                }
            }
        }

        //find the distance between other numbers and all other zeros one by one and 
        //store minimum value
        for(i = 0; i < other.size(); i++)
        {
            int mini_distance, current_dist;
            mini_distance = INT_MAX;
            for(j = 0 ; j < zero.size(); j++)
            {
                current_dist = abs(other[i].first - zero[j].first) + abs(other[i].second - zero[j].second);
                mini_distance = min(mini_distance , current_dist);
            }
            
            answer[other[i].first][other[i].second] = mini_distance;
        }

        return answer;
    }

};
