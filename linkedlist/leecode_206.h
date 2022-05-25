//
// Created by 15387 on 2022/5/24.
//

#ifndef LINKLEDIST_LEECODE_206_H
#define LINKLEDIST_LEECODE_206_H

/**
 * 题目描述：翻转一个链表，要求不能使用额外的内存空间
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 双指针 遍历法
ListNode *reverseList(ListNode *head) {
    ListNode *cur = head;
    ListNode *pre = nullptr;
    ListNode *tmp;

    while (nullptr != cur)
    {
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }

    return pre;
}

ListNode *reverse(ListNode *pre, ListNode *cur)
{
    if (nullptr == cur) return pre;

    ListNode *tmp;

    tmp = cur->next;
    cur->next = pre;
    pre = cur;
    cur = tmp;

    return reverse(pre, cur);
}

// 递归法
ListNode *reverseList(ListNode *head) {
    return reverse(nullptr, head);
}

#endif //LINKLEDIST_LEECODE_206_H
