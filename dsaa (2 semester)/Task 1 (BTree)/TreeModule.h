#pragma once
#ifndef TREEMODULE_H
#define TREEMODULE_H

#include <iostream>
#include <memory>
#include <queue>

using namespace std;

// Шаблонный класс для узла бинарного дерева
template<typename T>
class TreeNode {
public:
    T data;
    shared_ptr<TreeNode<T>> left;
    shared_ptr<TreeNode<T>> right;

    // Конструктор
    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}

    // Деструктор 
    ~TreeNode() {
        cout << "Удаление узла с данными: " << data << endl;
    }

    void NLR(TreeNode<T>* node)
    {
        if (node != NULL) {
            std::cout << node->Data << "\n";
            NLR(node->left);
            NLR(node->right);
        }
    }
};

// Функция для проверки, является ли дерево строгим (Strict Binary Tree)
template<typename T>
bool isStrictBinaryTree(shared_ptr<TreeNode<T>> node) {
    if (!node) return true;

    if ((node->left && !node->right) || (!node->left && node->right)) {
        return false; // Узел имеет только одного потомка
    }

    return isStrictBinaryTree(node->left) && isStrictBinaryTree(node->right);
}

// Функция для проверки, является ли дерево законченным (Complete Binary Tree)
template<typename T>
bool isCompleteBinaryTree(shared_ptr<TreeNode<T>> root) {
    if (!root) return true;
    //shared_ptr разобраться
    queue<shared_ptr<TreeNode<T>>> q;
    q.push(root);
    bool flag = false;

    while (!q.empty()) {
        auto node = q.front();
        q.pop();

        // Если узел имеет левый дочерний узел
        if (node->left) {
            if (flag) return false;  // Если раньше был замечен узел без двух потомков
            q.push(node->left);
        }
        else {
            flag = true;  // Если узел не имеет левого потомка, отмечаем это
        }

        // Если узел имеет правый дочерний узел
        if (node->right) {
            if (flag) return false;  // Если раньше был замечен узел без двух потомков
            q.push(node->right);
        }
        else {
            flag = true;  // Если узел не имеет правого потомка, отмечаем это
        }
    }
    return true;
}

// Функция для проверки, является ли дерево совершенным (Perfect Binary Tree)
template<typename T>
bool isPerfectBinaryTree(shared_ptr<TreeNode<T>> root, int depth, int level = 0) {
    if (!root) return true;

    // Проверяем, если это листовой узел
    if (!root->left && !root->right) {
        return depth == level + 1;
    }

    // Если узел имеет только одного потомка, это не совершенное дерево
    if (!root->left || !root->right) {
        return false;
    }

    // Рекурсивно проверяем левое и правое поддеревья
    return isPerfectBinaryTree(root->left, depth, level + 1) &&
        isPerfectBinaryTree(root->right, depth, level + 1);
}

// Функция для нахождения глубины дерева (необходима для проверки совершенного дерева)
template<typename T>
int findDepth(shared_ptr<TreeNode<T>> node) {
    int depth = 0;
    while (node) {
        depth++;
        node = node->left; // исправить
    }
    return depth;
}

#endif // TREEMODULE_H
