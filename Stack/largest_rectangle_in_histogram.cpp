int largestRectangleArea(vector<int>& A) {
        int n=A.size();
        vector<int>ps(n,0);
        vector<int>ns(n,n-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() and A[st.top()]>=A[i]){
                st.pop();
            }
            if(!st.empty()){
                ps[i]=st.top()+1;
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and A[st.top()]>=A[i]){
                st.pop();
            }
            if(!st.empty()){
                ns[i]=st.top()-1;
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int area=(ns[i]-ps[i]+1)*A[i];
            ans=max(ans,area);
        }
        return ans;
    }