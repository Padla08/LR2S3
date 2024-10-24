#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Array {
private:
    string* data;
    int capacity;
    int size;

public:
    Array(int initialCapacity = 10);
    ~Array();

    void add(int index, const string& value);
    void addToEnd(const string& value);
    string get(int index) const;
    void remove(int index);
    void set(int index, const string& value);
    int length() const;
    void print() const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif // ARRAY_H