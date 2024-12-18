#include <iostream>
#include <memory>
#include <cstdlib>

struct TreapNode 
{
    int key;
    int priority;
    std::unique_ptr<TreapNode> left;
    std::unique_ptr<TreapNode> right;

    TreapNode(int k) : key(k), priority(rand()), left(nullptr), right(nullptr) {}
};

struct Treap 
{
private:
    std::unique_ptr<TreapNode> root;

    std::pair<std::unique_ptr<TreapNode>, std::unique_ptr<TreapNode>> split(std::unique_ptr<TreapNode> node, int key) {
        if (!node) return {nullptr, nullptr};
        if (key < node->key) {
            auto splitted = split(std::move(node->left), key);
            node->left = std::move(splitted.second);
            return {std::move(splitted.first), std::move(node)};
        } else {
            auto splitted = split(std::move(node->right), key);
            node->right = std::move(splitted.first);
            return {std::move(node), std::move(splitted.second)};
        }
    }

    std::unique_ptr<TreapNode> merge(std::unique_ptr<TreapNode> left, std::unique_ptr<TreapNode> right) {
        if (!left) return right;
        if (!right) return left;
        if (left->priority > right->priority) {
            left->right = merge(std::move(left->right), std::move(right));
            return left;
        } else {
            right->left = merge(std::move(left), std::move(right->left));
            return right;
        }
    }

public:
    Treap() : root(nullptr) {}

    void insert(int key) {
        auto node = std::make_unique<TreapNode>(key);
        auto splitted = split(std::move(root), key);
        root = merge(std::move(splitted.first), merge(std::move(node), std::move(splitted.second)));
    }

    bool search(int key) {
        TreapNode* curr = root.get();
        while (curr) {
            if (curr->key == key) return true;
            curr = (key < curr->key) ? curr->left.get() : curr->right.get();
        }
        return false;
    }

    void remove(int key) {
        auto splitted1 = split(std::move(root), key);
        auto splitted2 = split(std::move(splitted1.second), key + 1);
        root = merge(std::move(splitted1.first), std::move(splitted2.second));
    }

    void clear() {
        root.reset();
    }
};

int main() {
    Treap treap;
    treap.insert(10);
    treap.insert(20);
    treap.insert(15);

    std::cout << "Поиск 15: " << (treap.search(15) ? "Найден" : "Не найден") << std::endl; // Найден
    treap.remove(15);
    std::cout << "Поиск 15 после удаления: " << (treap.search(15) ? "Найден" : "Не найден") << std::endl; // Не найден

    treap.clear(); // Очистка памяти
    return 0;
}
