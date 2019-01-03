# Review



## 0001. Two Sum

Tag) Array, Hash_Table<p>

Sol) 한 배열의 서로 다른 element 를 더한 결과를 target 과 비교해야 한다.<p>
- 2중 for 문으로 구현할 경우 O(n²) 시간복잡도를 가진다. '서로 다른 element' 조건도 고려해야 한다.<br>
- map 을 사용한 방법은 안쪽 for 문을 map 의 find 로 대체하여 O(nlog n) 시간복잡도를 가진다.<br>
이미 탐색한 수를 map 에 저장해두고 target - num 이 있는지 find 한다.<br>
- 만약 같은 element 로 더한 결과도 포함시킬 경우, find 를 실행하기 전에 map 에 num 을 저장하면 된다.<p>


Test Case)<p>

> Input: [3,2,4] 6
>
> Output: [1,2]
>
