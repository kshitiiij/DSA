class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<size;i++) {
            mp[nums[i]]++;
            if(mp[nums[i]]>size/2)
                return nums[i];
        }
        
        
        return 0;
    }
};