#pragma once
#include <map>
#include "graph.hpp"

template<typename T>
void recursive_dfs_visit(const unidirected_graph<T>& G, const T& nodo, std::map<T, bool>& visitati, unidirected_graph<T>& albero)
{
    visitati[nodo] = true;                                      
    for (const auto& vicino : G.neighbors(nodo)) {            
        if (!visitati[vicino]) {                               
            
            albero.add_edge(unidirected_edge<T>(nodo, vicino));
            
            recursive_dfs_visit(G, vicino, visitati, albero);
        }
    }
}

template<typename T>
unidirected_graph<T> recursive_dfs(const unidirected_graph<T>& G, const T& sorgente)
{
    unidirected_graph<T> albero;                   
    std::map<T, bool> visitati;                    
    
    recursive_dfs_visit(G, sorgente, visitati, albero);
    return albero;
}