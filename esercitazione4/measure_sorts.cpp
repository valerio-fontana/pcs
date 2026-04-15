#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include "sorts.hpp"
#include "randfiller.h"
#include "timecounter.h"

using namespace std;

int main()
{
    randfiller rf;
    timecounter tc;

    ofstream out("times.dat");

    if (!out) {
        cerr << "Errore nell'apertura del file.\n";
        return 1;
    }

    for (int size = 4; size <= 8192; size *= 2) {
        vector<int> v(size);

        rf.fill(v, -100, 100);
        tc.tic();
        bubble_sort(v);
        double t_bubble = tc.toc();

        rf.fill(v, -100, 100);
        tc.tic();
        insertion_sort(v);
        double t_insertion = tc.toc();

        rf.fill(v, -100, 100);
        tc.tic();
        selection_sort(v);
        double t_selection = tc.toc();

        rf.fill(v, -100, 100);
        tc.tic();
        sort(v.begin(), v.end());
        double t_std = tc.toc();

        cout << "Dimensione: " << size << "\n" <<
        "Bubble: " << t_bubble << "\n" <<
        "Insertion: " << t_insertion << "\n" <<
        "Selection: " << t_selection << "\n" <<
        "Standard sort: " << t_std << "\n\n";

        out << size << " " <<
        t_bubble << " " <<
        t_insertion << " " <<
        t_selection << " " <<
        t_std << "\n";
    }

    out.close();

    cout << "Risultati salvati anche in times.dat.\n" <<
    "Ordine: size, bubble, insertion, selection, std_sort.\n";

    return 0;
}