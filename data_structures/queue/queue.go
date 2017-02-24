package main

import "fmt"

type Node struct {
  value int
  next *Node
}

func NewNode(value int, next *Node) *Node {
  node := new(Node)
  node.value = value
  node.next = next

  return node
}

type Queue struct {
  head *Node
  tail *Node
}

func NewQueue(head *Node, tail *Node) *Queue {
  queue := new(Queue)
  queue.head = head
  queue.tail = tail

  return queue
}

func (q *Queue) peek() int {
  if (q.head != nil) {
    return q.head.value
  } else {
    return -1
  }
}

func (q *Queue) pop() int {
  temp := q.head
  q.head = q.head.next

  value := temp.value

  return value
}

func (q *Queue) push(value int) {
  node := NewNode(value, nil)

  // if head has not been set
  if (q.head == nil) {
    q.head = node
  }

  // if tail has been set, set it's next to the new node
  if (q.tail != nil) {
    q.tail.next = node
  }

  q.tail = node
}

func (q *Queue) printQueue() {
  temp := q.head

  for temp != nil {
    fmt.Println(temp.value)
    temp = temp.next
  }
}

func main() {
  queue := NewQueue(nil, nil)

  queue.push(4)
  queue.push(2)
  queue.push(42)

  queue.printQueue()

  fmt.Println(queue.pop())
  fmt.Println(queue.pop())
  fmt.Println(queue.peek())
  fmt.Println(queue.pop())
  fmt.Println(queue.peek())
}
