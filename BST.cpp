#include<iostream>
using namespace std;

struct Node {
    Node *left, *right;
    int data;
    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

class Binary {
public:
    Node *head;
    Binary() { head = nullptr; }

    void add(int data) {
        if (!head) head = new Node(data);
        else {
            Node *temp = head;
            while (true) {
                if (data > temp->data) {
                    if (!temp->right) {
                        temp->right = new Node(data);
                        break;
                    } else temp = temp->right;
                } else if (data < temp->data) {
                    if (!temp->left) {
                        temp->left = new Node(data);
                        break;
                    } else temp = temp->left;
                } else break;
            }
        }
    }

    Node* findMin(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    Node* deleteNode(Node* root, int data) {
        if (!root) return root;
        if (data < root->data) root->left = deleteNode(root->left, data);
        else if (data > root->data) root->right = deleteNode(root->right, data);
        else {
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    void remove(int data) { head = deleteNode(head, data); }

    void inorderTraversal(Node* node) {
        if (node) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    void printInOrder() { inorderTraversal(head); cout << endl; }
};

int main() {
    Binary B1;
    B1.add(12); B1.add(13); B1.add(10); B1.add(15); B1.add(7);
    B1.printInOrder();
    B1.remove(10);
    B1.printInOrder();
    return 0;
}
