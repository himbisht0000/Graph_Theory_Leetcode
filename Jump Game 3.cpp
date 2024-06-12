class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        bool visited[arr.size()];
        memset(visited,false,sizeof(bool) * arr.size());

        stack<int> st;
        st.push(start);
        visited[start] = true;

        while(!st.empty())
        {
            int current , left ,right;
            current = st.top();
            if(arr[current] == 0)
            {
                return true;
            }
            st.pop();
            
            left = current - arr[current];
            right = current + arr[current];

            if(left >=0 && visited[left] == false)
            {
                if(arr[left] == 0)
                {
                    return true;
                }
                st.push(left);
                visited[left] = true;
            }
            if(right < arr.size() && visited[right] == false)
            {
                if(arr[right] == 0)
                {
                    return true;
                }

                st.push(right);
                visited[right] = true;
            }

        }

        return false;
    }
};
