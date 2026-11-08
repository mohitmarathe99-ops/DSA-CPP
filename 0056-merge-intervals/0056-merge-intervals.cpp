class Solution {
public:
static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      vector<vector<int>> merged;
      if(intervals.size() == 0) return {};
      sort(intervals.begin(), intervals.end(),cmp);
      merged.push_back(intervals[0]);
      for (int i = 1; i < intervals.size(); i++) {
          if (merged.back()[1] >= intervals[i][0]) {
              merged.back()[1] = max(merged.back()[1], intervals[i][1]);
          } else {
              merged.push_back(intervals[i]);
          }
    }
    return merged;
    }
};