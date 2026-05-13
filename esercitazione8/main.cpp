#include <iostream>
#include "graph.hpp"

using namespace std;

int main() {

    // Test di unidirected_edge
    cout << "TEST SUGLI ARCHI\n";

    unidirected_edge<int> e1(4, 7);
    unidirected_edge<int> e2(7, 4);

    cout << "e1 = " << e1 << "\n";
    cout << "e2 = " << e2 << "\n";

    if (e1 == e2) {
        cout << "Gli archi e1 ed e2 sono uguali.\n";
    } else {
        cout << "Gli archi e1 ed e2 sono diversi.\n";
    }

    cout << "\n";

    // Test di unidirected_graph
    cout << "TEST SUL GRAFO\n";

    unidirected_graph<int> g;

    g.add_edge(unidirected_edge<int>(1, 3));
    g.add_edge(unidirected_edge<int>(1, 4));
    g.add_edge(unidirected_edge<int>(2, 4));

         // Aggiungo un duplicato dell'arco (1, 3)
    g.add_edge(unidirected_edge<int>(3, 1));

    cout << "Nodi del grafo:\n";
    for (const auto& nodo : g.all_nodes()) {
        cout << nodo << " ";
    }
    cout << "\n";

    cout << "\nArchi del grafo:\n";
    for (const auto& arco : g.all_edges()) {
        cout << arco << "\n";
    }

    cout << "\nVicini del nodo 1:\n";
    for (const auto& vicino : g.neighbors(1)) {
        cout << vicino << " ";
    }
    cout << "\n";

    cout << "\nNumerazione degli archi:\n";
    cout << "(1, 3) ha numero " << g.edge_number(unidirected_edge<int>(1, 3)) << "\n";
    cout << "(1, 4) ha numero " << g.edge_number(unidirected_edge<int>(1, 4)) << "\n";
    cout << "(2, 4) ha numero " << g.edge_number(unidirected_edge<int>(2, 4)) << "\n";

    cout << "\nArchi recuperati tramite numero:\n";
    cout << "Arco 0 = " << g.edge_at(0) << "\n";
    cout << "Arco 1 = " << g.edge_at(1) << "\n";
    cout << "Arco 2 = " << g.edge_at(2) << "\n";


    // Test di operator-
    cout << "\nTEST SULLA DIFFERENZA TRA GRAFI\n";

    unidirected_graph<int> h;

    h.add_edge(unidirected_edge<int>(1, 2));
    h.add_edge(unidirected_edge<int>(2, 4));

    unidirected_graph<int> differenza = g - h;

    cout << "Archi di g - h:\n";
    for (const auto& arco : differenza.all_edges()) {
        cout << arco << "\n";
    }

    return 0;
}