//
// Created by 15387 on 2022/6/19.
//

#ifndef QUEUE_LEECODE_347_H
#define QUEUE_LEECODE_347_H

/*
  给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

  输入: nums = [1,1,1,2,2,3], k = 2
  输出: [1,2]

 */
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class myconparion {
public:
    // 小顶堆，即整棵树自上而下 从小到大
    bool operator() (const pair<int, int> lft, const pair<int, int> rht) {
        return lft.second > rht.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;

    for (const auto val : nums) {
        map[val]++;
    }

    // 优先级队列  按照升序排列
    priority_queue<pair<int, int>, vector<pair<int, int>>, myconparion> queue;

    for (const auto &elem : map) {
        queue.push(elem);

        // 保证只有 k 个元素
        if (queue.size() > k) {
            queue.pop();
        }
    }

    // 倒序输出 从大到小排列
    vector<int> rst(k);
    for (unsigned i = k - 1; i >= 0; --i) {
        rst[i] = queue.top().first;
        queue.pop();
    }

    return rst;
}

#endif //QUEUE_LEECODE_347_H
