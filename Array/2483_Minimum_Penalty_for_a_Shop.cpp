class Solution {
public:
    int bestClosingTime(string customers) {
        int count = 0;
        
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y'){
                count++;
            }
        }
        
        //base case
        if(count==0){
            return 0;
        }
        if(count==customers.size()){
            return customers.size();
        }
        int ans = count;
        int res = 0;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y'){
                count--;
            }
            else{
                count++;
            }
            if(count<ans){
                ans = count;
                res = i+1;
            }
        }
        
        return res;
    }
};