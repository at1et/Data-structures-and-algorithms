#include "TreeModule.h"  // Подключаем модуль с функциями бинарного дерева

int main() {
    setlocale(LC_ALL, "rus");

    // Создаем узлы дерева
    shared_ptr<TreeNode<int>> root = make_shared<TreeNode<int>>(1);
    root->left = make_shared<TreeNode<int>>(2);
    root->right = make_shared<TreeNode<int>>(3);
    root->left->left = make_shared<TreeNode<int>>(4);
    root->left->right = make_shared<TreeNode<int>>(5);


    // Проверка строгого бинарного дерева
    cout << "\nЯвляется ли дерево строгим? "
        << (isStrictBinaryTree(root) ? "Да" : "Нет") << endl;

    // Проверка завершенного бинарного дерева
    cout << "Является ли дерево законченным? "
        << (isCompleteBinaryTree(root) ? "Да" : "Нет") << endl;

    // Проверка совершенного бинарного дерева
    int depth = findDepth(root);
    cout << "Является ли дерево совершенным? "
        << (isPerfectBinaryTree(root, depth) ? "Да" : "Нет") << endl;

    // Смотрим содержимое одного из узлов (например, правого потомка корня)
    cout << "\nСодержимое правого потомка корня: "
        << root->right->data << endl;

    // Удаляем все узлы (shared_ptr автоматически очищает память)
    root.reset();

    return 0;
}
