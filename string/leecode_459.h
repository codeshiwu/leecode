//
// Created by 15387 on 2022/6/6.
//

#ifndef STRING_LEECODE_459_H
#define STRING_LEECODE_459_H

/*
 题目描述:
 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

 实例：
 输入: s = "abab"
 输出: true
 解释: 可由子串 "ab" 重复两次构成。
 */

#include <iostream>
#include <string>

using namespace std;

bool repeatedSubstringPattern(string s) {
    int *next = new int[s.size()];
    if (nullptr == next) {
        return false;
    }

    int j = 0, len = s.size();
    next[0] = j;
    for (int i = 1; i < len; ++i) {
        while (j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        }

        next[i] = j;
    }


    bool rst = false;
    if ((len > 0)  && len > next[len - 1] && next[len - 1] && (len % (len - next[len - 1]) == 0)) {
        rst = true;
    } else {
        rst = false;
    }

    if (nullptr != next) {
        delete []next;
        next = nullptr;
    }

    return rst;
}

#endif //STRING_LEECODE_459_H
