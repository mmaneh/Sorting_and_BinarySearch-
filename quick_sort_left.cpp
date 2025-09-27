#include <iostream>
#include <vector>

int partition(std::vector<int>& vec, int left, int right) {
    int pivot = vec[left];

    int i = left;
    int j = right;

    while(i < j) {

        while(i <= right && vec[i] <= pivot) ++i;
        while(j >= left && vec[j] > pivot) --j;

        if (i < j) std::swap(vec[i], vec[j]);

    }

    std::swap(vec[j], vec[left]);
    return j;
}

void quickSort(std::vector<int>& vec, int left, int right) {
    if (left >= right) return;
    int pivot = partition(vec, left, right);
    quickSort(vec, left, pivot - 1);
    quickSort(vec, pivot + 1, right);

}

int main() {
    std::vector<int> vec = {10, 16, 8, 12, 15, 7, 9};
    quickSort(vec,0, vec.size() - 1);
      for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
}
