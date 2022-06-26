//
// Created by 15387 on 2022/6/19.
//

#ifndef QUEUE_LEECODE_20_H
#define QUEUE_LEECODE_20_H

#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

/*
给定一个只包括 '('，')'，'{'，'}'，'['，']'的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
 */


bool isValid(string s) {
    stack<int> stk1;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            stk1.push(')');
        } else if (s[i] == '[') {
            stk1.push(']');
        } else if (s[i] == '{') {
            stk1.push('}');
        } else if (stk1.empty() || stk1.top() != s[i]) {
            return false;
        } else {
            stk1.pop();
        }
    }

    return stk1.empty();
}

#endif //QUEUE_LEECODE_20_H
