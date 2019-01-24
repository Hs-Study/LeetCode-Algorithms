# Review



## 0006. ZigZag Conversion

Tag) String<p>

Sol) 층마다 문자열 인덱스를 더해가는 규칙을 찾는다.<p>
1. 맨 윗 층은 2*numRows-2 만큼 더한다.<br>
2. 두번째 층부터 맨 아래 전 층까지 2*(numRows-i)-2 와 2*(numRows)-2 - 2*(numRows-i)-2 를 번갈아가며 더한다.<br>
3. 맨 아랫 층도 2*numRows-2 만큼 더한다.<p>

Test Case)<p>
Input
> "PAYPALISHIRING", 3<br>
> "PAYPALISHIRING", 4<br>
> "A", 1<br>
> "AB", 1<p>

Output
> "PAHNAPLSIIGYIR"<br>
> "PINALSIGYAHRPI"<br>
> "A"<br>
> "AB"<p>

## 0014. Longest Common Prefix

Tag) String<p>

Sol) 문자를 검사할 위치(pos)를 증가시키면서 모든 문자열의 pos 위치의 문자를 ascii 배열에 저장한 다음, 아무 문자열의 pos 위치의 문자로 ascii 배열에 넣어 개수를 구해 strs 의 크기와 비교하여 같으면 검사위치를 증가시키고, 다르면 종료한다.<p>

```c++
int ascii[128]={0};
for(string str:strs){
    if(str.length()==pos) {
        running=false;
        break;
    }
    ascii[str[pos]]++;
}
char ch=strs[0][pos];
if(ascii[ch]==n) { //찾은 문자 개수와 strs 크기가 같으면 공통 접두
    pos++;
    ans.push_back(ch);
}else{ //종료
    break;
}
```

Test Case)<p>
Input
>["flower","flow","flight"]<br>
>["dog","racecar","car"]<p>

Output
>"fl"<br>
>""<p>