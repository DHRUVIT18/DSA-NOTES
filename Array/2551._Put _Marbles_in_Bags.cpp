class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        if(k==1 or n==k)return 0;
        
        vector<int>candidate;
        
        for(int i=0;i<n-1;i++){
            candidate.push_back(weights[i]+weights[i+1]);
        }
        sort(candidate.begin(),candidate.end());
        long long mins = 0, maxs = 0;
       //select k-1 minimum / maximum partitions
        for(int i=0;i<k-1;i++){
            mins+=candidate[i];
          
        }
        k--;
        int i=candidate.size()-1;
        while(k){
            maxs+=candidate[i];
            cout<<candidate[i]<<" ";
            i--;
            k--;
        }
        
        return maxs-mins;
    }
};
// 4 6 8