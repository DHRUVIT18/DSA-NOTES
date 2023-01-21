class Solution {
public:
    bool canBeValid(string s, string locked) {
        int balance=0;
       int n=s.size();
        if(n%2)return false;
        for(int i=0;i<n;i++){
            if(locked[i]=='0' or s[i]=='('){
                balance++;
            }else {
                balance--;
            }
            
            if(balance<0)return false;
        }
        balance=0;
         for(int i=n-1;i>=0;i--){
            if(locked[i]=='0' or s[i]==')'){
                balance++;
            }else {
                balance--;
            }
            
            if(balance<0)return false;
        }
        return true;
    }
};