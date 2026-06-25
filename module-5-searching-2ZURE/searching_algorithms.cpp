#include "searching_algorithms.h"
#include <chrono>



using Clock = std::chrono::high_resolution_clock;


void linear_search(const std::vector<int>& data, int target, Metrics& m) {
    auto start = Clock::now();

    m.comparisons = 0;
    m.found_index = -1;

    for (int i = 0; i < data.size(); i++) {
        m.comparisons++;

        if (data[i] == target) {
            m.found_index = i;
            break;
        }
    }

    m.time_us = std::chrono::duration<double, std::micro>(Clock::now() - start).count();
}



void binary_search(const std::vector<int>& data, int target, Metrics& m) {
    auto start = Clock::now();

     m.comparisons = 0;
    m.found_index = -1;

    int left = 0;
    int right = data.size() - 1;

    while (left <= right) {
        m.comparisons++;

        int mid = (left + right) / 2;

        if (data[mid] == target) {
            m.found_index = mid;
            break;
        }
        else if (target < data[mid]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    m.time_us = std::chrono::duration<double, std::micro>(Clock::now() - start).count();
}
