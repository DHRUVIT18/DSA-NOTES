
//segment tree template;
//all the questions will be done using this template;



class NumArray {
public:
    vector<int>seg;
    int n;
    NumArray(vector<int>& nums) {
        if(nums.size()>0){
            n=nums.size();
            seg.resize(4*n,0);
            buildtree(nums,0,0,n-1);
        }
    }
    void buildtree(vector<int>&nums,int pos,int left,int right){
        if(left==right){
            seg[pos]=nums[left];
            return;
        }
        int mid=(left+right)>>1;
        buildtree(nums,2*pos+1,left,mid);
        buildtree(nums,2*pos+2,mid+1,right);
          seg[pos]= seg[pos*2+1]+seg[pos*2+2];
    }
    
    
    
    void update(int index, int val) {
        // if(n==0)return 0;
        return updateutil(0,0,n-1,index,val);
    }
    void updateutil(int pos,int left,int right,int index,int val){
        //no overlap
        if(index<left or index>right)return ;
        //total overlap
        if(left==right){
            if(left==index)
                seg[pos]=val;
            return;
        }
        //partial overlap
        int mid=(left+right)>>1;
       updateutil(2*pos+1,left,mid,index,val);
       updateutil(2*pos+2,mid+1,right,index,val);    
         seg[pos]= seg[pos*2+1]+seg[pos*2+2];
    }
    
    
    
    int sumRange(int left, int right) {
       
        return rangeutil(left,right,0,n-1,0);
    }
    int rangeutil(int qleft,int qright,int left,int right,int pos){
        if(qleft<=left and qright>=right){
            //total overlap
            return seg[pos];
        }
        if(qleft>right or qright<left){
            //no overlap
            return 0;
        }
        int mid=(left+right)>>1;
        return rangeutil(qleft,qright,left,mid,pos*2+1)+
                rangeutil(qleft,qright,mid+1,right,pos*2+2);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */