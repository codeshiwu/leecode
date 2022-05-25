//
// Created by 15387 on 2022/5/24.
//

#ifndef LINKLEDIST_LEECODE_142_H
#define LINKLEDIST_LEECODE_142_H

/**
 * 题目描述：给定一个链表的头结点，返回链表开始入环的第一个节点，若没有环则返回空
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

// 快慢指针解法
ListNode *detectCycle(ListNode *head) {
    ListNode *node_fast = head;
    ListNode *node_slow = head;

    while (nullptr != node_fast && nullptr != node_fast->next)
    {
        node_fast = node_fast->next->next;
        node_slow = node_slow->next;

        if (node_fast == node_slow)
        {
            // 有环
            ListNode *index1 = head;        // 第一个节点
            ListNode *index2 = node_slow;   // 相交节点

            while(index1 != index2)
            {
                index1 = index1->next;
                index2 = index2->next;
            }

            return index2;
        }
    }

    return nullptr;
}

#endif //LINKLEDIST_LEECODE_142_H
