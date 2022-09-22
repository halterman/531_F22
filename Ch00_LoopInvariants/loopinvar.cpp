#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <span>
#include <utility>

int sum(std::span<int> seq) {
    int s = 0, n = seq.size();
    for (int i = 0; i < n; i++)
        s += seq[i];
    return s;
}


int maximum(std::span<int> seq) {
    if (seq.size() == 0)
        throw std::runtime_error("Cannot compute maximum of empty sequence");
    int max = seq[0], n = seq.size();
    for (int i = 1; i < n; i++) 
        if (seq[i] > max)
            max = seq[i];
    return max;
}


void selection_sort(std::span<int> seq) {
    int n = seq.size();
    for (size_t i = 0; i < n - 1; i++) {
        int small = i;
        for (int j = i + 1; j < n; j++)
            if (seq[j] < seq[small])
                small = j;
        if (small != i)
            std::swap(seq[i], seq[small]);
    }
}

void print(std::span<int> seq) {
    std::cout << '{';
    int n = seq.size();
    if (n > 0) {
        std::cout << seq[0];
        for (int i = 1; i < n; i++) 
            std::cout << ", " << seq[i];
    }
    std::cout << "}";
}


int main() {
    // Sum the elements in a vector
    std::vector vec{2, 10, -4, 5};
    print(vec);
    std::cout << " --- Sum: " << sum(vec)
              << " --- Maximum: " << maximum(vec) << '\n';
    selection_sort(vec);
    print(vec);
    std::cout << '\n';

    // Sum the elements in an array object
    std::array arr{2, 10, -5, 20};
    print(arr);
    std::cout << " --- Sum: " << sum(arr)
              << " --- Maximum: " << maximum(arr) << '\n';

    // Sum the elements in a primitive C array
    int a[]{12, 1, -2, 5};
    print(a);
    std::cout << " --- Sum: " << sum(a)
              << " --- Maximum: " << maximum(a) << '\n';

    // Consider an empty sequence
    vec = {};
    print(vec);
    std::cout << '\n';
    //std::cout << " --- Sum: " << sum(vec)
    //          << " --- Maximum: " << maximum(vec) << '\n';
    selection_sort(vec);
    print(vec);
    std::cout << '\n';
}

