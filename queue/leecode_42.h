//
// Created by 15387 on 2022/6/19.
//

#ifndef QUEUE_LEECODE_42_H
#define QUEUE_LEECODE_42_H

/**
 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 输出：6
 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。

 */

#include <iostream>
#include <vector>
#include <stack>


using namespace std;


/**
 * 总体思路：每个位置的需水量取决于 左侧最大列高度和右侧最大列高度
 *         该位置续水量 = min(maxL, maxR) - curHeight;
 */


int trap(vector<int>& height) {
    int sum = 0;
    int size = height.size();


    // 得到每个位置的左侧的最大列高度
    vector<int> vecL(size);
    vecL[0] = height[0];
    for (int i = 1; i < size; ++i) {
        vecL[i] = max(vecL[i - 1], height[i]);
    }

    // 得到每个位置的右侧的最大列高度
    vector<int> vecR(size);
    vecR[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; --i) {
        vecR[i] = max(vecR[i + 1], height[i]);
    }

    for (int i = 0; i < size; ++i) {
        if (i == 0 || i == size - 1) continue;

        sum += min(vecL[i], vecR[i]) - height[i];
    }

    return sum;
}

// 使用栈的思路来做
// 具体思路：将每一列的高度分别入栈，当当前列高大于栈顶元素时，说明出现凹槽可以积水，此时当前元素为蓄水区的右半部分，栈顶元素为蓄水区底部，栈顶元素的前一个元素为蓄水区左半部分

// 积水区域高度 = min(左列高， 右列高) - 底部列高
// 积水区域宽度 = 右列高索引 - 左列高索引 - 1
int trap1(vector<int>& height) {
    int sum = 0;
    stack<int> stk;

    for (int i = 0; i < height.size(); ++i) {
        while (!stk.empty() && height[i] > height[stk.top()]) {
            int mid = stk.top();
            stk.pop();

            if (!stk.empty()) {
                int h = min(height[stk.top()], height[i]) - height[mid];
                int w = i - stk.top() - 1;
                sum += h * w;
            }
        }

        stk.push(i);
    }
    return sum;
}

int trap2(vector<int>& height) {
    int maxL  = 0, maxR = 0;
    int lft = 0;
    int rht = height.size() - 1;
    int sum = 0;

    while (lft < rht) {
        maxL = max(maxL, height[lft]);
        maxR = max(maxR, height[rht]);

        if (maxL < maxR) {
            sum += maxL - height[lft];
            lft++;
        } else {
            sum += maxR - height[rht];
            rht--;
        }
    }

    return sum;
}



#endif //QUEUE_LEECODE_42_H
