#include <iostream>
#include <fstream>
#include "graph.hpp"
#include "graph_visit.hpp"
#include "recursive_dfs.hpp"
#include "dijkstra.hpp"
#include <vector>
#include <utility>

using namespace std;

int main() {
    unidirected_graph<unsigned int> G;

    vector<pair<unsigned int, unsigned int>>
    archi = {{1,2}, {1,3}, {2,4}, {2,5}, {3,6}, {4,7}, {5,7}, {5,8}, {6,9}, {8,9}};
    for (const auto& arco : archi) {
        G.add_edge(unidirected_edge<unsigned int>(arco.first, arco.second));
    }
    unsigned int nodo1 = 1;

    //BFS
    fifo<unsigned int> q;
    auto bfsG = graph_visit(G, nodo1, q);

    //DFS iterativa
    lifo<unsigned int> s;
    auto dfsG = graph_visit(G, nodo1, s);

    //DFS ricorsiva
    auto dfsRicorsivaG = recursive_dfs(G, nodo1);

    //Dijkstra
    auto dijkstraG = dijkstra(G, nodo1);

    cout << "BFS: " << "\n";
    for (const auto& arco : bfsG.all_edges()) {
        cout << arco << "\n";
    }
    cout << "\n";

    cout << "DFS iterativa: " << "\n";
    for (const auto& arco : dfsG.all_edges()) {
        cout << arco << "\n";
    }
    cout << "\n";

    cout << "DFS ricorsiva: " << "\n";
    for (const auto& arco : dfsRicorsivaG.all_edges()) {
        cout << arco << "\n";
    }
    cout << "\n";

    cout << "Dijkstra: " << "\n";
    for (const auto& arco : dijkstraG.all_edges()) {
        cout << arco << "\n";
    }
    cout << "\n";

    ofstream out_dfs("dfs.dot");
    out_dfs << "graph DFS {" << "\n";
    for (const auto& arco : dfsG.all_edges()) {
        out_dfs << "   " << arco.from() << " -- " << arco.to() << ";" << "\n";
    }
    out_dfs << "}" << "\n";

    out_dfs.close();
    
    ofstream out_bfs("bfs.dot");
    out_bfs << "graph BFS {" << "\n";
    for (const auto& arco : bfsG.all_edges()) {
        out_bfs << "   " << arco.from() << " -- " << arco.to() << ";" << "\n";
    }
    out_bfs << "}" << "\n";

    out_bfs.close();

    ofstream out_dfs_ricorsiva("dfs_r.dot");
    out_dfs_ricorsiva << "graph DFS_Ricorsiva {" << "\n";
    for (const auto& arco : dfsRicorsivaG.all_edges()) {
        out_dfs_ricorsiva << "   " << arco.from() << " -- " << arco.to() << ";" << "\n";
    }
    out_dfs_ricorsiva << "}" << "\n";

    out_dfs_ricorsiva.close();

    ofstream out_dijkstra("dijkstra.dot");
    out_dijkstra << "graph Dijkstra {" << "\n";
    for (const auto& arco : dijkstraG.all_edges()) {
        out_dijkstra << "   " << arco.from() << " -- " << arco.to() << ";" << "\n";
    }
    out_dijkstra << "}" << "\n";

    out_dijkstra.close();
    
    return 0;
}

