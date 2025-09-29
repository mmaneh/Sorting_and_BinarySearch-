#include <iostream>
#include <vector>
#include <algorithm>

void countingSort(std::vector<int>& arr) {

    int min = *std::min_element(arr.begin(), arr.end());
    int max = *std::max_element(arr.begin(), arr.end());


    int size = max - min + 1;
    std::vector<int> count(size, 0);

    for (int num : arr) {
        ++count[num - min];
    }


    
    int j = 0;
    for (int i = 0; i < size; ++i) {
        while (count[i]--) {
            arr[j++] = i + min;
        
        }
    }


}



int main() {
    std::vector<int> arr = {-1, 2, 0, 5, 3, 4};
    countingSort(arr);

    
    for (int a : arr) {
        std::cout << a << " ";
    }


    return 0;
}
