#include <iostream>
#include <algorithm>

using namespace std;

class Set {
public:
    void add(int element) {
        if (!contains(element)) {
            elements[size++] = element;
        }
    }
    // Метод для проверки наличия элемента в множестве
    bool contains(int element) const {
        for (size_t i = 0; i < size; ++i) {
            if (elements[i] == element) {
                return true;
            }
        }
        return false;
    }
    size_t getSize() const {
        return size;
    }
    const int* getElements() const {
        return elements;
    }

private:
    static const size_t MAX_SIZE = 100; // Максимальный размер множества
    int elements[MAX_SIZE]; // Массив для хранения элементов
    size_t size = 0; // Текущий размер множества
};
// Поиск двух множеств
pair<const Set*, const Set*> findMaxIntersection(const Set* sets, size_t numSets, size_t& maxIntersectionSize) {
    maxIntersectionSize = 0; // Инициализация максимального количества общих элементов
    const Set* maxSet1 = nullptr; // Первое множество с максимальным пересечением
    const Set* maxSet2 = nullptr; // Второе множество с максимальным пересечением
    // Перебираем все пары множеств
    for (size_t i = 0; i < numSets; ++i) {
        for (size_t j = i + 1; j < numSets; ++j) {
            const Set& set1 = sets[i];
            const Set& set2 = sets[j];

            size_t intersectionSize = 0; // Количество общих элементов
            // Проверяем каждый элемент первого множества на наличие во втором
            for (size_t k = 0; k < set1.getSize(); ++k) {
                if (set2.contains(set1.getElements()[k])) {
                    ++intersectionSize;
                }
            }
            // Если текущее пересечение больше максимального, обновляем максимальное
            if (intersectionSize > maxIntersectionSize) {
                maxIntersectionSize = intersectionSize;
                maxSet1 = &set1;
                maxSet2 = &set2;
            }
        }
    }
    return {maxSet1, maxSet2};
}
int main() {
    Set sets[4]; // Массив множеств

    sets[0].add(1);
    sets[0].add(2);
    sets[0].add(3);

    sets[1].add(2);
    sets[1].add(3);
    sets[1].add(4);

    sets[2].add(5);
    sets[2].add(6);

    sets[3].add(3);
    sets[3].add(4);
    sets[3].add(5);

    size_t maxIntersectionSize = 0; // Переменная для хранения максимума

    // Поиск двух с максимальным кол-вом
    auto [maxSet1, maxSet2] = findMaxIntersection(sets, 4, maxIntersectionSize);

    if (maxSet1 && maxSet2) {
        cout << "Множества с максимальным количеством общих элементов:\n";
        cout << "{";
        for (size_t i = 0; i < maxSet1->getSize(); ++i) {
            cout << maxSet1->getElements()[i];
            if (i < maxSet1->getSize() - 1) {
                cout << ", ";
            }
        }
        cout << "} и {";
        for (size_t i = 0; i < maxSet2->getSize(); ++i) {
            cout << maxSet2->getElements()[i];
            if (i < maxSet2->getSize() - 1) {
                cout << ", ";
            }
        }
        cout << "}, количество общих элементов: " << maxIntersectionSize << "\n";
    } else {
        cout << "Не удалось найти множества с общими элементами.\n";
    }

    return 0;
}