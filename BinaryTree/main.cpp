#include <iostream>
#include <vector>
#include <iomanip>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class DegenerateBinaryTree {
public:
    Node* root;

    DegenerateBinaryTree() : root(nullptr) {}

    // Вставка элемента
    void insert(int value) {
        root = insertRec(root, value);
    }

    // Минимальное значение
    int minValue() {
        if (root == nullptr) throw std::runtime_error("Дерево пустое");
        return minValueRec(root);
    }

    // Максимальное значение
    int maxValue() {
        if (root == nullptr) throw std::runtime_error("Дерево пустое");
        return maxValueRec(root);
    }

    // Количество элементов
    int count() {
        return countRec(root);
    }

    // Сумма элементов
    int sum() {
        return sumRec(root);
    }

    // Среднее арифметическое
    double avg() {
        int total = count();
        if (total == 0) return 0.0;
        return static_cast<double>(sum()) / total;
    }

    // Очистка дерева
    void clear() {
        clearRec(root);
        root = nullptr;
    }

    // Удаление элемента
    void erase(int value) {
        root = eraseRec(root, value);
    }

    // Глубина дерева
    int depth() {
        return depthRec(root);
    }

    // Балансировка дерева
 void balance() {
    std::vector<int> values;
    storeInOrder(root, values); // Сохраняем элементы в отсортированном порядке
    clear(); // Очищаем текущее дерево
    balanceRec(values, 0, values.size() - 1); // Создаем сбалансированное дерево
}

void balanceRec(const std::vector<int>& values, int start, int end) {
    if (start > end) return;

    int mid = (start + end) / 2; // Находим средний элемент
    insert(values[mid]); // Вставляем средний элемент в дерево

    // Рекурсивно балансируем левую и правую части
    balanceRec(values, start, mid - 1); // Левое поддерево
    balanceRec(values, mid + 1, end); // Правое поддерево
}


    // Обход дерева (инфиксный обход)
    void inorder() {
        inorderRec(root);
        std::cout << std::endl;
    }

    // Вывод дерева
    void printTree() {
        printTreeRec(root, 0);
    }

private:
    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        node->right = insertRec(node->right, value); // Вырожденное дерево
        return node;
    }

    int minValueRec(Node* node) {
        if (node->left == nullptr) {
            return node->data;
        }
        return minValueRec(node->left);
    }

    int maxValueRec(Node* node) {
        if (node->right == nullptr) {
            return node->data;
        }
        return maxValueRec(node->right);
    }

    int countRec(Node* node) {
        if (node == nullptr) return 0;
        return 1 + countRec(node->left) + countRec(node->right);
    }

    int sumRec(Node* node) {
        if (node == nullptr) return 0;
        return node->data + sumRec(node->left) + sumRec(node->right);
    }

    void clearRec(Node* node) {
        if (node != nullptr) {
            clearRec(node->left);
            clearRec(node->right);
            delete node;
        }
    }

    Node* eraseRec(Node* node, int value) {
        if (node == nullptr) return nullptr;
        if (value < node->data) {
            node->left = eraseRec(node->left, value);
        } else if (value > node->data) {
            node->right = eraseRec(node->right, value);
        } else {
            // Узел найден
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Узел с двумя потомками
            int temp = minValueRec(node->right); // Получаем минимальное значение из правого поддерева
            node->data = temp; // Заменяем значение узла
            node->right = eraseRec(node->right, temp); // Удаляем узел с минимальным значением
        }
        return node;
    }

    int depthRec(Node* node) {
        if (node == nullptr) return 0;
        return 1 + std::max(depthRec(node->left), depthRec(node->right));
    }

    void storeInOrder(Node* node, std::vector<int>& values) {
        if (node != nullptr) {
            storeInOrder(node->left, values);
            values.push_back(node->data);
            storeInOrder(node->right, values);
        }
    }



    void inorderRec(Node* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            std::cout << node->data << " ";
            inorderRec(node->right);
        }
    }

    void printTreeRec(Node* node, int space) {
        if (node == nullptr) return;
        space += 10;
        printTreeRec(node->right, space);
        std::cout << std::endl;
        std::cout << std::setw(space) << node->data << std::endl;
        printTreeRec(node->left, space);
    }
};

int main() {
    DegenerateBinaryTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(12);

    std::cout << "Элементы дерева (инфиксный обход): ";
    tree.inorder(); // Вывод: 1 2 3 4

    std::cout << "Минимальное значение: " << tree.minValue() << std::endl;
    std::cout << "Максимальное значение: " << tree.maxValue() << std::endl;
    std::cout << "Количество элементов: " << tree.count() << std::endl;
    std::cout << "Сумма элементов: " << tree.sum() << std::endl;
    std::cout << "Среднее арифметическое: " << tree.avg() << std::endl;

    std::cout << "Глубина дерева: " << tree.depth() << std::endl;

    std::cout << "Дерево до балансировки:" << std::endl;
    tree.printTree();

    tree.balance();

    std::cout << "Дерево после балансировки:" << std::endl;
    tree.printTree();

    tree.clear();
    std::cout << "Дерево очищено. Количество элементов: " << tree.count() << std::endl;

    return 0;
}
