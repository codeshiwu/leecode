//
// Created by 15387 on 2022/5/24.
//

#ifndef LINKLEDIST_LEECODE_19_H
#define LINKLEDIST_LEECODE_19_H

/**
 * 题目描述：删除列表的倒数第n个节点（n从1开始）
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 暴力解法
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *node = head;
    int size = 0;
    while (nullptr != node)
    {
        ++size;
        node = node->next;
    }

    if (n > size)
    {
        return head;
    }

    int loop = size - n;
    ListNode *node_del = nullptr;
    if (0 == loop)
    {
        // 说明删除的是第一个节点
        node_del = head;
        head = head->next;
    }
    else
    {
        node = head;
        while (--loop)
        {
            node = node->next;
        }

        node_del = node->next;
        node->next = node_del->next;
    }

    delete node_del;
    node_del = nullptr;

    return head;
}

// 其他解法
ListNode* removeNthFromEnd2(ListNode* head, int n) {
    ListNode dummy_head = ListNode(0, head);

    ListNode *node_fast = &dummy_head;    // 快指针
    ListNode *node_slow = &dummy_head;    // 慢指针(待删除节点的前一个节点)
    ListNode *node_del = nullptr;

    while (n--)
    {
        node_fast = node_fast->next;

        if (nullptr == node_fast && n)
        {
            return head;
        }
    }

    while (nullptr != node_fast->next)
    {
        node_fast = node_fast->next;
        node_slow = node_slow->next;
    }

    node_del = node_slow->next;
    node_slow->next = node_del->next;

    delete node_del;
    node_del = nullptr;

    return dummy_head.next;
}

#endif //LINKLEDIST_LEECODE_19_H
