#include <iostream>
#include <algorithm>
using namespace std;

class AVLTree {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;
        int height;

        Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    int getHeight(Node* node) {
        return (node == nullptr) ? 0 : node->height;
    }

    int getBalanceFactor(Node* node) {
        return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
    }

    int updateHeight(Node* node) {
        return (node == nullptr) ? 0 : 1 + std::max(getHeight(node->left), getHeight(node->right));
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = updateHeight(y);
        x->height = updateHeight(x);

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = updateHeight(x);
        y->height = updateHeight(y);

        return y;
    }

    Node* insertNode(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insertNode(node->left, key);
        } else if (key > node->key) {
            node->right = insertNode(node->right, key);
        } else {
            // Duplicate keys are not allowed
            return node;
        }

        // Update height of the current node
        node->height = updateHeight(node);

        // Get the balance factor to check if this node became unbalanced
        int balance = getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && key < node->left->key) {
            return rotateRight(node);
        }

        // Right Right Case
        if (balance < -1 && key > node->right->key) {
            return rotateLeft(node);
        }

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr || root->right == nullptr) {
                Node* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp;
                }

                delete temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (root == nullptr) {
            return root;
        }

        root->height = updateHeight(root);

        int balance = getBalanceFactor(root);

        // Left Left Case
        if (balance > 1 && getBalanceFactor(root->left) >= 0) {
            return rotateRight(root);
        }

        // Left Right Case
        if (balance > 1 && getBalanceFactor(root->left) < 0) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        // Right Right Case
        if (balance < -1 && getBalanceFactor(root->right) <= 0) {
            return rotateLeft(root);
        }

        // Right Left Case
        if (balance < -1 && getBalanceFactor(root->right) > 0) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->key << " ";
            inOrderTraversal(node->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insertNode(root, key);
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }

    void printInOrder() {
        cout << "In-order traversal of the AVL tree: ";
        inOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    AVLTree avlTree;

    // Insert nodes
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(40);
    avlTree.insert(50);
    avlTree.insert(25);

    avlTree.printInOrder();

    // Remove nodes
    avlTree.remove(30);
    avlTree.remove(40);

    avlTree.printInOrder();

    return 0;
}
