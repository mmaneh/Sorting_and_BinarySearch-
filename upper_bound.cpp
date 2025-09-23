#include <iostream>
#include <vector>
template<typename ForwardIt, typename T, typename Func>
ForwardIt upper_bound(ForwardIt first, ForwardIt last, T value, Func cmp) {
    int count = std::distance(first,last);
    int step = 0;

    ForwardIt it;

    while(count > 0) {
        it = first;
        step = count / 2;
        std::advance(it,step);

        if (!cmp(value,*it)) {
            first = ++it;
            count -= step + 1;
        }else {
            count = step;
        }
    }
    return first;
}
template <typename T>
bool compare(T v1, T v2) {

    return v1 < v2;
}
int main() {
    std::vector<int> vec = {1,2,3,4,5};
    auto res = upper_bound(vec.begin(),vec.end(), 4, compare<int>);
    std::cout << *res;
}
