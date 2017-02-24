using namespace std;
#include <iostream>

/**
 * Defines a node in a Queue.
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
 * Defines a linked list based queue data structure.
 *
 * Time complexity: O(1)
 */
class Queue {
  public:
    Queue() {
      this->head = NULL;
      this->tail = NULL;
    }

    int peek() {
      return this->head ? this->head->value : -1;
    }

    int pop() {
      Node* temp = this->head;
      this->head = this->head->next;

      int buffer = temp->value;
      delete temp;

      return buffer;
    }

    void push(int value) {
      Node* node = new Node(value);

      // if head has not been set yet, set it.
      if (!this->head) {
        this->head = node;
      }

      // if tail has been set, set it's next to the new node
      if (this->tail) {
        this->tail->next = node;
      }

      this->tail = node;
    }

  private:
    Node* head;
    Node* tail;
};

int main() {
  Queue queue;
  queue.push(1);
  queue.push(2);
  queue.push(3);
  queue.push(4);

  cout << queue.pop() << endl;
  cout << queue.pop() << endl;
  cout << queue.pop() << endl;
  cout << queue.peek() << endl;
  cout << queue.pop() << endl;
  cout << queue.peek() << endl;
  return 0;
};
