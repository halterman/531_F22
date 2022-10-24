import java.util.Arrays;

public class Heapsort {
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

    public static void heapsort(int[] a) {
        buildMaxHeap(a);
        int heapSize = a.length;
        for (int i = a.length - 1; i > 0; i--) {
            int temp = a[0];
            a[0] = a[i];
            a[i] = temp;
            heapSize--;
            maxHeapify(a, heapSize, 0);
        }
    }

    public static void main(String[] args) {
        int[] vals = { 31, 41, 59, 26, 41, 58 };
        System.out.println(Arrays.toString(vals));
        heapsort(vals);
        System.out.println(Arrays.toString(vals));
    }
}
