//
// Created by 15387 on 2022/5/24.
//

#ifndef LINKLEDIST_LINKED_LIST_H
#define LINKLEDIST_LINKED_LIST_H

#include <iostream>
#include <string>

struct SNode
{
    SNode(const std::string &str = "")
    : _next(nullptr)
    , _data(str)
    {}

    ~SNode()
    {
    }

    SNode *_next;
    std::string _data;
};

class CLinkedList
{
public:
    CLinkedList();
    ~CLinkedList();

    // 获取链表第 index 个节点的数据
    std::string &getelem(int index) const;

    void addhead(const std::string &str);
    void addtail(const std::string &str);

    // 在第index节点插入节点数据
    void addindex(int index, const std::string &str);

    // 删除第index个节点
    void delindex(int index);

    int size();

    // 打印整个链表
    void printlist();
private:
    CLinkedList(const CLinkedList &rhs) = delete;
    CLinkedList &operator=(const CLinkedList &rhs) = delete;

    SNode *create_node(const std::string &str = "");

private:
    int _size;     // 链表总元素
    SNode *_head;  // 链表头指针
};

void test_linkedlist();


#endif //LINKLEDIST_LINKED_LIST_H
