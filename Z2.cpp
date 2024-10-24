#include "HashTable.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void processFile(const string& filePath, const string& query) {
    HashTable mySet;
    ifstream file(filePath);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);

        string operation, element;
        ss >> operation >> element;

        if (operation == "SETADD") {
            mySet.insert(element, "true");
            cout << "Element " << element << " added to the set." << endl;
        }
        else if (operation == "SETDEL") {
            mySet.remove(element);
            cout << "Element " << element << " removed from the set." << endl;
        }
        else if (operation == "SET_AT") {
            if (mySet.get(element) == "true") {
                cout << "Element " << element << " is in the set." << endl;
            }
            else {
                cout << "Element " << element << " is not in the set." << endl;
            }
        }
        else {
            cerr << "Unknown operation: " << operation << endl;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cerr << "Usage: " << argv[0] << " --file <file_path> --query <query_type>" << endl;
        return 1;
    }

    string filePath = argv[2];
    string queryType = argv[4];

    if (queryType != "process") {
        cerr << "Unsupported query type: " << queryType << endl;
        return 1;
    }

    processFile(filePath, queryType);

    return 0;
}