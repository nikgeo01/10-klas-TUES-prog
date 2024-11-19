import java.util.*;

public class Vector implements Iterable<Integer> {
    private int[] data;
    private int size;
    private static final int INITIAL_CAPACITY = 5;

    public Vector() {
        this.data = new int[INITIAL_CAPACITY];
        this.size = 0;
    }

    public Vector(int value) {
        this();
        pushBack(value);
    }

    public void pushBack(int value) {
        ensureCapacity(size + 1);
        data[size++] = value;
    }

    public void insert(int index, int value) {
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException();
        }
        ensureCapacity(size + 1);
        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }

    public int pop() {
        if (size == 0) {
            throw new NoSuchElementException();
        }
        return data[--size];
    }

    public int remove(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException();
        }
        int removedValue = data[index];
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
        return removedValue;
    }

    public int at(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException();
        }
        return data[index];
    }

    public boolean contains(int value) {
        for (int i = 0; i < size; i++) {
            if (data[i] == value) {
                return true;
            }
        }
        return false;
    }

    public int size() {
        return size;
    }

    private void ensureCapacity(int minCapacity) {
        if (minCapacity > data.length) {
            int newCapacity = data.length * 2;
            if (newCapacity < minCapacity) {
                newCapacity = minCapacity;
            }
            int[] newData = new int[newCapacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            data = newData;
        }
    }

    public java.util.Iterator<Integer> iterator() {
        return new EvenIterator();
    }

    private class EvenIterator implements java.util.Iterator<Integer> {
        private int currentIndex;

        public EvenIterator() {
            currentIndex = 0;
            advanceToNextEven();
        }

        private void advanceToNextEven() {
            while (currentIndex < size && data[currentIndex] % 2 != 0) {
                currentIndex++;
            }
        }

        public boolean hasNext() {
            return currentIndex < size;
        }

        public Integer next() {
            if (!hasNext()) {
                throw new java.util.NoSuchElementException();
            }
            int value = data[currentIndex];
            currentIndex++;
            advanceToNextEven();
            return value;
        }
    }
}
