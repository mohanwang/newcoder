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

class Solution {
public:
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
    stack<int> stack1;
    stack<int> stack2;
};




#endif /* Solution_hpp */
