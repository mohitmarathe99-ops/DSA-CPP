class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, long long> prefixCount;
        prefixCount[0] = 1;
        long long prefixSum = 0;
        long long count = 0;
        for (int value : nums) {
            prefixSum += value;
            long long neededSum = prefixSum - k; 
            if (prefixCount.find(neededSum) != prefixCount.end()) {
                count += prefixCount[neededSum];
            }
            prefixCount[prefixSum]++;
        }

        return count;
    }
        
};