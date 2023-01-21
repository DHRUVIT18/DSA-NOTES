class Solution {
public:
    //tle
//     bool valid(string &s,int m){
//         //find groupof 1s exactly equal to m
//         int cnt=0;
//         for(int i=0;i<s.size();i++){
//             if(s[i]=='1'){
//                 cnt++;
//             }else{
//                 if(cnt==m)return true;
//                 cnt=0;
//             }
//         }
//         if(cnt==m)return true;
//         return false;
//     }
    
//     int findLatestStep(vector<int>& arr, int m) {   
//         string s="";
//         int n=arr.size();
//         for(int i=0;i<=n;i++){
//             s+="0";
//         }
//         int latest=-1;
//       for(int i=0;i<n;i++){
//           s[arr[i]]='1';
//           if(valid(s,m)){
//               latest=i+1;
//           }
//       }
//         return latest;
//     }
     

     
     int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        queue<pair<int, int>> que;
        que.push({1, n}); // initial state
		
        int step = 0;
		// do it reversely
        for(int i = n - 1; i >= 0; --i){
			// we split the intervals in que each step
            int t = que.size();
            for(int j = 0; j < t; ++j){
                auto p = que.front();
                que.pop();
                int len = p.second - p.first + 1;
                if(len == m) return n - step; // we find the first (i.e. the lastest in terms of this question)
				
                if(len < m) continue; // we can accelerate by discarding the intervals with length less than m
				
				// split
                if(arr[i] >= p.first && arr[i] <= p.second){
					// same accelaration
                    if(arr[i] - p.first >= m) que.push({p.first, arr[i] - 1});
                    if(p.second - arr[i] >= m) que.push({arr[i] + 1, p.second});
                }else{
                    que.push(p);
                }
            }
            step++;
        }
        return -1;
    }
};