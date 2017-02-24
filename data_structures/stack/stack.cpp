using namespace std;
#include <iostream>

/**
 * Defines a node in a Stack.
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
 * Defines a stack data structure.
 *
 * Time Complexity: O(1)
 */
class Stack {

  public:
    Stack() {
      this->root = NULL;
    }

    int peek() {
      return this->root ? this->root->value : -1;
    }

    int pop() {
      if (!this->root) {
        return -1;
      }

      int buffer = this->root->value;
      Node* temp = this->root;
      this->root = this->root->next;

      delete temp;

      return buffer;
    }

    void push(int value) {
      this->root = new Node(value, this->root);
    }

  private:
    Node* root;

};

int main() {
  Stack* stack = new Stack();
  stack->push(3);
  stack->push(2);
  stack->push(1);

  cout << stack->pop() << endl;
  cout << stack->pop() << endl;
  cout << stack->peek() << endl;
  cout << stack->pop() << endl;
  cout << stack->peek() << endl;

  delete stack;

  return 0;
};
