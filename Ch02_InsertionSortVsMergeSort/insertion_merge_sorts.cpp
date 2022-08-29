// Ch02_Insertion_Merge_Sorts.cpp
// Created 8/23/2020 3:23:43 PM

#include <iostream>
#include <iomanip>
#include <vector>
#include <climits>
#include "stopwatch.h"

// Conveniently print a vector of integers using <<
std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    int n = v.size();
    os << '{';
    if (n > 0) {
        os << v[0];
        for (int i = 1; i < n; i++)
            os << ", " << v[i];

    }
    os << '}';
    return os;
}


void insertion_sort(std::vector<int>& a) {
    int n = a.size();
    for (int j = 1; j < n; j++) {
        int key = a[j];
        // Insert a[j] into the sorted sequence a[0]...a[j - 1]
        int i = j - 1;
        while (i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
}


void merge(std::vector<int>& a, int p, int q, int r) {
    int n1 = q - p + 1, n2 = r - q, i, j;            // |  c1
    std::vector<int> left(n1 + 1), right(n2 + 1);    // |  c2 
    for (i = 0; i < n1; i++) {                       // +
        left[i] = a[p + i];                          // |  n + 1
    }                                                // +
    for (j = 0; j < n2; j++) {                       // +
        right[j] = a[q + j + 1];                     // |  n + 1
    }                                                // +
    left[n1] = INT_MAX; // Place sentinel            // |  c3
    right[n2] = INT_MAX; // values                   // |  c4
    i = j = 0;                                       // |  c5
    for (int k = p; k <= r; k++) {                   // +
        if (left[i] <= right[j]) {                   // |
            a[k] = left[i];                          // |
            i++;                                     // |  n
        }                                            // |
        else {                                       // |
            a[k] = right[j];                         // |
            j++;                                     // |
        }                                            // |
    }
}


void merge_rec(std::vector<int>& a, int p, int r) {
    if (p < r) {
        //int q = (p + r) / 2;
        int q = p + (r - p)/2;
        merge_rec(a, p, q);
        merge_rec(a, q + 1, r);
        merge(a, p, q, r);
    }
}

void merge_sort(std::vector<int>& a) { // Call to recursive method
    merge_rec(a, 0, a.size() - 1);
}


// Returns true if the elements of an integer vector are
// in non-decreasing (sorted) order; otherwise, returns false.
bool is_sorted(const std::vector<int>& vec) {
    int n = vec.size();
    for (int i = 1; i < n; i++)
        if (vec[i - 1] > vec[i])
            return false;
    return true;
}


// Makes a vector filled with random integers.
// The vector contains size elements and each element
// is from the range 0...max_value - 1.
std::vector<int> make_vector(int size, int max_value) {
    std::vector<int> result(size);
    for (int& elem : result)
        elem = rand() % max_value;
    return result;
}



int main() {
    srand(42);

    std::vector<int> original{ 56, 100, 22, 19, 88, 22, 17, 100, 45 },
                     insertion_working,
                     merge_working;

    // Test insertion sort
    insertion_working = original;
    std::cout << "Before: " << insertion_working << '\n';
    insertion_sort(insertion_working);
    std::cout << "After : " << insertion_working << "   "
              << (is_sorted(insertion_working) ? "(sorted)\n" : "(not sorted)\n");

    // Test mergesort
    merge_working = original;
    std::cout << "Before: " << merge_working << '\n';
    merge_sort(merge_working);
    std::cout << "After : " << merge_working << "   "
              << (is_sorted(merge_working) ? "(sorted)\n" : "(not sorted)\n");

    std::cout << (insertion_working == merge_working ? "Equal\n" : "NOT equal\n");

    std::cout << "================================================\n";

    original = make_vector(10'000, 1'000'000);
    Stopwatch timer;

    // Test insertion sort
    insertion_working = original;
    timer.start();
    insertion_sort(insertion_working);
    timer.stop();
    double insertion_time = timer.elapsed();
    std::cout << (is_sorted(insertion_working) ? "(sorted)\n" : "(not sorted)\n");

    timer.reset(); // Clear stopwatch for a new timing

    // Test mergesort
    merge_working = original;
    timer.start(); 
    merge_sort(merge_working);
    timer.stop(); 
    double merge_time = timer.elapsed();
    std::cout << (is_sorted(merge_working) ? "(sorted)\n" : "(not sorted)\n");

    std::cout << (insertion_working == merge_working ? "Equal\n" : "NOT equal\n");
    std::cout << std::fixed << std::showpoint << std::setprecision(4);
    std::cout << "Insertion time: " << std::setw(10) << insertion_time << " seconds\n";
    std::cout << "Merge time    : " << std::setw(10) << merge_time << " seconds\n";
    
}
