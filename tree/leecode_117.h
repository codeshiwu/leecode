#pragma once

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/*
    填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

    初始状态下，所有 next 指针都被设置为 NULL。

*/

Node* connect(Node* root) {
	if (nullptr == root) return root;

	queue<Node*> nodequeue;
	nodequeue.push(root);

	while (!nodequeue.empty())
	{
		int size = nodequeue.size();
		for (int i = 0; i < size; ++i)
		{
			Node* node = nodequeue.front();
			nodequeue.pop();

			if (node->left) nodequeue.push(node->left);
			if (node->right) nodequeue.push(node->right);

			if (i == size - 1)
			{
				node->next = nullptr;
			}
			else
			{
				Node* nextNode = nodequeue.front();
				node->next = nextNode;
			}
		}
	}

	return root;
}

// 层链表连接方法
void handle(Node *&preNode, Node *&curNode, Node *&nextStart)
{
	// 假设当前在遍历二叉树的第 i 层，那么入参均为第 i + 1 层的数据。
	if (preNode)
	{
		preNode->next = curNode;
	}

	if (!nextStart)
	{
		nextStart = curNode;
	}

	preNode = curNode;
}

/* 利用上层为下层建立链表关系 */
Node* connect1(Node* root) {
	if (nullptr == root) return root;
	
	Node* start = root;

	while (nullptr != start)
	{
		// 每层实际上是一个链表
		Node* preNode = nullptr;      // 每层链表的最后一个节点（随着上层遍历进行，该指针一直向后指）
		Node* nextStart = nullptr;    // 下一层的开始节点

		for (auto *node = start; node != nullptr; node = node->next)
		{
			if (node->left)
			{
				handle(preNode, node->left, nextStart);
			}

			if (node->right)
			{
				handle(preNode, node->right, nextStart);
			}
		}

		start = nextStart;
	}

	return root;
}
