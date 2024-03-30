class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(auto i:tasks){
            freq[i-'A']++;
        }
        sort(freq.begin(),freq.end());
        int chunks = freq[25]-1;
        int idlespots = chunks*n;
        
        for(int i=24;i>=0;i--){
            idlespots -= min(chunks,freq[i]);
        }
        
        return idlespots<0?tasks.size():idlespots+tasks.size();
    }
};