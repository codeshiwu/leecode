//
// Created by 15387 on 2022/6/19.
//

#ifndef QUEUE_LEECODE_150_H
#define QUEUE_LEECODE_150_H

/*
 根据 逆波兰表示法，求表达式的值。
 有效的算符包括+、-、*、/。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
 注意两个整数之间的除法只保留整数部分。
 可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

 输入：tokens = ["2","1","+","3","*"]
 输出：9
 解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
 */

#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int evalRPN(vector<string>& tokens) {
    int rst = 0;

    stack<int> stk;
    for (const auto &str : tokens) {
        if (str != "*" && str!= "/" && str != "-" && str != "+") {
            // 数字
            stk.push(std::stoi(str));
        } else {
            // 运算符
            int n1 = 0, n2 = 0;
            n1 = stk.top();
            stk.pop();
            n2 = stk.top();
            stk.pop();

            if (str == "*") {
                stk.push(n2 * n1);
            } else if (str == "/") {
                stk.push(n2 / n1);
            } else if (str == "-") {
                stk.push(n2 - n1);
            } else if (str == "+") {
                stk.push(n2 + n1);
            }
        }
    }

    return stk.top();
}


#endif //QUEUE_LEECODE_150_H
