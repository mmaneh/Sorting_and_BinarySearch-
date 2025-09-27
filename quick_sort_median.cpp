#include <vector>
#include <iostream>
int partition(std::vector<int>& vec, int left, int right) {
    int mid = left + (right - left) / 2 ;
    if (vec[left] > vec[mid]) std::swap(vec[left], vec[mid]);
    if (vec[left] > vec[right]) std::swap(vec[left], vec[right]);
    if (vec[mid] > vec[right]) std::swap(vec[mid], vec[right]);

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
    std::vector<int> vec = {10, 16, 8, 12, 15, 7, 9};
    quickSort(vec,0, vec.size() - 1);
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
}

