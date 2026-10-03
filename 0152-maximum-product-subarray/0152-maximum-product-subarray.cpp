class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        long long currentMax = nums[0];
        long long currentMin = nums[0];
        long long maxProduct = nums[0];

        for (int index = 1; index < n; index++) {
            long long currentValue = nums[index];
            long long previousMax = currentMax;
            long long previousMin = currentMin;
            currentMax = max({
                currentValue,
                previousMax * currentValue,
                previousMin * currentValue
            });

            currentMin = min({
                currentValue,
                previousMax * currentValue,
                previousMin * currentValue
            });
            if (currentMax > maxProduct) {
                maxProduct = currentMax;
            }
        }

        return maxProduct;
        }
        
    };