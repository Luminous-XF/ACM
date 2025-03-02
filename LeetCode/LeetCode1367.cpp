//
// Created by Luminous on 2024/12/30 16:05
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSubPath(ListNode *head, TreeNode *root) {
        if (root == nullptr) return false;
        return check(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

    bool check(ListNode *cur, TreeNode *root) {
        if (cur == nullptr) return true;
        if (root == nullptr) return false;
        if (cur->val != root->val) return false;
        return check(cur->next, root->right) || check(cur->next, root->left);
    }
};