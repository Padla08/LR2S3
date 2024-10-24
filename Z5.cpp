#include <iostream>
#include <cmath>
#include "Queue.h"

using namespace std;

// Функция для поиска минимального значения в правом поддереве
TreeNode* findMin(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Функция для удаления вершины с заданным значением
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
        return nullptr;
    }

    // Если ключ меньше значения корня, идем влево
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }
    // Если ключ больше значения корня, идем вправо
    else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }
    // Если ключ равен значению корня, то это вершина для удаления
    else {
        // Случай 1: Нет детей или только один ребенок
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Случай 2: Два ребенка
        // Находим минимальное значение в правом поддереве
        TreeNode* temp = findMin(root->right);

        // Копируем значение минимального узла в текущий узел
        root->val = temp->val;

        // Удаляем минимальный узел в правом поддереве
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

// Вспомогательная функция для вывода дерева (обход в порядке in-order)
void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

// Функция для вывода дерева в виде уровней
void printTreeLevels(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    Queue q;
    q.push(root);
    int level = 0;
    bool hasNodes = true;

    while (hasNodes) {
        hasNodes = false;
        int levelSize = pow(2, level);
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.pop();
            if (node != nullptr) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
                if (node->left || node->right) {
                    hasNodes = true;
                }
            } else {
                cout << "N ";
                q.push(nullptr);
                q.push(nullptr);
            }
        }
        cout << endl;
        level++;
    }
}

// Функция для перестроения дерева без нулевых узлов
TreeNode* rebuildTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    // Создаем очередь для обхода дерева
    Queue q;
    q.push(root);

    // Создаем новый корень
    TreeNode* newRoot = nullptr;
    TreeNode* current = nullptr;

    while (!q.isEmpty()) {
        TreeNode* node = q.pop();
        if (node != nullptr) {
            // Создаем новый узел
            TreeNode* newNode = new TreeNode(node->val);

            // Если новый корень еще не создан, делаем этот узел корнем
            if (newRoot == nullptr) {
                newRoot = newNode;
                current = newRoot;
            } else {
                // Иначе добавляем узел к текущему узлу
                if (current->left == nullptr) {
                    current->left = newNode;
                } else {
                    current->right = newNode;
                    current = current->left;
                }
            }

            // Добавляем детей в очередь
            q.push(node->left);
            q.push(node->right);
        }
    }

    return newRoot;
}

int main() {
    // Пример создания дерева
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    cout << "Исходное дерево: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Дерево в виде уровней:" << endl;
    printTreeLevels(root);
    cout << endl;

    // Удаляем вершину со значением 3
    root = deleteNode(root, 3);

    cout << "Дерево после удаления вершины со значением 3: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Дерево в виде уровней после удаления:" << endl;
    printTreeLevels(root);
    cout << endl;

    // Перестраиваем дерево без нулевых узлов
    root = rebuildTree(root);

    cout << "Дерево после перестроения:" << endl;
    printTreeLevels(root);
    cout << endl;

    return 0;
}