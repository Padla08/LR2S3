#include "HashTable.h"
#include <iostream>
#include <string>

using namespace std;

int lengthOfLongestSubstring(const string& s) {
    int n = s.length();
    if (n == 0) return 0;

    HashTable charIndexMap(n);  // Создаем хеш-таблицу с начальной емкостью n
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < n; ++end) {
        char currentChar = s[end];

        // Если символ уже встречался и его индекс больше или равен началу текущего окна
        string charStr(1, currentChar);  // Преобразуем символ в строку
        string indexStr = charIndexMap.get(charStr);
        int lastIndex = (indexStr.empty()) ? -1 : stoi(indexStr);

        if (lastIndex != -1 && lastIndex >= start) {
            // Сдвигаем начало окна на позицию после повторяющегося символа
            start = lastIndex + 1;
        }

        // Обновляем индекс текущего символа
        charIndexMap.insert(charStr, to_string(end));

        // Вычисляем текущую длину подстроки
        int currentLength = end - start + 1;
        maxLength = max(maxLength, currentLength);
    }

    return maxLength;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    int result = lengthOfLongestSubstring(input);
    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}