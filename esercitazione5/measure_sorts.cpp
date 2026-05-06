#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

#include "sorts.hpp"
#include "randfiller.h"
#include "timecounter.h"

using namespace std;

struct times {
    double bubble = 0;
    double insertion = 0;
    double selection = 0;
    double merge = 0;
    double quick = 0;
    double quick_mod = 0;
    double std = 0;
};

int main()
{
    randfiller rf;
    timecounter tc;

    ofstream out("times.dat");

    if (!out) {
        cerr << "Errore nell'apertura del file.\n";
        return 1;
    }

    int n = 0;
    string algoritmo_n = "";

    vector<int> dimensioni;
    vector<times> tempi;

    for (int i = 10; i <= 100; i += 10) {
        times t;

        vector<vector<int>> vettori(10, vector<int>(i));

        for (int j = 0; j < 10; j++) {
            rf.fill(vettori[j], -100, 100);
        }

        vector<vector<int>> v_bubble = vettori;
        tc.tic();
        for (int j = 0; j < 10; j++) {
            bubble_sort(v_bubble[j]);
        }
        t.bubble = tc.toc() / 10;

        vector<vector<int>> v_insertion = vettori;
        tc.tic();
        for (int j = 0; j < 10; j++) {
            insertion_sort(v_insertion[j]);
        }
        t.insertion = tc.toc() / 10;

        vector<vector<int>> v_selection = vettori;
        tc.tic();
        for (int j = 0; j < 10; j++) {
            selection_sort(v_selection[j]);
        }
        t.selection = tc.toc() / 10;

        vector<vector<int>> v_merge = vettori;
        tc.tic();
        for (int j = 0; j < 10; j++) {
            merge_sort(v_merge[j], 0, v_merge[j].size() - 1);
        }
        t.merge = tc.toc() / 10;

        vector<vector<int>> v_quick = vettori;
        tc.tic();
        for (int j = 0; j < 10; j++) {
            quick_sort(v_quick[j], 0, v_quick[j].size() - 1);
        }
        t.quick = tc.toc() / 10;

        vector<vector<int>> v_std = vettori;
        tc.tic();
        for (int j = 0; j < 10; j++) {
            sort(v_std[j].begin(), v_std[j].end());
        }
        t.std = tc.toc() / 10;

        double quadratico = min({t.bubble, t.insertion, t.selection});
        double logaritmico = min({t.merge, t.quick});

        if (quadratico == t.bubble) {
            algoritmo_n = "Bubble sort";
        }
        else if (quadratico == t.insertion) {
            algoritmo_n = "Insertion sort";
        }
        else {
            algoritmo_n = "Selection sort";
        }

        if (quadratico < logaritmico) {
            n = i;
        }

        dimensioni.push_back(i);
        tempi.push_back(t);
    }

    if (n > 0) {
        cout << "Soglia trovata: n = " << n << "\n";
        cout << "Algoritmo quadratico scelto: " << algoritmo_n << "\n\n";
    }
    else {
        cout << "Nessuna soglia trovata.\n\n";
    }

    for (int k = 0; k < dimensioni.size(); k++) {
        int i = dimensioni[k];

        vector<vector<int>> vettori(10, vector<int>(i));
        for (int j = 0; j < 10; j++) {
            rf.fill(vettori[j], -100, 100);
        }

        vector<vector<int>> v_quickmod = vettori;

        tc.tic();
        for (int j = 0; j < 10; j++) {
            quick_mod_sort(v_quickmod[j], 0, v_quickmod[j].size() - 1, n);
        }
        tempi[k].quick_mod = tc.toc() / 10;
    }

    for (int k = 0; k < dimensioni.size(); k++) {
        cout << "Dimensione: " << dimensioni[k] << "\n" <<
        "Bubble: " << tempi[k].bubble << "\n" <<
        "Insertion: " << tempi[k].insertion << "\n" <<
        "Selection: " << tempi[k].selection << "\n" <<
        "Merge: " << tempi[k].merge << "\n" <<
        "Quick: " << tempi[k].quick << "\n" <<
        "Quick modificato: " << tempi[k].quick_mod << "\n" <<
        "Standard sort: " << tempi[k].std << "\n\n";

        out << dimensioni[k] << " " <<
        tempi[k].bubble << " " <<
        tempi[k].insertion << " " <<
        tempi[k].selection << " " <<
        tempi[k].merge << " " <<
        tempi[k].quick << " " <<
        tempi[k].quick_mod << " " <<
        tempi[k].std << "\n";
    }
    

    out.close();

    cout << "Risultati salvati anche in times.dat.\n" <<
    "Ordine: size, bubble, insertion, selection, merge, quick, quick_mod, std_sort.\n";

    return 0;
}