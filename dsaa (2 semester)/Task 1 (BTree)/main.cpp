#include <iostream>
#include <memory>  // Для использования умных указателей

using namespace std;

template<typename T>
class TreeNode {
public:
    T data;  // Данные узла
    shared_ptr<TreeNode<T>> left;  // Указатель на левый дочерний узел
    shared_ptr<TreeNode<T>> right; // Указатель на правый дочерний узел

    // Конструктор
    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}

    // Деструктор (shared_ptr автоматически освободит память)
    ~TreeNode() {
        cout << "Удаление узла с данными: " << data << endl;
    }
};

int main() {
    setlocale(LC_ALL,"rus");
    // Создаем узлы дерева
    shared_ptr<TreeNode<int>> root = make_shared<TreeNode<int>>(1);
    root->left = make_shared<TreeNode<int>>(2);
    root->right = make_shared<TreeNode<int>>(3);
    root->left->left = make_shared<TreeNode<int>>(4);
    root->left->right = make_shared<TreeNode<int>>(5);

    // Визуализируем дерево 
    cout << "   " << root->data << endl;
    cout << "  / \\" << endl;
    cout << " " << root->left->data << "   " << root->right->data << endl;
    cout << "/ \\" << endl;
    cout << root->left->left->data << "   " << root->left->right->data << endl;

    // Посмотрим содержимое узла (например, правого потомка корня)
    cout << "Содержимое правого потомка  " << root->left->right->data << endl;

    // Удаляем все узлы (shared_ptr автоматически очищает память)
    root.reset();

    return 0;
}
