#pragma once

#include <iostream>
#include <queue>
#include <vector>

#include "treeNode.h"

using namespace std;

/*
	����һ���ǿն������ĸ��ڵ� root , ���������ʽ����ÿһ��ڵ��ƽ��ֵ����ʵ�ʴ���� 10-5 ���ڵĴ𰸿��Ա����ܡ�
*/

vector<double> averageOfLevels(TreeNode* root) {
	vector<double> result;
	if (nullptr == root) return result;

	queue<TreeNode*> queue;
	queue.push(root);

	while (!queue.empty())
	{
		int size = queue.size();
		long sum = 0;

		TreeNode* node = nullptr;

		for (int i = 0; i < size; ++i)
		{
			node = queue.front();
			sum += node->val;
			queue.pop();

			if (node->left) queue.push(node->left);
			if (node->right) queue.push(node->right);
		}

		result.push_back((double)sum / size);
	}

	return result;
}