class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i;
        for(i=0;i<k;i++) {
            if(i>nums.size()-1)
                return false;
            cout<<nums[i]<<" ";
            mp[nums[i]]++;
            if(mp[nums[i]]==2) {
                cout<<nums[i]<<" ";
                return true;
            }
        }
        
        for(i=k;i<nums.size();i++) {
            mp[nums[i]]++;
            if(mp[nums[i]]==2) {
                cout<<nums[i]<<" ";
                return true;
            }
            
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0)
                mp.erase(nums[i-k]);
            
        }
        
        return false;
    }
};