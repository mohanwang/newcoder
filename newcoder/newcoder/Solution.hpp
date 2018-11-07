//
//  Solution.hpp
//  newcoder
//
//  Created by maciejwang on 2018/8/25.
//  Copyright © 2018年 maciejwang. All rights reserved.
//

#ifndef Solution_hpp
#define Solution_hpp

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
    label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    // 复杂链表的复制
    RandomListNode* Clone(RandomListNode* pHead);
    void _CloneCopy(RandomListNode *pHead);
    void _CloneConnectRandom(RandomListNode *pHead);
    RandomListNode* _CloneResult(RandomListNode *pHead);
    // 二叉树中和为某一值的路径
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber);
    // 二叉搜索树后序遍历判别
    bool VerifySquenceOfBST(vector<int> sequence);
    bool _VerifySquenceOfBST(vector<int> sequence, size_t begin, size_t end);
    // 从上往下打印二叉树
    vector<int> PrintFromTopToBottom(TreeNode* root);
    // 栈的压入弹出顺序
    bool IsPopOrder(vector<int> pushV,vector<int> popV);

    //包含min函数的栈
    void min_push(int value) {
        stackInt.push(value);
        if (stackMin.empty()) {
            stackMin.push(value);
        } else if (stackMin.top() < value) {
            stackMin.push(stackMin.top());
        } else {
            stackMin.push(value);
        }
    }
    void min_pop() {
        if (!stackInt.empty()) {
            stackInt.pop();
            stackMin.pop();
        }
    }
    int min_top() {
        return stackInt.top();
    }
    
    int min_min() {
        return stackMin.top();
    }
    // 二叉树镜像
    void Mirror(TreeNode *pRoot);
    // 树的子结构
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);
    // 合并有序链表
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2);
    // 翻转链表
    ListNode* ReverseList(ListNode* pHead);
    // 链表查找倒数第K
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);
    // 数组重排序
    void reOrderArray(vector<int> &array);
    // 计算数字二进制中1的个数
    int  NumberOf1(int n);
    // 矩形覆盖
    int rectCover(int number);
    // 变态跳台阶
    int jumpFloorII(int number);
    // 青蛙跳台阶
    int jumpFloor(int number);
    //
    int Fibonacci(int n);
    // 旋转数组的最小数字
    int minNumberInRotateArray(vector<int> rotateArray);  // 二分法
    int minNumberInRotateArray1(vector<int> rotateArray); // 逆序查找

    // 两个栈实现一个队列
    void push(int node);
    int pop();
    
    // 二叉树重建
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin);
    
    // 链表逆向输出
    vector<int> printListFromTailToHead(ListNode* head);
    vector<int> printListFromTailToHead1(ListNode* head);// 递归

    // 字符串替换
    void replaceSpace(char *str,int length);
    
    // 数组查找
    bool Find(int target, vector<vector<int> > array);
    bool Find0(int target, vector<vector<int> > array);
    
private:
    bool _internalHasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);
    
private:
    stack<int> stack1;
    stack<int> stack2;
    stack<int> stackInt;
    stack<int> stackMin;
};




#endif /* Solution_hpp */
