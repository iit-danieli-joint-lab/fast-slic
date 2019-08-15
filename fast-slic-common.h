#ifndef _FAST_SLIC_COMMON_H
#define _FAST_SLIC_COMMON_H

#include <stdint.h>
#include <chrono>
#include <iostream>
typedef std::chrono::high_resolution_clock Clock;

typedef uint16_t cluster_no_t;
typedef struct Cluster {
    // 7 bytes
    uint16_t y;
    uint16_t x;
    uint16_t r;
    uint16_t g;
    uint16_t b;
    // 1 byte dummy data
    uint16_t reserved[1];

    cluster_no_t number; // 2 bytes
    uint8_t is_active;
    uint32_t num_members;

} Cluster;

typedef struct Connectivity {
    int num_nodes;
    int *num_neighbors;
    uint32_t **neighbors;
} Connectivity;


template <typename T>
static inline T my_max(T x, T y) {
    return (x > y) ? x : y;
}


template <typename T>
static inline T my_min(T x, T y) {
    return (x < y) ? x : y;
}

template <typename T>
static inline T clamp(T value, T lo, T hi) {
    return (value < lo) ? lo : ((value > hi)? hi : value);
}


template <typename T>
static T fast_abs(T n)
{
    if (n < 0)
        return -n;
    return n;
}

template <typename T>
static T ceil_int(T numer, T denom) {
    return (numer + denom - 1) / denom;
}

template <typename T>
static T round_int(T numer, T denom) {
    return (numer + (denom / 2)) / denom;
}

#endif
