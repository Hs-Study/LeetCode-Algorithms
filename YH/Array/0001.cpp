/* 
 * Name:    Two Sum
 * Tag:     Array, Hash Table 
 * Level:   Easy
 */

#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
       
        map<int, int> mii;
        for(int i=0; i<nums.size(); i++) {
            int k = target - nums[i];
            if(mii.find(k) != mii.end()) {
                ans.push_back(mii[k]);
                ans.push_back(i);
                break;
            }
            mii[nums[i]] = i;
        }
        
        return ans;
    }
};
