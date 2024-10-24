#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Queue {
private:
    TreeNode** data;  // Теперь храним указатели на TreeNode
    int front;
    int rear;
    int capacity;

public:
    Queue(int initialCapacity = 10);
    ~Queue();

    void push(TreeNode* value);  // Теперь принимаем указатель на TreeNode
    TreeNode* pop();  // Теперь возвращаем указатель на TreeNode
    TreeNode* peek() const;  // Теперь возвращаем указатель на TreeNode
    bool isEmpty() const;
    void print() const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif