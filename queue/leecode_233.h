//
// Created by 15387 on 2022/6/19.
//

#ifndef QUEUE_LEECODE_233_H
#define QUEUE_LEECODE_233_H


#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() = default;

    // 入栈
    void push(int n) {
        in.push(n);
    }

    // 出栈
    int pop() {
        swap();

        int result = out.top();
        out.pop();
        return result;
    }

    // 获取栈顶元素
    int peek() {
        swap();

        return out.top();
    }

    // 栈是否为空
    bool empty() {
        return in.empty() && out.empty();
    }

private:
    void swap() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }


private:
    stack<int> in;
    stack<int> out;
};


#endif //QUEUE_LEECODE_233_H
