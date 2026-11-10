class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftsum = 0;
        int maxsum = 0;
        for(int i = 0; i < k;i++){
            leftsum = leftsum + cardPoints[i];
            maxsum = leftsum;
        }
        int rightindex = n-1;
        int rightsum = 0;
        for(int j = k - 1 ; j>=0 ; j--){
             leftsum = leftsum - cardPoints[j];
             rightsum += cardPoints[rightindex];
             rightindex--;
              maxsum = max(maxsum,leftsum+rightsum);
        }
        return maxsum;
    }
};