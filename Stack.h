#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Stack {
private:
    string* data; 
    int top;
    int capacity;

public:
    Stack(int initialCapacity = 10);
    ~Stack();

    void push(const string& value);  
    string pop();  
    string peek() const; 
    bool isEmpty() const;
    void print() const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif