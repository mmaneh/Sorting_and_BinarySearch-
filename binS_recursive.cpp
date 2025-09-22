#include <iostream>
#include <vector>

template <typename Container>
int binarySearch(Container& cont, int start, int end, typename Container::value_type target) {
    if (start > end) return -1;
    int mid = start + (end - start) / 2;
    if (cont[mid] == target) return mid;

    if(cont[mid] > target)  return binarySearch(cont, start, mid - 1, target); 
    else return binarySearch(cont, mid + 1, end, target);

}

int main() {
        std::vector<int> vec = {1,2,3,4,5};

        int target = 8;
        std::cout << binarySearch(vec, 0, vec.size() - 1, target) << std::endl;

        target = 4;
        std::cout << binarySearch(vec, 0, vec.size() - 1, target) << std::endl;
}

