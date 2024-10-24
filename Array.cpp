#include "Array.h"

Array::Array(int initialCapacity) {
    capacity = initialCapacity;
    size = 0;
    data = new string[capacity];
}

Array::~Array() {
    delete[] data;
}

void Array::add(int index, const string& value) {
    if (index < 0 || index > size) {
        cout << "Invalid index!\n";
        return;
    }
    if (size == capacity) {
        capacity *= 2;
        string* newData = new string[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    size++;
}

void Array::addToEnd(const string& value) {
    add(size, value);
}

string Array::get(int index) const {
    if (index < 0 || index >= size) {
        cout << "Invalid index!\n";
        return "";
    }
    return data[index];
}

void Array::remove(int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index!\n";
        return;
    }
    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
}

void Array::set(int index, const string& value) {
    if (index < 0 || index >= size) {
        cout << "Invalid index!\n";
        return;
    }
    data[index] = value;
}

int Array::length() const {
    return size;
}

void Array::print() const {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << "\n";
}

void Array::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file for writing!\n";
        return;
    }
    file << "Array\n";
    for (int i = 0; i < size; i++) {
        file << data[i] << "\n";
    }
    file.close();
}

void Array::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file for reading!\n";
        return;
    }
    string header;
    file >> header;
    if (header != "Array") {
        cout << "Invalid file format!\n";
        return;
    }
    string value;
    while (file >> value) {
        addToEnd(value);
    }
    file.close();
}