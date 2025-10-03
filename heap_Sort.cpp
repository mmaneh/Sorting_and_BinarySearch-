#include <vector>
#include <iostream>


void heapify(std::vector<int>& vec, int size, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int idx = i;

    if (l < size && vec[l] > vec[idx]) {
        idx = l;
    }
    if(r < size && vec[r] > vec[idx]) {
        idx = r;
    }
    if (i != idx) {
	std::swap(vec[i],vec[idx]);
    	heapify(vec,size,idx);

    }
}

void heapSort(std::vector<int>& vec) {
    int n = vec.size();
    for(int i = n/2 - 1; i >= 0; --i) {
        heapify(vec,n,i);
    }

    for(int i = n - 1; i >= 0; --i) {
        std::swap(vec[0], vec[i]);
        heapify(vec,i, 0);
    }
}

int main() {
    std::vector<int> vec = {32,4,77,5,23,6};
    heapSort(vec);
    for(int v : vec) std::cout << v << " ";
}
