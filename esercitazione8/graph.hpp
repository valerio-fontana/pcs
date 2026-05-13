#pragma once
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <list>

template<typename T>
class unidirected_edge {
    T node1_;
    T node2_;
public:
    unidirected_edge(const T& p_node1, const T& p_node2)
    {
        node1_ = std::min(p_node1, p_node2);
        node2_ = std::max(p_node1, p_node2);
    }
  
    T node1() const { return node1_;}
    T node2() const { return node2_;}

    T from() const { return node1_;}
    T to() const { return node2_;}

    bool operator<(const unidirected_edge<T>& other) const {
        if (node1_ < other.node1_) {
            return true;
        }
        if (node1_ > other.node1_) {
            return false;
        }
        if (node2_ < other.node2_) {
            return true;
        }
        return false;
    }

    bool operator==(const unidirected_edge<T>& other) const {
        if (node1_ == other.node1_ ) {
            if (node2_ == other.node2_) {
                return true;
            }
        }
        return false;
    }
};

template<typename T> 
std::ostream&
operator<<(std::ostream& os, const unidirected_edge<T>& e) {
    os << "(" << e.from() << "," << e.to() << ")";
    return os;
}

template<typename T>
class unidirected_graph {
    std::map<T, std::set<T>> neighbours;
    std::set<unidirected_edge<T>> edges;
    std::list<unidirected_edge<T>> ord_edges;
    std::map<unidirected_edge<T>, int> num_edges;

public:
    unidirected_graph()
    {}

    unidirected_graph(const unidirected_graph<T>& other)
        : neighbours(other.neighbours),
          edges(other.edges),
          ord_edges(other.ord_edges),
          num_edges(other.num_edges)
    {}

    std::set<T> neighbors(const T& node) const {
        auto pos = neighbours.find(node);
        if (pos == neighbours.end()) {
            return {};
        }
        return pos -> second; 
    }

    void add_edge(const unidirected_edge<T>& edge) {
        auto ret = edges.insert(edge);
        if (!ret.second) {
            return;
        }
        T node1 = edge.from();
        T node2 = edge.to();

        neighbours[node1].insert(node2);
        neighbours[node2].insert(node1);

        int num = static_cast<int>(ord_edges.size());

        ord_edges.push_back(edge);
        num_edges[edge] = num;
    }

    std::set<unidirected_edge<T>> all_edges() const {
        return edges;
    }

    std::set<T> all_nodes() const {
        std::set<T> nodes;
        for (const auto& elemento : neighbours) {
            nodes.insert(elemento.first);
        }
        return nodes;
    }

    int edge_number(const unidirected_edge<T>& edge) const {
        auto pos = num_edges.find(edge);
        
        if (pos == num_edges.end()) {
            return -1;
        }
        return pos -> second;
    }

    unidirected_edge<T> edge_at(int num) const {
        int count = 0;
        for (const auto& edge : ord_edges) {
            if (count == num) {
                return edge;
            }
            count = count + 1;
        }
        return ord_edges.front();
    }

    unidirected_graph<T> operator-(const unidirected_graph<T>& other) const{
        unidirected_graph<T> result;

        for (const auto& edge : edges) {
            if (other.edges.find(edge) == other.edges.end()) {
                result.add_edge(edge);
            }
        }
        return result;
    }
};