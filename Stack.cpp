#include "Stack.h"
#include <iostream>
#include <fstream>

using namespace std;

Stack::Stack(int initialCapacity) {
    capacity = initialCapacity;
    data = new string[capacity];  
    top = -1;
}

Stack::~Stack() {
    delete[] data;
}

void Stack::push(const string& value) { 
    if (top == capacity - 1) {
        capacity *= 2;
        string* newData = new string[capacity]; 
        for (int i = 0; i <= top; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[++top] = value;
}

string Stack::pop() {  
    if (top == -1) {
        cout << "Stack is empty!\n";
        return "";  // Возвращаем пустую строку, если стек пуст
    }
    return data[top--];
}

string Stack::peek() const {  
    if (top == -1) {
        cout << "Stack is empty!\n";
        return ""; 
    }
    return data[top];
}

bool Stack::isEmpty() const {
    return top == -1;
}

void Stack::print() const {
    for (int i = 0; i <= top; i++) {
        cout << data[i] << " ";  // Выводим строки
    }
    cout << "\n";
}

void Stack::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file for writing!\n";
        return;
    }
    file << "Stack\n";
    for (int i = 0; i <= top; i++) {
        file << data[i] << "\n";  // Сохраняем строки
    }
    file.close();
}

void Stack::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file for reading!\n";
        return;
    }
    string header;
    getline(file, header);
    if (header != "Stack") {
        cout << "Invalid file format!\n";
        return;
    }
    string value;
    while (getline(file, value)) {
        push(value);  // Добавляем строки в стек
    }
    file.close();
}