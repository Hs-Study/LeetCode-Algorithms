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

> Input: 
> "abcabcbb"
> "bbbbb"
> "pwwkew"
> "dvdf"
> " "
> ""
>
> Output:
> 3
> 1
> 3
> 3
> 1
> 0