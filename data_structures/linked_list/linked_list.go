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

type List struct {
  root *Node
}

func (l *List) add(value int) {
  node := NewNode(value, nil)

  if (l.root == nil) {
    l.root = node
  } else {
    l._add(l.root, node)
  }
}

func (l *List) find(value int) {
  isInList := "is NOT"

  if (l._find(l.root, value)) {
    isInList = "is"
  }

  fmt.Println("Value", value, isInList, "in list")
}

func (l *List) print() {
  l._print(l.root)
}

func (l *List) _add(root *Node, node *Node) {
  if (root.value < node.value &&
      (root.next == nil || root.next.value > node.value)) {
    temp := root.next
    root.next = node
    node.next = temp
  } else {
    l._add(root.next, node)
  }
}

func (l *List) _find(root *Node, value int) bool {
  if (root == nil) {
    return false
  } else if (root.value == value) {
    return true
  } else {
    return l._find(root.next, value)
  }
}

func (l *List) _print(root *Node) {
  if (root != nil) {
    fmt.Println(root.value)
    l._print(root.next)
  }
}

func main() {
  list := List{nil}

  list.add(1)
  list.add(2)
  list.add(3)
  list.print()

  list.find(3)
  list.find(4)
}
