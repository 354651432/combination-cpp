#include <iostream>

#include "combination.hpp"

using namespace std;

int main(int argc, char const* argv[]) {
    vector<int> arr1 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 11, 22, 33, 44};

    Combination<int> cb(arr1);

    // auto result = cb.arrangement(4);
    auto result = cb.combination(4);

    int idx = 0;
    for (auto res : result) {
        cout << ++idx << ": ";
        for (auto it : res) {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
