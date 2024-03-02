class Solution {
public:
   class Solution {
public:
    int check(vector<int> &nums,vector<int> &index,int k)
    {
        unordered_map<int,int> m1,m2;
        for(int i=0;i<=k;i++)
        {
            m1[index[i]]=i;
        }
        int count=0,ans=0;
        for(int i=0;i<=k;i++)
        {
            count++;
            if(m1[index[i]]==i)
            {
                if(count>=(nums[index[i]-1]+1))
                {
                    count=count-nums[index[i]-1]-1;
                    ans++;
                }
                else
                {
                    return false;
                }
            }
            
        }
        return ans==nums.size() ? true : false;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& index) 
    {
        int m=index.size()-1;
        int i=0,j=m,mid,ans=INT_MAX,curr;
        while(i<=j)
        {
            mid=i+(j-i)/2;
            curr=check(nums,index,mid);
            if(curr)
            {
                ans=mid;
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }
        }
        return ans!=INT_MAX ? ans+1 : -1;
    }
};
};