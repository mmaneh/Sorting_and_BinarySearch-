#include <iostream>
#include <vector>
template <typename Container>
int binarySearch(Container& cont, int start, int end, typename Container::value_type target) {
    while(start <= end) {
        int mid = start + (end - start)/2;
        if (cont[mid] == target) return mid;
        else if (cont[mid] > target) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}

int main() {
	std::vector<int> vec = {1,2,3,4,5};

	int target = 8;
	std::cout << binarySearch(vec, 0, vec.size() - 1, target) << std::endl;

	target = 4;
	std::cout << binarySearch(vec, 0, vec.size() - 1, target) << std::endl;
}
