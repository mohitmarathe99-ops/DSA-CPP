class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> arrival;
        vector<int> departure;
        for (const auto& interval : intervals) {
            arrival.push_back(interval[0]);
            departure.push_back(interval[1]);
        }
        sort(arrival.begin(), arrival.end());
        sort(departure.begin(), departure.end());
        int i = 0, j = 0, count = 0, maxCount = 0;
        while (i < arrival.size() && j < departure.size()) {
            if (arrival[i] <= departure[j]) {
                count++;
                i++;
            } else {
                count--;
                j++;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};