using namespace std;
#include <iostream>
#include <string>

/**
 * Defines a node in a Linked List.
 *
 * Only supports integer values.
 */
class Node {
  public:
    int value;
    Node* next;

    Node(int value, Node* next=NULL) {
      this->value = value;
      this->next = next;
    }
};

/**
 * Defines a sorted, singly Linked List.
 *
 * Any values added will be added in order.
 * This class also provides search and deleteion functionality.
 */
class List {
  public:
    Node* root;

    List(Node* root=NULL) {
      this->root = root;
    }

    void add(int value) {
      Node* node = new Node(value);

      // if the list is empty, create a new root.
      // Otherwise, call private `_add` method.
      if (!this->root) {
        this->root = node;
      } else {
        this->_add(this->root, node);
      }
    }

    void find(int value) {
      string isInList = "is NOT";

      if (this->_find(this->root, value)) {
        isInList = "is";
      }

      cout << "Value " << value << " " << isInList << " in list" << endl;
    }

    void print() {
      this->_print(this->root);
    }

  private:
    void _add(Node* root, Node* node) {
      // check if `next` is null (end of list)
      // check if `node->value` falls between `root` and `root-next` values.
      if (root->value < node->value && (
          !root->next || root->next->value > node->value)) {
        // preform an addition between two existing nodes or at the end of list.
        Node* oldNext = root->next;
        root->next = node;
        node->next = oldNext;
      } else {
        this->_add(root->next, node);
      }
    }

    bool _find(Node* root, int value) {
      if (!root) {
        return false;
      } else if (root->value == value) {
        return true;
      } else {
        return this->_find(root->next, value);
      }
    }

    void _print(Node* root) {
      if (root) {
        cout << root->value << endl;
        this->_print(root->next);
      }
    }
};

int main() {

  List* list = new List();

  list->add(1);
  list->add(3);
  list->add(2);

  list->print();
  list->find(3);
  list->find(4);

  return 0;
};
