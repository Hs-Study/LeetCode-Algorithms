# Review


## 0007. Reverse Integer

Tag) Math<p>

Sol) 배열에 각 자리의 수를 담아 MAX_INT 를 넘는지 확인<br>
그냥 결과값을 long 변수에 담아서 비교할 걸... MAX_INT 각 자리수를 저장한 배열을 만드는 등 복잡하게 푼 것 같다.<p>


Test Case)<p>

> Input: 123<br>
-123<br>
120<br>
-2147483648<br>
>
> Output: 321<br>
-321<br>
21<br>
0
>




## 0009. Palindrome Number

Tag) Math<p>

Sol) 배열에 각 자리수를 저장하여 양쪽 인덱스의 수가 같은지 보고 펠린드롬을 확인하였다. 시간은 256ms (19.51%) 나왔다...<p>
x 1의 자리부터 절반을 y 에 저장하여 둘을 비교하면 훨씬 빠르다.

```c++
bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;

    int y = 0;
    while (x > y) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    
    return x == y || x == y / 10;
}
```

Test Case)<p>

> Input: 121<br>
-121<br>
10<br>
1001<br>
>
> Output: true
false
false
true
>
