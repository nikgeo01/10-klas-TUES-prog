public class MyDeque {
    private Integer[] data;
    private int size;
    private int capacity;
    private static final int INITIAL_CAPACITY = 10;

    public MyDeque() {
        this.capacity = INITIAL_CAPACITY;
        this.data = new Integer[capacity];
        this.size = 0;
    }

    private void resize() {
        capacity *= 2;
        Integer[] newData = new Integer[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        data = newData;
    }

    public void addFront(Integer elementToAdd) {
        if (size == capacity) {
            resize();
        }
        for (int i = size; i > 0; i--) {
            data[i] = data[i - 1];
        }
        data[0] = elementToAdd;
        size++;
    }

    public void addBack(Integer elementToAdd) {
        if (size == capacity) {
            resize();
        }
        data[size] = elementToAdd;
        size++;
    }

    public Integer removeFront() {
        if (size == 0) {
            return null;
        }
        Integer front = data[0];
        for (int i = 1; i < size; i++) {
            data[i - 1] = data[i];
        }
        data[size - 1] = null;
        size--;
        return front;
    }

    public Integer removeBack() {
        if (size == 0) {
            return null;
        }
        Integer back = data[size - 1];
        data[size - 1] = null;
        size--;
        return back;
    }

    public Integer peekFront() {
        if (size == 0) {
            return null;
        }
        return data[0];
    }

    public Integer peekBack() {
        if (size == 0) {
            return null;
        }
        return data[size - 1];
    }

    public void printDeque() {
        for (int i = 0; i < size; i++) {
            System.out.print(data[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        MyDeque deque = new MyDeque();

        System.out.println("Adding elements to the back:");
        deque.addBack(10);
        deque.addBack(20);
        deque.addBack(30);
        deque.printDeque();

        System.out.println("\nAdding elements to the front:");
        deque.addFront(5);
        deque.addFront(2);
        deque.printDeque();

        System.out.println("\nPeeking front and back elements:");
        System.out.println("Front element: " + deque.peekFront());
        System.out.println("Back element: " + deque.peekBack());

        System.out.println("\nRemoving front element: " + deque.removeFront());
        deque.printDeque();

        System.out.println("\nRemoving back element: " + deque.removeBack());
        deque.printDeque();
    }
}
