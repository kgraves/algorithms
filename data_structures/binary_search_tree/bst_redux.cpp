using namespace std;
#include <iostream>

class Node {
  public:
    int value;
    Node* left;
    Node* right;

    Node(int value, Node* left=NULL, Node* right=NULL) {
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
      if (!this->root) {
        this->root = new Node(value, NULL, NULL);
      } else {
        this->_insert(&this->root, value);
      }
    }

    void printInOrder() {
      this->_printInOrder(this->root);
    }

  private:
    Node* root;

    void _insert(Node** root, int value) {
      // if root is null, create and append a new node.
      if (!*root) {
        *root = new Node(value);
      } else {
        // figure out which side to append, and recurse.
        if (value < (*root)->value) {
          this->_insert(&(*root)->left, value);
        } else {
          this->_insert(&(*root)->right, value);
        }
      }
    }

    void _printInOrder(Node* root) {
      if (root) {
        this->_printInOrder(root->left);
        cout << root->value << endl;
        this->_printInOrder(root->right);
      }
    }
};

int main() {
  Tree* tree = new Tree();
  tree->insert(4);
  tree->insert(2);
  tree->insert(1);
  tree->insert(3);
  tree->insert(6);
  tree->insert(5);
  tree->insert(7);

  tree->printInOrder();

  return 0;
};
