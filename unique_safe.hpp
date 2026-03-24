#ifndef UNIQUE_SAFE_HPP
#define UNIQUE_SAFE_HPP

#include <cstddef>

template<typename T>
T* unique(const T* src, std::size_t n, T* dest, std::size_t dest_capacity) {
    if (dest_capacity < n) {
        return nullptr;
    }
    
    if (n == 0) {
        return dest;
    }
    
    std::size_t write_idx = 0;
    
    for (std::size_t read_idx = 0; read_idx < n; ++read_idx) {
        bool is_unique = true;
        
        for (std::size_t check_idx = 0; check_idx < write_idx; ++check_idx) {
            if (src[read_idx] == dest[check_idx]) {
                is_unique = false;
                break;
            }
        }
        
        if (is_unique) {
            dest[write_idx] = src[read_idx];
            ++write_idx;
        }
    }
    
    return dest + write_idx;
}

#endif