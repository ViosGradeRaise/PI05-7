#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    // Рекурсивный метод подсчета листьев
    int countLeaves(TreeNode* root) {
        // Базовый случай: пустое дерево
        if (root == nullptr) {
            return 0;
        }
        
        // Если узел является листом (нет детей)
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        
        // Рекурсивно считаем листья в левом и правом поддереве
        return countLeaves(root->left) + countLeaves(root->right);
    }
};

int main() {
    // Создаем дерево:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    BinaryTree tree;
    cout << "Количество листьев (рекурсия): " << tree.countLeaves(root) << endl;
    // Вывод: 3
    
    return 0;
}
