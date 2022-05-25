//
// Created by 15387 on 2022/5/24.
//

#include "linked_list.h"

CLinkedList::CLinkedList()
:_size(1)
,_head(create_node())
{
}

CLinkedList::~CLinkedList()
{
    // 删除所有节点
    SNode *node = _head;
    while (nullptr != node)
    {
        SNode *node_del = node;
        node = node->_next;

        if (nullptr != node_del)
        {
            delete node_del;
            node_del = nullptr;
        }
    }
}

std::string &CLinkedList::getelem(int index) const
{
    std::string str = "";
    if (index < 0 || index > _size - 1)
    {
        std::cout << "error input" << std::endl;
        return _head->_data;
    }

    SNode *node = _head;
    for (int i = 0; i < _size; ++i)
    {
        if (index != i)
        {
            node = node->_next;
            continue;
        }

        break;
    }

    return node->_data;
}

void CLinkedList::addhead(const std::string &str)
{
    SNode *node = create_node(str);
    SNode *next = _head->_next;

    node->_next  = next;
    _head->_next = node;
    _size++;
}

void CLinkedList::addtail(const std::string &str)
{
    SNode *node = create_node(str);
    SNode *tail = _head;

    while (nullptr != tail->_next)
    {
        tail = tail->_next;
    }

    tail->_next = node;
    _size++;
}

void CLinkedList::addindex(int index, const std::string &str)
{
    if (index <= 0 || index > _size)
    {
        std::cout << "error input" << std::endl;
        return;
    }

    SNode *node = _head;
    for (int i = 0; i < _size; ++i)
    {
        if (index - 1 != i)
        {
            node = node->_next;
            continue;
        }

        break;
    }

    SNode *node_insert = create_node(str);

    node_insert->_next = node->_next;
    node->_next = node_insert;
    ++_size;
}

void CLinkedList::delindex(int index)
{
    if (index <= 0 || index > _size)
    {
        std::cout << "error input" << std::endl;
        return;
    }

    SNode *node = _head;
    while (--index)
    {
        node = node->_next;
    }

    SNode *node_del = nullptr;
    if (nullptr != node->_next)
    {
        node_del = node->_next;
        node->_next = node_del->_next;
    }

    if (nullptr != node_del)
    {
        delete node_del;
        node_del = nullptr;
    }

    --_size;
}

int CLinkedList::size()
{
    return _size - 1;
}

void CLinkedList::printlist()
{
    SNode *node = _head->_next;
    while (nullptr != node)
    {
        std::cout << node->_data << "->";
        node = node->_next;

        if (nullptr == node)
        {
            std::cout << "end" << std::endl;
        }
    }
}

SNode *CLinkedList::create_node(const std::string &str)
{
    SNode *node = new SNode(str);
    if (nullptr == node)
    {
        std::cout << "malloc node failed" << std::endl;
        return nullptr;
    }
    return node;
}

void test_linkedlist()
{
    CLinkedList list;

    list.addhead("4");
    list.addhead("3");
    list.addhead("2");
    list.addtail("6");
    list.printlist();

    list.addindex(1, "1");
    list.addindex(list.size(), "5");
    list.printlist();

    list.delindex(0);
    list.delindex(1);
    list.delindex(list.size());
    list.printlist();
}
