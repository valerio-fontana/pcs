#pragma once

#include <iostream>
#include <concepts>
#include <algorithm>
#include <optional>
#include <vector>

template<typename T>
void bubble_sort(std::vector<T>& v)
{
    for (int i = 0; i < v.size(); i++) {
        for (int j = v.size() - 1; j > i; j--) {
            if (v[j] < v[j - 1]) {
                std::swap(v[j], v[j - 1]);
            }
        }
    }
}

template<typename T>
void insertion_sort(std::vector<T>& v)
{
    for (int j = 1; j < v.size(); j++) {
        T key = v[j];
        int i = j - 1;

        while (i >= 0 && v[i] > key) {
            v[i + 1] = v[i];
            i--;    
        }

        v[i + 1] = key;
    }
}

template<typename T>
void selection_sort(std::vector<T>& v)
{
    for (int i = 0; i < v.size() - 1; i++) {
        int min = i;

        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }

        std::swap(v[i], v[min]);
    }
}

template<typename T>
bool is_sorted(const std::vector<T>& v)
{
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < v[i - 1]) {
            return false;
        }
    }

    return true;
}