class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        sort(nums.begin(),nums.end());
        deque<int>dq;
        for(auto i:nums){
            dq.push_back(i);
        }

        int count=0;
        while(dq.size()>1){
            int a=dq.front();
            dq.pop_front();
            
            int b=dq.back();
            dq.pop_back();

            int c=a%b;
            int d=b%a;
            
            if(c!=0 and d!=0){
               int e=min(c,d);
               dq.push_front(e);
            }else if(c!=0 and d==0){
                dq.push_front(c);
            }else if(c==0 and d!=0){
                dq.push_front(d);
            }else{
                count++;
            }
        }
        return dq.size()+count;
    }
};