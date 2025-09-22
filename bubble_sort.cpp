#include <vector>
#include <iostream>

template <typename Container>
void bubbleSort(Container& cont) {

    for (int i = 0; i < cont.size(); ++i) {
        for (int j = 0; j < cont.size() - 1 - i; ++j) {
            if (cont[j] > cont[j + 1]) {
                std::swap(cont[j], cont[j + 1]);
            }
        }
    }
}

int main() {
	std::vector<int> vec = {1,7,5,3,2};
	bubbleSort(vec);
        for (int i = 0; i < vec.size(); ++i) {
        	std::cout << vec[i];
	}
}
