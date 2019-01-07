# String

### 0006. ZigZag Conversion

Sol)

배열을 numRows 만큼 만든다음 아래방행, 위방향으로 반복적으로 순회하면서 스트링의 문자 하나하나를 담았다.



Worng Ans)

```c++
#include <vector>

class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> v(numRows);
        int cur = 1;
        int add = 1;
        v[0].push_back(s[0]);
        for(int i=1; i<s.size(); i++) {
            v[cur].push_back(s[i]);
            if(cur == numRows-1) {
                add = -1;
                cur--;
            }
            else if(cur == 0) {
                add = 1;
                cur++;
            }
            else 
                cur += add;  
        }
        
        char *ans = new char[s.size()+1];
        int idx=0;
        for(int i=0; i<numRows; i++) {
            for(int j=0; j<v[i].size(); j++) {
                ans[idx++] = v[i][j];
            }
        }
        ans[idx] = 0;
        return ans;
    }
};
```

> 위 코드에서는 numRows 가 1인 경우 runtime error 가 발생하였다.
>
> if(numRows == 1) return s;` 코드를 추가하니 해결 되었다.