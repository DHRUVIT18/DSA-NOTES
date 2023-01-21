class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        int sign=1;
        int ans=0;
        long long currNo=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]-'0'>=0 and s[i]-'0'<=9){
                currNo=s[i]-'0';
                while(i+1<n and s[i+1]-'0'>=0 and s[i+1]-'0'<=9 ){
                    currNo=currNo*10+s[i+1]-'0';
                    i++;
                }
                currNo=currNo*sign;
                ans+=currNo;
                sign=1;
            }else if(s[i]=='+'){
                sign=1;
            }else if(s[i]=='-'){
                sign=-1;
            }else if(s[i]=='('){
                st.push(ans);
                st.push(sign);
                ans=0;
                sign=1;
            }else if(s[i]==')'){
                int prevsign=st.top();
                st.pop();
                ans=ans*prevsign;
                int prevans=st.top();
                st.pop();
                ans+=prevans;
            }
        }
        return ans;
    }
};