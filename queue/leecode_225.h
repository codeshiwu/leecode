//
// Created by 15387 on 2022/6/19.
//

#ifndef QUEUE_LEECODE_225_H
#define QUEUE_LEECODE_225_H

#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    MyStack() = default;

    void push(int x) {
        stack.push(x);
    }

    int pop() {
        int num;
        int size = stack.size();

        while (--size) {
            num = stack.front();
            stack.pop();
            stack.push(num);
        }

        num = stack.front();
        stack.pop();
        return num;
    }

    int top() {
        int num;
        int size = stack.size();

        while (size--) {
            num = stack.front();
            stack.pop();
            stack.push(num);
        }

        return num;
    }

    bool empty() {
        return stack.empty();
    }

private:
    queue<int> stack;
};


#endif //QUEUE_LEECODE_225_H
