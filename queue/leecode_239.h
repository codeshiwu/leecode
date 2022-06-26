//
// Created by 15387 on 2022/6/19.
//

#ifndef QUEUE_LEECODE_239_H
#define QUEUE_LEECODE_239_H

/*
 给你一个整数数组 nums，有一个大小为k的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k个数字。滑动窗口每次只向右移动一位。
 返回 滑动窗口中的最大值

 示例 1：

 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
    输出：[3,3,5,5,6,7]
    解释：
    滑动窗口的位置                最大值
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
     1 [3  -1  -3] 5  3  6  7       3
     1  3 [-1  -3  5] 3  6  7       5
     1  3  -1 [-3  5  3] 6  7       5
     1  3  -1  -3 [5  3  6] 7       6
     1  3  -1  -3  5 [3  6  7]      7
 */

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <queue>
#include <deque>

using namespace std;

// 暴力解法， 会超出时间限制
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> rst;
    queue<int>  que;

    int max = INT32_MIN;
    for (int i = 0; i < nums.size(); ++i) {
        if (i < k) {
            que.push(nums[i]);
            max = max < nums[i] ? nums[i] : max;
        } else {
            max = INT32_MIN;
            que.pop();
            que.push(nums[i]);

            // 计算最大值
            int size = que.size();
            for (int j = 0; j < size ; ++j) {
                int temp = que.front();
                max = max < temp ? temp : max;

                que.pop();
                que.push(temp);
            }
        }

        if (i >= k - 1) {
            rst.push_back(max);
        }
    }

    return rst;
}

class MyQueue1
{
public:
    void push(int value) {
        while (!que.empty() && value > que.back()) {
            que.pop_back();
        }

        que.push_back(value);
    }

    int front()
    {
        return que.front();
    }

    void pop(int value) {
        if (!que.empty() && value == que.front()) {
            que.pop_front();
        }
    }
private:
    deque<int> que;
};

vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
    vector<int> rst;
    MyQueue1 que;

    for (int i = 0; i < k; ++i) {
        que.push(nums[i]);
    }
    rst.push_back(que.front());

    for (int i = k; i < nums.size(); ++i) {
        que.pop(nums[i - k]);
        que.push(nums[i]);

        rst.push_back(que.front());
    }

    return rst;
}


#endif //QUEUE_LEECODE_239_H
