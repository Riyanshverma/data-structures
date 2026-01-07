#include <iostream>
#include <vector>

class MultiwayTree {
private:
    struct Node {
        int data;
        std::vector<Node*> children;

        Node(int value) : data(value) {}
    };

    Node* root;

    void destroyTree(Node* node) {
        if (node != nullptr) {
            for (Node* child : node->children) {
                destroyTree(child);
            }
            delete node;
        }
    }

    void printTree(Node* node, int depth = 0) const {
        if (node != nullptr) {
            std::cout << std::string(2 * depth, ' ') << node->data << std::endl;
            for (Node* child : node->children) {
                printTree(child, depth + 1);
            }
        }
    }

    Node* findNode(Node* node, int value) const {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->data == value) {
            return node;
        }

        for (Node* child : node->children) {
            Node* found = findNode(child, value);
            if (found != nullptr) {
                return found;
            }
        }

        return nullptr;
    }

public:
    MultiwayTree() : root(nullptr) {}

    ~MultiwayTree() {
        destroyTree(root);
    }

    void insert(int parentValue, int childValue) {
        if (root == nullptr) {
            root = new Node(parentValue);
        }

        Node* parentNode = findNode(root, parentValue);
        if (parentNode != nullptr) {
            parentNode->children.push_back(new Node(childValue));
        } else {
            std::cerr << "Parent not found. Unable to insert." << std::endl;
        }
    }

    void print() const {
        std::cout << "Multiway Tree:" << std::endl;
        printTree(root);
    }
};

int main() {
    MultiwayTree mTree;

    mTree.insert(1, 2);
    mTree.insert(1, 3);
    mTree.insert(2, 4);
    mTree.insert(2, 5);
    mTree.insert(3, 6);
    mTree.insert(4, 7);
    mTree.insert(4, 8);
    mTree.insert(5, 9);
    mTree.insert(6, 10);

    mTree.print();

    return 0;
}
