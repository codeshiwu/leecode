#pragma once

// ����һ���������� ���ڵ� root�������Լ�վ�������Ҳ࣬���մӶ������ײ���˳�򣬷��ش��Ҳ����ܿ����Ľڵ�ֵ��

#include <iostream>
#include <queue>
#include <vector>

#include "treeNode.h"

using namespace std;

vector<int> rightSideView(TreeNode* root) {
	vector<int> result;
	if (nullptr == root) return result;

	queue<TreeNode*> queue;
	queue.push(root);

	while (!queue.empty())
	{
		int size = queue.size();
		TreeNode* node = nullptr;

		for (int i = 0; i < size; ++i)
		{
			node = queue.front();
			queue.pop();

			if (node->left) queue.push(node->left);
			if (node->right) queue.push(node->right);
		}

		result.push_back(node->val);
	}

	return result;
}
