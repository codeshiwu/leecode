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
    // Ĭ�Ϲ��캯��
    CArray(int size = 5);

    // ��������
    ~CArray();

    // ����Ԫ��
    void push(const std::string &str);

    // ɾ��Ԫ��
    std::string pop();

    // �����Ƿ�Ϊ��
    bool empty();

    // ����ռ�ô�С
    int size();

private:
    CArray(const CArray &rhs) = delete;
    CArray &operator=(const CArray &rhs) = delete;

    bool full();
private:
    int size_ = 0;       // ����������
    int beg_ = 0;        // ���ζ��е���ʼλ��
    int end_ = 0;        // ���ζ��е���ֹλ��
    std::string *str_;   // ָ�����飨���ζ��У�
};


#endif //ARRAY_ARRAY_H
