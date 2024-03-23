    class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        long long sum = 0;
        int n = nums.size(), m= queries.size();
        set<pair<int,int>> st;
        for(int i=0; i<n; i++){
            st.insert({nums[i], i});
            sum+=nums[i];
        }
        vector<long long> ans;
        for(int i=0; i<m; i++){
            int index = queries[i][0];
            int total = queries[i][1];
            int num = nums[index];
            if(st.count({num, index})){
                sum-=num;
                st.erase({num, index});
            }
            while(total-- && !st.empty()){
                auto p = *st.begin();
                int x = p.first;
                if(st.count(p)){
                    sum-= x;
                    st.erase(p);
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};