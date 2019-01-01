# Review



## 0001. Two Sum

Tag) Array, Hash_Table

Sol) taget - nums[i] 의 값이 map 에 저장이 되어 있으면, 기존에 저장되어 있는 값의 인덱스와 현재 인덱스를 벡터에 담은 후 리턴. 인덱스는 기존에 저장된 값이 순서상 앞서므로 기존 값의 인덱스 또한 앞선다.



Wrong Answer)

```c++
#include <algorithm>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            int k = target - nums[i];
            int pos = lower_bound(nums.begin(), nums.end(), k) - nums.begin();
            if(pos == nums.size() || pos == i) continue;
            if(nums[pos] == k) {
                ans.push_back(i);
                ans.push_back(pos);
                break;
            }
        }
        return ans;
    }
};
```

> Input: [3,2,4] 6
>
> Output: [0,2]
>
> Expected: [1,2]
>
> 정렬을 하면서 인덱스가 바뀌어 오답을 저장하게 되었다.

