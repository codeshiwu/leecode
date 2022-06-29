//
// Created by 15387 on 2022/6/26.
//

#ifndef TREE_LEECODE_144_H
#define TREE_LEECODE_144_H


#include "treeNode.h"
#include <vector>
#include <stack>

/* 题目描述：二叉树的前序遍历 */

void traverse(TreeNode *cur, vector<int> &result) {
    if (nullptr == cur) return;

    result.push_back(cur->val);
    traverse(cur->left, result);
    traverse(cur->right, result);
}

// 递归方法
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    traverse(root, result);
    return result;
}

// 迭代方法
// 入栈顺序：中右左（每个节点都要按照此顺序入栈，空节点不入栈）
vector<int> preorderTraversal1(TreeNode *root) {
    vector<int> result;
    if (nullptr == root) return result;

    stack<TreeNode *> st;
    st.push(root);

    while (st.size()) {
        TreeNode *cur = st.top();
        st.pop();

        if (cur->right) {
            st.push(cur->right);
        }

        if (cur->left) {
            st.push(cur->left);
        }

        if (cur) {
            result.push_back(cur->val);
        }
    }

    return result;
}

#endif //TREE_LEECODE_144_H
