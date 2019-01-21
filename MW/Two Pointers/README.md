# Review

## 0003. Longest Substring Without Repeating Characters

Tag) Hash Table, Two Pointers, String<p>

Sol) ch 가 현재 선택된 부분 문자열에 이미 포함된 문자인지 확인해야 하고, 포함되어 있으면 start 를 먼저 들어 온 문자 뒤까지 옮겨야 한다.<p>
- ch 가 이미 포함된 문자 여부는 해시테이블을 사용한다.<br>
- start 를 갱신하는 것은 해시테이블에 문자의 인덱스를 계속 갱신하는 것으로 간단하게 처리할 수 있다.

```c++
int lengthOfLongestSubstring(string s) {
    int alpha[128];
    memset(alpha, -1, sizeof(int)*128);
    int start = 0;
    int max_len = 0;

    int i = 0;
    while (i < s.length()) {
        char ch = s[i];

//문자가 탐색된 적 있고,
//문자의 최근 인덱스가 부분 문자열 범위에 포함되면
        if (alpha[ch] >= start) {
            max_len = max(max_len, i-start);
            start = alpha[ch]+1;
        }
        alpha[ch]=i;
        i++;
    }

    return max(max_len, i-start);
}
```

Test Case)<p>
Input
> "abcabcbb"<br>
> "bbbbb"<br>
> "pwwkew"<br>
> "dvdf"<br>
> " "<br>
> ""<p>

Output
> 3<br>
> 1<br>
> 3<br>
> 3<br>
> 1<br>
> 0<p>

## 0011. Container With Most Water

Tag) Array, Two Pointers<p>

Sol)
- 완전탐색 O(n^2)<br>
- Two Pointers O(n): left, right 포인터를 두고, 높이가 낮은 쪽의 포인터를 변경하면서 최대 넓이를 찾는다.<p>

```c++
class Solution {
    
    int get_area(vector<int>& height, int start, int end) {
        int a=height[start],b=height[end];
        return ((a<b)?a:b)*(end-start);
    }
    
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int l=0,r=height.size()-1;
                
        while (l<r) {
            int area = get_area(height,l,r);
            if(max<area)max=area;
            
            if(height[l]<height[r]) l++;
            else r--;
        }
        
        return max;
    }
};
```

## 0015. 3Sum

Tag) Array, Two Pointers<p>

Sol)
- 완전탐색 O(n^3)<br>
- 이분탐색 O(n^2 logn) : 완전탐색에서 마지막 값을 구할 때 이분탐색을 사용한다. 중복은 map으로 처리가능<br>
- Two Pointers O(n^2 ???): 첫번째 값을 선택한 다음 0이 되는 두 쌍을 Two Pointers로 찾는다. 중복을 제거하기 위해 i, left, right 인덱스에 대해 현재 인덱스와 다음 인덱스에 있는 수가 같은지 비교한다.<p>

```c++
int nsize = nums.size();
vector<vector<int>> ans;
if (nsize < 3) return ans;

sort(nums.begin(), nums.end());

for (int i = 0; i < nsize - 2; i++) { //nums[i]를 선택한 다음 0이 되는 쌍을 Two Pointer로 탐색
    if (i && nums[i] == nums[i - 1]) continue; //중복제거

    int l = i + 1, r = nsize - 1;
    while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];

        if (sum > 0) {
            r--;
        } else if (sum < 0) {
            l++;
        } else {
            ans.push_back({nums[i], nums[l], nums[r]});
            while (l < r && nums[l] == nums[l + 1]) l++; // 중복제거
            while (l < r && nums[r] == nums[r - 1]) r--; // 중복제거
            l++; r--; //nums[i]와 0 이 되는 다른 쌍을 찾는다.
        }
    }
}

return ans;
```

Test Case)<p>
Input
> [-1,0,1,2,-1,-4]<br>
> [-2,0,0,2,2]<br>
> [0,0,0,0]<p>

Output
> [[-1,-1,2],[-1,0,1]]<br>
> [[-2,0,2]]<br>
> [[0,0,0]]<p>