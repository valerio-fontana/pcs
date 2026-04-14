#include <iostream>
#include <vector>
#include <algorithm>

#include "sorts.hpp"
#include "randfiller.h"
#include "timecounter.h"

using namespace std;

int main()
{
    randfiller rf;
    timecounter tc;

    for (int i = 4; i <= 8192; i *= 2) {
        vector<int> v(i);

        rf.fill(v, -100, 100);

        vector<int> v_bubble = v;
        vector<int> v_insertion = v;
        vector<int> v_selection = v;
        vector<int> v_std = v;

        tc.tic();
        bubble_sort(v_bubble);
        double t_bubble = tc.toc();

        tc.tic();
        insertion_sort(v_insertion);
        double t_insertion = tc.toc();

        tc.tic();
        selection_sort(v_selection);
        double t_selection = tc.toc();

        tc.tic();
        sort(v_std.begin(), v_std.end());
        double t_std = tc.toc();

        cout << "Dimensione: " << i << "\n" <<
        "Bubble: " << t_bubble << "\n" <<
        "Insertion: " << t_insertion << "\n" <<
        "Selection: " << t_selection << "\n" <<
        "Standard sort: " << t_std << "\n\n";
    }

    return 0;
}