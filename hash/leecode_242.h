//
// Created by 15387 on 2022/5/25.
//

#ifndef HASH_LEECODE_242_H
#define HASH_LEECODE_242_H

#include <iostream>
#include <string>

using namespace std;

/**
 * 题目描述：判断字符串s中的字符是否可以通过改变顺序的方式变成字符串t
 *         如果字符串s与字符串t相同，那么也是可以的
 *         字符串中只包含小写字母
 */

// 暴力解法
// 思路为遍历两字符串，若相等则同时删除字符，到最后看两字符串长度为0
bool isAnagram_1(string s, string t) {
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < t.size(); ++j) {
            if (s[i] == t[j])
            {
                s.erase(i, 1);
                t.erase(j, 1);

                i--;
                break;
            }
        }

    }

    return (s.size() || t.size()) == false;
}

// 使用哈希表的思想
bool isAnagram_2(string s, string t) {
    char hash[26] = {0};

    for (auto val : s) {
        hash[val - 0x61]++;
    }

    for (auto val : t) {
        hash[val - 0x61]--;
    }

    for (int i = 0; i < 26; ++i) {
        if (hash[i] != 0) {
            return false;
        }
    }

    return true;
}

#endif //HASH_LEECODE_242_H
