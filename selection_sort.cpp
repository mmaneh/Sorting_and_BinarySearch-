#include <iostream>
#include <vector>

template <typename Container>
void selectionSort(Container& cont) {
    for (int i = 0; i < cont.size() - 1; ++i) {
        int minIdx = i; 
        for (int j = i + 1; j < cont.size(); ++j) {
            if (cont[j] < cont[minIdx]) {
                minIdx = j;
            }
        }
        std::swap(cont[minIdx], cont[i]);
    }
}


int main() {
        std::vector<int> vec = {1,7,5,3,2};
        selectionSort(vec);
        for (int i = 0; i < vec.size(); ++i) {
                std::cout << vec[i];
        }
}

