#ifndef UNIQUE_ORIGINAL_HPP
#define UNIQUE_ORIGINAL_HPP

#include <cstddef>

template<typename T>
T* unique(T* a, std::size_t s) {
    if (s == 0) return a;
    
    std::size_t write_idx = 1;
    for (std::size_t read_idx = 1; read_idx < s; ++read_idx) {
        if (a[read_idx] != a[write_idx - 1]) {
            a[write_idx] = a[read_idx];
            ++write_idx;
        }
    }
    return a + write_idx;
}

#endif