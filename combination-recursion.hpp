#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Combination {
    typedef vector<T> Set;
    Set vec;
    int n;
    bool needFilter;

    Set buildLast(Set state) {
        Set ret;
        for (T it : vec) {
            if (find(state.begin(), state.end(), it) == state.end()) {
                ret.push_back(it);
            }
        }

        return ret;
    };

    bool inResults(const Set& vec) {

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

    int run(const Set& state) {
        if (state.size() >= n) {
            if (needFilter && inResults(state)) {
                return 0;
            }

            results.push_back(state);
            return 1;
        }

        Set last = buildLast(state);

        int cnt = 0;
        for (T it : last) {
            auto state1 = state;
            state1.push_back(it);

            cnt += run(state1);
        }

        return cnt;
    }

public:
    vector<Set> results;
    Combination(Set vec, int n)
        : vec(vec)
        , n(n) { }

    vector<Set> combination() {
        results.clear();
        needFilter = true;
        run(Set {});

        return results;
    }

    vector<Set> arrangement() {
        results.clear();
        needFilter = false;
        run(Set {});

        return results;
    }
};