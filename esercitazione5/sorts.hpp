#pragma once

#include <iostream>
#include <concepts>
#include <algorithm>
#include <optional>
#include <vector>

template<typename T>
void bubble_sort(std::vector<T>& v)
{
    for (int i = 0; i < v.size() - 1; i++) {
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
void merge(std::vector<T>& v, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    std::vector<T> L(n1 + 1);
    std::vector<T> R(n2 + 1);

    for (int i = 0; i < n1; i++) {
        L[i] = v[p + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = v[q + j + 1];
    }

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++) {
        bool infinito_l = (i >= n1);
        bool infinito_r = (j >= n2);

        if (infinito_r || (!infinito_l && L[i] <= R[j])) {
            v[k] = L[i];
            i++;
        }
        else {
            v[k] = R[j];
            j++;
        }
    }
}

template<typename T>
void merge_sort(std::vector<T>& v, int p, int r)
{
    if (p < r) {
        int q = (p + r)/2;

        merge_sort(v, p, q);
        merge_sort(v, q + 1, r);
        merge(v, p, q, r);
    }
}

template<typename T>
int partition(std::vector<T>& v, int p, int r)
{
    T x = v[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        if (v[j] <= x) {
            i++;
            std::swap(v[i], v[j]);
        }
    }

    std::swap(v[i + 1], v[r]);

    return i + 1;
}

template<typename T>
void quick_sort(std::vector<T>& v, int p, int r)
{
    if (p < r) {
        int q = partition(v, p, r);

        quick_sort(v, p, q - 1);
        quick_sort(v, q + 1, r);
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

template<typename T>
void quick_mod_sort(std::vector<T>& v, int p, int r, int n)
{
    int dim = v.size();

    if (dim <= n) {
        insertion_sort(v);
    }
    else {
        quick_sort(v, p, r);
    }
}