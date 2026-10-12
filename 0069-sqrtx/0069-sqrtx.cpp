class Solution {
public:
    int mySqrt(int x) {
        //for GH
        if (x == 0) return 0;
        
        long long low = 1, high = x;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return high;
    }
};