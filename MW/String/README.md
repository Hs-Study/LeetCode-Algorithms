# Review



## 0006. ZigZag Conversion

Tag) String<p>

Sol) 층마다 문자열 인덱스를 더해가는 규칙을 찾는다.<p>
1. 맨 윗 층은 2*numRows-2 만큼 더한다.<br>
2. 두번째 층부터 맨 아래 전 층까지 2*(numRows-i)-2 와 2*(numRows)-2 - 2*(numRows-i)-2 를 번갈아가며 더한다.<br>
3. 맨 아랫 층도 2*numRows-2 만큼 더한다.<p>

Test Case)<p>

> Input: "PAYPALISHIRING", 3<br>
"PAYPALISHIRING", 4<br>
"A", 1<br>
"AB", 1<br>
>
> Output: "PAHNAPLSIIGYIR"<br>
"PINALSIGYAHRPI"<br>
"A"<br>
"AB"<br>
>
