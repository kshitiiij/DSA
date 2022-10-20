class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count = 1, size = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<size;i++) {
            if(nums[i]==nums[i-1])
                count++;
            else
                count = 1;
            
            if(count>size/2)
                return nums[i];
        }
        return 1;
    }
};