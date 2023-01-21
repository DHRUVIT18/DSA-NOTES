
//304
//calculate prefix matrix first;
//and then calculate for a region


class NumMatrix {
public:
    vector<vector<int>>a;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        a.resize(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                a[i][j]=matrix[i-1][j-1]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            }
        }
        
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        // for(auto it:a){
        //     for(auto i:it){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        

        int res=a[r1][c1]+a[r2+1][c2+1]-a[r2+1][c1]-a[r1][c2+1];
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */