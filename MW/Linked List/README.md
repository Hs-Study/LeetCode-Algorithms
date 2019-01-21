# Review

## 0002. Add Two Numbers

Tag) Linked List<p>

Sol) 중복되는 부분을 줄이기 위해 함수로 뺐는데 52ms 에서 76ms로 느려졌다.<br>
ans 리스트는 HEAD를 쓰면 반복문 중간에 NULL 체크를 할 필요없었다.<br>
다음은 보완한 코드.

```c++
auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
....
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *p1 = l1, *p2 = l2;
    ListNode *ans = new ListNode(0);
    ListNode *p3 = ans;
    int carry = 0;

    for (; p1 != NULL && p2 != NULL; p1=p1->next, p2=p2->next, p3=p3->next) {
        int sum = p1->val + p2->val + carry;
        carry = sum / 10;
        sum %= 10;
        p3->next = new ListNode(sum);
    }
    for (; p1 != NULL; p1=p1->next, p3=p3->next) {
        int sum = p1->val + carry;
        carry = sum / 10;
        sum %= 10;
        p3->next = new ListNode(sum);
    }
    for (; p2 != NULL; p2=p2->next, p3=p3->next) {
        int sum = p2->val + carry;
        carry = sum / 10;
        sum %= 10;
        p3->next = new ListNode(sum);
    }

    if (carry > 0) {
        p3->next = new ListNode(carry);
    }

    return ans->next;
}
```

Test Case)<p>
Input
> [2,4,3], [5,6,4]<br>

Output
> [7,0,8]<p>