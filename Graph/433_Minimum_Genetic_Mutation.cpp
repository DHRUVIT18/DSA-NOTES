class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int res=0;
        vector<char>dir={'A','C','G','T'};
        unordered_set<string>st(bank.begin(),bank.end());
        if(st.find(end)==st.end())return -1;
        queue<string>q;
        q.push(start);
        while(!q.empty()){
            int sz=q.size();
            for(int k=0;k<sz;k++){
                auto curr=q.front();q.pop();
                if(curr==end)return res;
                st.erase(curr);
                for(int i=0;i<8;i++){
                    char c=curr[i];
                    for(int j=0;j<4;j++){
                        curr[i]=dir[j];
                        if(st.find(curr)!=st.end()){
                            q.push(curr);
                        }
                    }
                    curr[i]=c;
                }
            }
            res++;
        }
       
      return -1;
    }
};