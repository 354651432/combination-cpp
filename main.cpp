#include <iostream>

#include "combination-recursion.hpp"

using namespace std;

int main() {
    vector<int> arr1 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 11};

    Combination<int> cb(arr1, 3);
    auto result = cb.arrangement();
    // result = cb.combination();

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
