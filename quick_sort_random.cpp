#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int partition(std::vector<int>& vec, int left, int right) {
    int pivotIdx = left + rand() % (right - left + 1);;
    std::swap(vec[pivotIdx],vec[right]);
    int pivot = vec[right];
    int i = left;
    int j = right;

    while(i <= j) {

        while(vec[i] < pivot) ++i;
        while(vec[j] >= pivot) --j;

       if(i < j) std::swap(vec[i], vec[j]);

    }

    std::swap(vec[i],vec[right]);
    return i;
}

void quickSort(std::vector<int>& vec, int left, int right) {
    if (left >= right) return;
    int pivot = partition(vec, left, right);
    quickSort(vec, left, pivot - 1);
    quickSort(vec, pivot + 1, right);

}

int main() {
    srand(time(0));
    std::vector<int> vec = {10, 16, 8, 12, 15, 7, 9};
    quickSort(vec,0, vec.size() - 1);
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
}

