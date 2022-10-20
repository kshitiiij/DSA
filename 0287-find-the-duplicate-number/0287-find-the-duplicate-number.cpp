class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int tor=nums[0],hare=nums[0];
        tor = nums[tor];
        hare = nums[nums[hare]];
        while(tor!=hare) {
            tor = nums[tor];
            hare = nums[nums[hare]];
        }

        tor =nums[0];
        while(tor!=hare) {
            tor = nums[tor];
            hare = nums[hare];
        }
        
        return hare;
        
    }
};