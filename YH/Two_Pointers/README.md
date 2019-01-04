# Review



## 0003  Longest Substring Without Repeating Characters

sol)

현재 봐야 하는 문자(s[i]) 가 이미 체크가 되어 있으면, 이전까지의 길이를 `ans` 에 갱신.

그리고 [prev, i) 구간에서 i번째 문자가 나오는 구간까지 체크를 해제하고, i번째 문자를 체크한다. 그리고 반복



```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int prev=0;
        int check[128]={0};
        
        int ans=0;
        check[s[0]] = 1;
        for(int i=1; i<s.size(); i++) {
            if(!check[s[i]]) {
                check[s[i]] = 1;
            }
            else {
                ans = max(ans, i-prev);
                while(s[prev] != s[i]) {
                    check[s[prev++]] = 0;    
                }
                check[s[prev++]] = 0;
                check[s[i]] = 1;
            }
        }
        ans = max(ans, s.size()-prev);
        return ans;
    }
    
    int max(int a, int b) {
        return a > b ? a : b;
    }
};
```

> 위의 코드(정답코드)에서 `return ans;` 위의 라인을 추가하지 않아서 한번 틀리고, 
>
> " "
>
> Output: 0
>
> Expected: 1
>
> `while(s[prev] != s[i]) { ... }` 아래에 `ans = max(ans, i-prev)` 를 넣어서 한번 틀렸었다.
>
> Input: "cdd"
>
> Output: 1
>
> Expected: 2



```
int x = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
        int maxLen = 0, start = -1;
        vector<int> charStart(128, -1);
        for(int end = 0; end < s.length(); end++){
            start = max(charStart[s[end]], start);
            maxLen = max(maxLen, end - start);
            charStart[s[end]] = end;
        }
		return maxLen;
	}
};
```

> 다른 유저의 8ms 로 AC를 받은 코드이다.  (처음 6줄을 주석처리하면 28ms 가 나온다.)
>
> 그리고 charStart 는 현재 만난 문자의 이전까지의 가장 최근의 인덱스를 저장하고 있는 것 같다.