# DP

## 0005 Longest Palindromic Substring

sol)

d\[i][j] : 문자열의 구간 [i, j] 가 팰린드롬인지.

d\[i][j] = s[i] == s[j] ? d\[i+1][j-1] : 0 

[i, j] 가 팰린드롬이고, 그 구간이 가장 길면 구간을 저장해 놓는다. 

시간 복잡도는 O(n^2)



[Manacher's Algorithm](https://algospot.com/wiki/read/Manacher's_algorithm) 을 사용하면 O(n) 에 해결 가능하다고 한다. 

