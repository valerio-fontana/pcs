#pragma once
#include <queue>
#include <stack>
#include <map>
#include "graph.hpp"

// Contenitore FIFO
template<typename T>
class fifo {
    std::queue<T> q;
public:
    fifo() {}
    void put(const T& valore) {
        q.push(valore);
    }
    T get() {
        T num = q.front();
        q.pop();
        return num;
    }
    bool empty() const {
        return q.empty();
    }
};

// Contenitore LIFO
template<typename T>
class lifo {
    std::stack<T> s;
public:
    lifo() {}
    void put(const T& valore) {
        s.push(valore);
    }
    T get() {
        T num = s.top();
        s.pop();
        return num;
    }
    bool empty() const {
        return s.empty();
    }
};

// BFS e DFS iterativa
template<typename T, typename Container>
unidirected_graph<T> graph_visit(const unidirected_graph<T>& G, const T& ns, Container& contenitore)
{
    unidirected_graph<T> albero;
    std::map<T, bool> visitati;

    contenitore.put(ns);
    visitati[ns] = true;

    while (!contenitore.empty()) {
        T nodo = contenitore.get();
        for (const auto& vicino : G.neighbors(nodo)) {
            if (!visitati[vicino]) {                 
                visitati[vicino] = true;             
                         
                albero.add_edge(unidirected_edge<T>(nodo, vicino));
                contenitore.put(vicino);            
            }
        }
    }
    return albero;
}