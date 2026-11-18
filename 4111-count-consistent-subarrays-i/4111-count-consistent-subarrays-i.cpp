class Solution {
public:
    int countConsistent(vector<int>& nums) {int n=nums.size(),count=0;
for(int i=0;i<n;i++){
    int curr_and=nums[i],curr_min=nums[i];
    for(int j=i;j<n;j++){
        curr_and&=nums[j];
        curr_min=min(curr_min,nums[j]);
        if(curr_and==curr_min)count++;
    }
}
return count;
        
    }
};