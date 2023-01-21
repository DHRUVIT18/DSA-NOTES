class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int M=1e9+7;
        vector<int>diff(n);
        int sum=0;
        for(int i=0;i<n;i++){
            sum=(sum+abs(nums1[i]-nums2[i]))%M;
            diff[i]=abs(nums1[i]-nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        vector<int>a(n);
        for(int i=0;i<n;i++){
            int j=lower_bound(nums1.begin(),nums1.end(),nums2[i])-nums1.begin();
            if(j!=0 and j!=n){
                a[i]=min(abs(nums1[j]-nums2[i]),abs(nums1[j-1]-nums2[i]));
            }else if(j==0){
                a[i]=abs(nums1[j]-nums2[i]);
            }else if(j==n){
                a[i]=abs(nums1[j-1]-nums2[i]);
            }
        }
        int maxchange=0;
        for(int i=0;i<n;i++){
            maxchange=max(maxchange,diff[i]-a[i]);
        }
        return (M+sum-maxchange)%M;
    }
};