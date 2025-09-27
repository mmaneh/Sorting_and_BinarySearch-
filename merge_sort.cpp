#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;

    std::vector<int> LeftArray(size1), RightArray(size2);

    for (int i = 0; i < size1; i++) {
        LeftArray[i] = arr[left + i];
    }

    for (int j = 0; j < size2; j++) {
        RightArray[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < size1 && j < size2) {
        if (LeftArray[i] <= RightArray[j]) arr[k++] = LeftArray[i++];
        else arr[k++] = RightArray[j++];
    }
    while (i < size1) arr[k++] = LeftArray[i++];
    while (j < size2) arr[k++] = RightArray[j++];
}

void mergeSort(std::vector<int>& arr, int left, int right) {
        if(left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }


int main() {
    std::vector<int> vec = {1, 7, 5, 3, 2};
    mergeSort(vec, 0, vec.size() - 1);
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    return 0;
}
