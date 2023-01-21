class Solution {
public:
   vector<int>v;
    
    Solution(vector<int>& w) {
        //calculate probability by prefix sum range refer to techdose video
        v.push_back(w[0]);
        for(int i=1;i<w.size();i++){
            v.push_back(v.back()+w[i]);
        }
    }
    
    int pickIndex() {
       int r=rand()%(v.back());
        int ans=upper_bound(v.begin(),v.end(),r)-v.begin();
        return ans;
    }
};