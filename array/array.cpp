//
// Created by 15387 on 2022/5/24.
//

#include "array.h"

CArray::CArray(int size)
: size_(size)
, beg_(0)
, end_(0)
, str_(new std::string[size_])
{
    std::cout << "环形队列构造成功" << std::endl;
}

CArray::~CArray()
{
    if (nullptr != str_) {
        delete[] str_;
        str_ = nullptr;
    }
}

void CArray::push(const std::string &str)
{
    // 判断容量是否已满
    if (full()) {
        std::cout << "队列已满" << std::endl;
        return;
    }

    str_[end_] = str;
    end_ = (end_ +1) % size_;
}

std::string CArray::pop()
{
    std::string str1 = str_[beg_];
    str_[beg_].clear();

    beg_ = (beg_ + 1) % size_;

    return str1;
}

bool CArray::empty()
{
    return beg_ == end_;
}

int CArray::size()
{
    return (end_ - beg_ + size_) % size_;
}

bool CArray::full()
{
    return ((end_ + 1) % size_ == beg_);
}







