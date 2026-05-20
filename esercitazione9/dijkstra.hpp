#pragma once
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <limits>
#include <functional>

#include "graph.hpp"

template<typename T>
unidirected_graph<T> dijkstra(const unidirected_graph<T>& G, const T& ns)
{
    unidirected_graph<T> albero;
    int infinito = std::numeric_limits<int>::max();
    std::map<T, int> distanza;
    std::map<T, T> np;

    for (const T& nodo : G.all_nodes()){
        distanza[nodo] = infinito;
    }

    distanza[ns] = 0;

    std::priority_queue<
    std::pair<int, T>,                  
    std::vector<std::pair<int, T>>,     
    std::greater<std::pair<int, T>>     
    > prio_queue;
    
    prio_queue.push({0, ns});

    while (!prio_queue.empty()) {
        T n = prio_queue.top().second;     
        int d = prio_queue.top().first;    
        prio_queue.pop();

        if (d > distanza[n]) {
            continue;
        }

        for (const T& w : G.neighbors(n)) {
            if (distanza[n] + 1 < distanza[w]) { 
                distanza[w] = distanza[n] + 1;
                np[w] = n;

                prio_queue.push({distanza[w], w});
            }
        }
    }

    for (const auto& elemento : np) {
        T nodo = elemento.first;
        T precedente = elemento.second;
        albero.add_edge(unidirected_edge<T>(precedente, nodo));
    }

    return albero;
}