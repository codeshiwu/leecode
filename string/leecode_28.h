//
// Created by 15387 on 2022/6/6.
//

#ifndef STRING_LEECODE_28_H
#define STRING_LEECODE_28_H

/*
 题目描述：
 实现strStr()函数。
 给你两个字符串haystack和needle请你在haystack字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回-1 。

 实例：
 输入：haystack = "hello", needle = "ll"
 输出：2
*/

#include <iostream>
#include <string>

using namespace std;

// 暴力解法 时间复杂度 O(m * n)
int strStr(string haystack, string needle) {
    if (needle.size() == 0) {
        return 0;
    }

    int result = -1;
    for (int i = 0; i < haystack.size(); ++i) {
        int index = i;

        for (int j = 0; j < needle.size(); ++j, ++index) {
            if (haystack[index] != needle[j]) {
                break;
            }

            // 完全匹配
            if (j == needle.size()) {
                return i;
            }
        }
    }

    return result;
}

// 使用KMP算法  时间复杂度为O(m + n)
int strStr_1(string haystack, string needle) {
    if (needle.size() == 0) {
        return 0;
    }

    // 1. 获取前缀表
    int *next = new int[needle.size()];
    if (nullptr == next) {
        return -1;
    }

    int j = 0;
    next[0] = j;
    for (int i = 1; i < needle.size(); ++i) {
        while (j > 0 && needle[i] != needle[j] ) {
            j = next[j - 1];
        }

        if (needle[i] == needle[j]) {
            j++;
        }

        next[i] = j;
    }

    int rst = -1;

    // 2. 进行匹配
    int index = 0;
    for (int i = 0; i < haystack.size(); ++i) {
        while (index > 0 && haystack[i] != needle[index]) {
            index = next[index - 1];
        }

        if (haystack[i] == needle[index]) {
            ++index;
        }

        if (index == needle.size()) {
            rst = i - index + 1;
            break;
        }
    }

    if (nullptr != next) {
        delete []next;
        next = nullptr;
    }

    return rst;
}


#endif //STRING_LEECODE_28_H
