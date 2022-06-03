//
// Created by 15387 on 2022/5/25.
//

#ifndef HASH_LEECODE_454_H
#define HASH_LEECODE_454_H

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * 题目描述：给定四个长度相同的数组，找出有几种元祖可以使A[i] + B[j] + C[k] + D[l] = 0
 */

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    int count = 0;
    unordered_map<int, int> map;

    for (auto v1 : nums1) {
        for (auto v2 : nums2) {
            map[v1 + v2]++;
        }
    }

    for (auto v3 : nums3) {
        for (auto v4 : nums4) {
            if (map.find(0 - v3 - v4) != map.end()) {
                // 这里是因为每个值都对应之前的n种组合。
                count += map[0 - v3 - v4];
            }
        }
    }
    return count;
}

#endif //HASH_LEECODE_454_H
