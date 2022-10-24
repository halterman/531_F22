public class MaxHeap {
    private int size;
    private int maxSize;
    private int[] heap;

    public MaxHeap(int max) {
        heap = new int[max]; 
        maxSize = max;
        size = 0;
    }

    public MaxHeap(int max, int[] elements) {
        this(max);
        for (int i = 0; i < elements.length; i++) {
            insert(elements[i]);
        }
    }

    public void insert(int newValue) { 
        if (size < maxSize) {
            heap[size++] = newValue;
            int i = size - 1;
            while (i > 0 && heap[parent(i)] < heap[i]) {
                int temp = heap[parent(i)];
                heap[parent(i)] = heap[i];
                heap[i] = temp;
                i = parent(i);
            }
        } else {
            System.out.println("Heap overflow");
        } 
    }

    public int maximum() {
        return heap[0];
    }

    public int extractMaximum() { 
        if (size < 1) {
            System.out.println("Heap underflow");
            return 0;
        }
        int max = heap[0]; 
        heap[0] = heap[--size];
        maxHeapify(heap, size, 0);
        return max;
    }

    private static int parent(int i) {
        return (i - 1)/2;
    }

    private static int left(int i) {
        return 2*i + 1;
    }

    private static int right(int i) {
        return 2*i + 2;
    }

    private static void maxHeapify(int[] a, int heapSize, int i) {
        int lf = left(i), rt = right(i), largest;
        if (lf < heapSize && a[lf] > a[i]) {
            largest = lf;
        } else {
            largest = i;
        }
        if (rt < heapSize && a[rt] > a[largest]) {
            largest = rt;
        }
        if (largest != i) {
            int temp = a[i]; 
            a[i] = a[largest]; 
            a[largest] = temp;
            maxHeapify(a, heapSize, largest);
        }
    }

    private static void buildMaxHeap(int[] a) {
        for (int i = a.length/2 - 1; i >= 0; i--) {
            maxHeapify(a, a.length, i);
        }
    }

    public static void main(String[] args) {
        MaxHeap pq = new MaxHeap(10);
        boolean done = false;
        var scan = new java.util.Scanner(System.in);
        do {
            System.out.print("(I)nsert <n> (G)et (P)rint (Q)uit => ");
            switch (scan.next().charAt(0)) {
                case 'I', 'i' -> pq.insert(scan.nextInt());
                case 'G', 'g' -> System.out.println(pq.extractMaximum());
                case 'Q', 'q' -> done = true;
            }
        } while (!done);

    }
}
