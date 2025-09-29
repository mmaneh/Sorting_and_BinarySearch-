#include <iostream>
#include <vector>
#include <algorithm>

void countingSort(std::vector<int>& arr) {
   
    int min = *std::min_element(arr.begin(), arr.end());
    int max = *std::max_element(arr.begin(), arr.end());


    int size = max- min + 1;
    std::vector<int> count(size, 0);

    for (int num : arr) {
        ++count[num - min];
    }


    for (int i = 1; i < size; ++i) {
        count[i] += count[i - 1];
    }


    std::vector<int> res(arr.size());

    for (int i = arr.size() - 1; i >= 0; --i) {
        int num = arr[i];
        res[--count[num - min]] = num;
    }


    arr = res;
}

int main() {
    std::vector<int> arr = {-10, 2, 8, 5, -3};
    countingSort(arr);

    for (int a : arr) {
        std::cout << a << " ";
    }


    return 0;
}
