//
// Created by 15387 on 2022/5/24.
//

#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H

#include<iostream>
#include<string>


class CArray
{
public:
    // 默认构造函数
    CArray(int size = 5);

    // 析构函数
    ~CArray();

    // 插入元素
    void push(const std::string &str);

    // 删除元素
    std::string pop();

    // 队列是否为空
    bool empty();

    // 队列占用大小
    int size();

private:
    CArray(const CArray &rhs) = delete;
    CArray &operator=(const CArray &rhs) = delete;

    bool full();
private:
    int size_ = 0;       // 数组总容量
    int beg_ = 0;        // 环形队列的起始位置
    int end_ = 0;        // 环形队列的终止位置
    std::string *str_;   // 指针数组（环形队列）
};


#endif //ARRAY_ARRAY_H
