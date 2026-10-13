class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = (long long)m * k;
        if (val > n) return -1;
        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            int count = 0;
            int noOfB = 0;
            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= mid) {
                    count++;
                } else {
                    noOfB += (count / k);
                    count = 0;
                }
            }
            noOfB += (count / k);
            
            if (noOfB >= m) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};