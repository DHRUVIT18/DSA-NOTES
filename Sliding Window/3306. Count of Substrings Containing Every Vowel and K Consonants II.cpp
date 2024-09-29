class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return solve(word,k-1)-solve(word,k);
    }
    long long solve(string &w,int k){
        unordered_map<char,int>c;
        int left=0;
        long long res=0;
        int consonants=0;
        for(int right=0;right<w.size();++right){
            if(w[right]=='a' || w[right]=='e' || w[right]=='i' || w[right]=='o' || w[right]=='u' ){
                c[w[right]]++;
            }else{
                consonants++;
            }
            while(c.size()==5 and consonants>k){
                  if(w[left]=='a' || w[left]=='e' || w[left]=='i' || w[left]=='o' || w[left]=='u' ){
                    c[w[left]]--;
                    if(c[w[left]]==0)c.erase(w[left]);
                  }else{
                    consonants--;
                  }
                  left++;
            }
            res += left;
        }
    return res;
    }
};