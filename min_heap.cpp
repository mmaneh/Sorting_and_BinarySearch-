#include <vector>
#include <iostream>

class min_heap {
    private:
        std::vector<int> heap;
        int parent(int i) {return (i - 1) / 2;}
        int left(int i) {return 2 * i + 1;}
        int right(int i) {return 2 * i + 2;}

        void heapify(int i) {
            int l = left(i);
            int r = right(i);
            int idx = i;

            if(l < heap.size() && heap[idx] > heap[l]) {
                idx = l;
            }
            if(r < heap.size() && heap[idx] > heap[r]) {
                idx = r;
            }
            if (idx != i) {
                std::swap(heap[idx], heap[i]);
                heapify(idx);
            }
        }
    public:
        min_heap() = default;
        ~min_heap() = default;

        int top() {
            return heap[0];
        }


        void push(int val) {
            heap.push_back(val);
            int i = heap.size() - 1;
            int  p = parent(i);
            while(i > 0 && heap[p] > heap[i]) {
                std::swap(heap[p], heap[i]);
                i = parent(i);
		p = parent(i);
            }
        }

        void pop() {
            std::swap(heap[0], heap[heap.size() - 1]);
            heap.pop_back();
	    if(!heap.empty()) heapify(0);
        }
        void print() {
            for (int h : heap) std::cout << h << " ";
        }
};
int main() {
    min_heap hp;
    hp.push(5);
    hp.push(15);
    hp.push(30);
    hp.push(20);

    hp.print();
    hp.pop();
    hp.print();
}
