#include "Queue.h"
#include <iostream>
#include <fstream>

using namespace std;

Queue::Queue(int initialCapacity) {
    capacity = initialCapacity;
    data = new TreeNode*[capacity];  // Теперь храним указатели на TreeNode
    front = 0;
    rear = -1;
}

Queue::~Queue() {
    delete[] data;
}

void Queue::push(TreeNode* value) {  // Теперь принимаем указатель на TreeNode
    if (rear == capacity - 1) {
        capacity *= 2;
        TreeNode** newData = new TreeNode*[capacity];  // Теперь храним указатели на TreeNode
        for (int i = 0; i <= rear; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[++rear] = value;
}

TreeNode* Queue::pop() {  // Теперь возвращаем указатель на TreeNode
    if (front > rear) {
        cout << "Queue is empty!\n";
        return nullptr;  // Возвращаем nullptr, если очередь пуста
    }
    return data[front++];
}

TreeNode* Queue::peek() const {  // Теперь возвращаем указатель на TreeNode
    if (front > rear) {
        cout << "Queue is empty!\n";
        return nullptr;  // Возвращаем nullptr, если очередь пуста
    }
    return data[front];
}

bool Queue::isEmpty() const {
    return front > rear;
}

void Queue::print() const {
    for (int i = front; i <= rear; i++) {
        cout << data[i]->val << " ";  // Выводим значение узла
    }
    cout << "\n";
}

void Queue::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file for writing!\n";
        return;
    }
    file << "Queue\n";
    for (int i = front; i <= rear; i++) {
        file << data[i]->val << "\n";  // Сохраняем значение узла
    }
    file.close();
}

void Queue::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file for reading!\n";
        return;
    }
    string header;
    getline(file, header);
    if (header != "Queue") {
        cout << "Invalid file format!\n";
        return;
    }
    int value;
    while (file >> value) {
        push(new TreeNode(value));  // Создаем новый узел и добавляем его в очередь
    }
    file.close();
}