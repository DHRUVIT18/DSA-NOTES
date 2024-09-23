class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int>v(26,0);
        int k=0;
        for(auto &i:word2){
            v[i-'a']++;
            k++;
        }
        int begin=0,end=0;
        vector<int>count(26,0);
        long long res=0;
        while(end<word1.size()){
           
           if(v[word1[end]-'a']>0){
                if(count[word1[end]-'a']<v[word1[end]-'a']){
                    k--;
                }
           }
           count[word1[end]-'a']++;
           
           while(k==0){
            res+=word1.size()-end;
            count[word1[begin]-'a']--;
            if(v[word1[begin]-'a']>0 and count[word1[begin]-'a']<v[word1[begin]-'a']){
                k++;
            }
            begin++;
           }
           end++;
        }
        return res;
    }
};