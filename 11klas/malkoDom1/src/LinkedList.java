import java.util.Iterator;

public class LinkedList implements java.lang.Iterable<Integer> {
    private Node head;
    private Node tail;
    private int size;

    public LinkedList() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    public LinkedList(int value) {
        Node newNode = new Node(value);
        this.head = newNode;
        this.tail = newNode;
        newNode.next = newNode;
        newNode.prev = newNode;
        this.size = 1;
    }

    private class Node {
        private int value;
        private Node next;
        private Node prev;

        public Node(int value) {
            this.value = value;
            this.next = null;
            this.prev = null;
        }

        public int getValue() {
            return value;
        }

        public void setValue(int value) {
            this.value = value;
        }
    }

    public void add(int index, int value) {
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException();
        }

        Node newNode = new Node(value);

        if (size == 0) {
            head = newNode;
            tail = newNode;
            newNode.next = newNode;
            newNode.prev = newNode;
        } else if (index == 0) {
            addFirst(value);
            return;
        } else if (index == size) {
            addLast(value);
            return;
        } else {
            Node current = head;
            for (int i = 0; i < index; i++) {
                current = current.next;
            }
            Node previous = current.prev;
            previous.next = newNode;
            newNode.prev = previous;
            newNode.next = current;
            current.prev = newNode;
        }
        size++;
    }

    public void addLast(int value) {
        Node newNode = new Node(value);
        if (size == 0) {
            head = newNode;
            tail = newNode;
            newNode.next = newNode;
            newNode.prev = newNode;
        } else {
            newNode.prev = tail;
            newNode.next = head;
            tail.next = newNode;
            head.prev = newNode;
            tail = newNode;
        }
        size++;
    }


    public void addFirst(int value) {
        if (size == 0) {
            addLast(value);
            return;
        }
        Node newNode = new Node(value);
        newNode.next = head;
        newNode.prev = tail;
        head.prev = newNode;
        tail.next = newNode;
        head = newNode;
        size++;
    }

    public int poll(int index) {
        if (index < 0 || index >= size) {
            throw new java.lang.IndexOutOfBoundsException();
        }

        Node removedNode;

        if (size == 1) {
            removedNode = head;
            head = null;
            tail = null;
        } else if (index == 0) {
            removedNode = head;
            head = head.next;
            head.prev = tail;
            tail.next = head;
        } else if (index == size - 1) {
            removedNode = tail;
            tail = tail.prev;
            tail.next = head;
            head.prev = tail;
        } else {
            removedNode = head;
            for (int i = 0; i < index; i++) {
                removedNode = removedNode.next;
            }
            Node previous = removedNode.prev;
            Node next = removedNode.next;
            previous.next = next;
            next.prev = previous;
        }
        size--;
        return removedNode.value;
    }

    public int pollLast() {
        return poll(size - 1);
    }

    public int pollFirst() {
        return poll(0);
    }

    public int get(int index) {
        if (index < 0 || index >= size) {
            throw new java.lang.IndexOutOfBoundsException();
        }

        Node current = head;
        for (int i = 0; i < index; i++) {
            current = current.next;
        }
        return current.value;
    }

    public int getLast() {
        if (tail == null) {
            throw new java.util.NoSuchElementException();
        }
        return tail.value;
    }

    public int getFirst() {
        if (head == null) {
            throw new java.util.NoSuchElementException();
        }
        return head.value;
    }

    public int indexOf(int value) {
        Node current = head;
        for (int i = 0; i < size; i++) {
            if (current.value == value) {
                return i;
            }
            current = current.next;
        }
        return -1;
    }

    public int lastIndexOf(int value) {
        Node current = tail;
        for (int i = size - 1; i >= 0; i--) {
            if (current.value == value) {
                return i;
            }
            current = current.prev;
        }
        return -1;
    }

    public boolean contains(int value) {
        return indexOf(value) != -1;
    }

    public int size() {
        return size;
    }

    public Iterator<Integer> iterator() {
        return new OddIterator();
    }

    private class OddIterator implements Iterator<Integer> {
        private Node current;
        private int traversed;

        public OddIterator() {
            current = head;
            traversed = 0;
            advanceToNextOdd();
        }

        private void advanceToNextOdd() {
            while (current != null && traversed < size && current.value % 2 == 0) {
                current = current.next;
                traversed++;
                if (current == head) {
                    break;
                }
            }
            if (traversed >= size || current.value % 2 == 0) {
                current = null;
            }
        }

        public boolean hasNext() {
            return current != null && traversed < size;
        }

        public Integer next() {
            if (!hasNext()) {
                throw new java.util.NoSuchElementException();
            }
            int value = current.value;
            current = current.next;
            traversed++;
            advanceToNextOdd();
            return value;
        }
    }
}
