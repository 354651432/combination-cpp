#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Combination {

    // 最终结果集
    vector<vector<T>> results;

    // 初始集合
    vector<T> vec;

    // 如果 needFilter ＝ true 则是组合，否则是排列

    void pick(bool needFilter) {
        int n = results.size();
        for (int i = 0; i < n; i++) {
            vector<T> head = *results.begin();
            results.erase(results.begin());

            vector<T> last = diff(vec, head);

            for (auto& it : last) {
                vector<T> headCopy = head;
                headCopy.push_back(it);

                if (needFilter && inResults(headCopy)) {
                    continue;
                }

                results.push_back(headCopy);
            }
        }
    }

    bool inResults(const vector<T>& vec) {

        for (auto arr : results) {
            if (arr.size() != vec.size()) {
                continue;
            }
            vector<T> arr1 = vec;
            sort(arr1.begin(), arr1.end());
            sort(arr.begin(), arr.end());

            if (arr == arr1) {
                return true;
            }
        }

        return false;
    }

    // std的 set_difference 只能用于排序过的 vector
    vector<T> diff(const vector<T>& arr1, const vector<T>& arr2) {
        vector<T> ret;
        for (T it : arr1) {
            if (find(arr2.begin(), arr2.end(), it) == arr2.end()) {
                ret.push_back(it);
            }
        }

        return ret;
    }

public:
    Combination(vector<T> vec1)
        : vec(vec1) { }

    // 排列
    vector<vector<T>> arrangement(int m, bool needFilter = false) {
        if (m > vec.size()) {
            throw "m is bigger than number of vec";
        }

        results.clear();
        for (auto it : vec) {
            results.push_back(vector<T> {it});
        }

        for (int i = 0; i < m - 1; i++) {
            pick(needFilter);
        }

        return results;
    }

    // 组合
    vector<vector<T>> combination(int m) {
        return arrangement(m, true);
    }
};