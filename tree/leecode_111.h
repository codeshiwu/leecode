#pragma once

/*
	����һ�����������ҳ�����С��ȡ�

	��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������
 */

#include <iostream>
#include <queue>
#include <vector>

#include "treeNode.h"

using namespace std;

int minDepth(TreeNode* root) {
	int depth = 0;
	if (nullptr == root) return depth;

	queue<TreeNode*> queue;
	queue.push(root);

	while (!queue.empty())
	{
		int size = queue.size();
		TreeNode* node = nullptr;

		++depth;

		for (int i = 0; i < size; ++i)
		{
			node = queue.front();
			queue.pop();

			if (node->left) queue.push(node->left);
			if (node->right) queue.push(node->right);

			if (!node->left && !node->right)
			{
				return depth;
			}
		}
	}

	return depth;
}

