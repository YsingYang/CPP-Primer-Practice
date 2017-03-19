#include<stdio.h>
#include<iostream>

class TreeNode{
public:
    /**
        构造函数
    */
    TreeNode():value(string()),count(0),left(nullptr),right(nullptr){}
    TreeNode(TreeNode &rtn){
        value = rtn.value;
        count = rtn.count;
        left = rtn.left;
        right = rtn.right;
    }


    /**
        拷贝控制
    */
    TreeNode &operator=(TreeNode  &rtn){
        value = rtn.value;
        count = rtn.count;
        delete(left);
        left = rtn.left;
        delete(right);
        right = rtn.right;
        return *this;
    }

    /**
        析构函数
    */
    ~TreeNode(){
        delete(left);
        delete(right);
    }

private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};
