using namespace std;
#include <iostream>

class Node {
  public:
    int value;
    Node *left;
    Node *right;

    Node(int value, Node *left=NULL, Node *right=NULL) {
      this->value = value;
      this->left = left;
      this->right = right;
    }
};

class Tree {
  public:
    Tree() {
      this->root = NULL;
    }
    void insert(int value) {
      if (this->root == NULL) {
        this->root = new Node(value, NULL, NULL);
      } else {
        this->_insert(this->root, value);
      }
    }
    void print() {
      this->_print(this->root);
    }

  private:
    Node *root;
    void _insert(Node *root, int value) {
      if (value < root->value) {
        if (root->left == NULL) {
          root->left = new Node(value, NULL, NULL);
        } else {
          this->_insert(root->left, value);
        }
      } else {
        if (root->right == NULL) {
          root->right = new Node(value, NULL, NULL);
        } else {
          this->_insert(root->right, value);
        }
      }
    }
    void _print(Node *root) {
      if (root) {
        this->_print(root->left);
        cout << root->value << endl;
        this->_print(root->right);
      }
    }
};

int main() {
  Tree *tree = new Tree();
  tree->insert(4);
  tree->insert(2);
  tree->insert(1);
  tree->insert(3);

  tree->insert(6);
  tree->insert(5);
  tree->insert(7);

  tree->print();

  return 0;
};
