#pragma once

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

/* ����һ�� N ������������ڵ�ֵ�Ĳ�����������������ң��������� */

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> result;
    if (nullptr == root) return result;

    vector<int> level;
    queue<Node*> queue;
    queue.push(root);

    while (!queue.empty())
    {
        int size = queue.size();
        Node* node = nullptr;

        for (int i = 0; i < size; ++i)
        {
            node = queue.front();
            queue.pop();

            level.push_back(node->val);

            for (int j = 0; j < node->children.size(); ++j)
            {
                if (node->children[j]) queue.push(node->children[j]);
            }
        }

        result.push_back(level);
        level.clear();
    }

    return result;
}
