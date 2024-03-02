class Solution {
public:
   const long long INFNEG = LLONG_MIN;
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {

        const int n = (int) bottomLeft.size();


        long long answer = INFNEG;
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){

                long long mxLeft = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long mnRight = min(topRight[i][0], topRight[j][0]);
                long long mnUp = min(topRight[i][1], topRight[j][1]);
                long long mxDown = max(bottomLeft[i][1], bottomLeft[j][1]);

                if (!(mxLeft < mnRight && mnUp > mxDown)) continue;

                long long area = min(mnUp - mxDown, mnRight - mxLeft);

                answer = max(answer, area);
            }
        }

        answer = max(answer, 0LL);

        return answer*answer;
    }
};