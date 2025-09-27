#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    std::vector<int> vec = {1, 7, 5, 3, 2};
    insertionSort(vec);
    for (int i = 0; i < vec.size(); ++i) {
	    std::cout << vec[i] << " ";
    }
    return 0;
}

