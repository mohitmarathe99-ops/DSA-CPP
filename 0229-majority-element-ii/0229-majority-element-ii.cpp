class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    
        int candidate1 = nums[0], candidate2 = nums[0];
        int count1 = 0, count2 = 0;
        for (int value : nums) {
            if (value == candidate1) {
                count1++;
            } else if (value == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = value; 
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = value; 
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        int threshold = nums.size() / 3;
        vector<int> answer;
        int verified1 = 0;
        for (int value : nums) {
            if (value == candidate1) {
                verified1++;
            }
        }
        if (verified1 > threshold) {
            answer.push_back(candidate1);
        }

        int verified2 = 0;
        for (int value : nums) {
            if (value == candidate2) {
                verified2++;
            }
        }
        if (candidate2 != candidate1 && verified2 > threshold) {
            answer.push_back(candidate2);
        }

        return answer;
    

        
    }
};