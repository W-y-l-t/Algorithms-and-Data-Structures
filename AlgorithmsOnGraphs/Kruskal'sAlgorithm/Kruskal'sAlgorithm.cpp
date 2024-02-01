/*
 * Time Complexity: O(E log E),
 * where E - count of edges in graph
 *
 * Auxiliary Space: O(V)
 */

#include <iostream>
#include <cinttypes>
#include <numeric>
#include <algorithm>
#include <vector>
#include <set>

struct edge {
    uint32_t from;
    uint32_t to;
    int64_t cost;
};

uint32_t GetParent(uint32_t current,
                   std::vector<uint32_t> &parents) {

    return (parents[current] == current ?
            current : parents[current] = GetParent(parents[current], parents));
}

bool Union(uint32_t a,
           uint32_t b,
           std::vector<uint32_t> &parents,
           std::vector<uint32_t> &rangs) {

    uint32_t a_parent = GetParent(a, parents);
    uint32_t b_parent = GetParent(b, parents);

    if (a_parent != b_parent) {
        if (rangs[a_parent] < rangs[b_parent]) {
            std::swap(a_parent, b_parent);
        }

        parents[b_parent] = a_parent;
        rangs[a_parent] += rangs[b_parent];

        return true;
    }

    return false;
}

int64_t Kruskal(std::vector<edge> &graph,
                size_t vertexes,
                size_t edges,
                std::vector<uint32_t> &parents,
                std::vector<uint32_t> &rangs) {

    int64_t mst_cost = 0;
    std::set<uint32_t> mst;

    for (size_t i = 0; i < edges; ++i) {
        if (Union(graph[i].from, graph[i].to, parents, rangs)) {
            mst_cost += graph[i].cost;
            mst.insert(graph[i].from);
            mst.insert(graph[i].to);
        }

        if (mst.size() == vertexes) {
            return mst_cost;
        }
    }

    return -1;
}

int main() {
    size_t vertexes;
    size_t edges;

    std::cin >> vertexes;
    std::cin >> edges;

    std::vector<edge> graph(edges);

    for (size_t i = 0; i < edges; ++i) {
        uint32_t from;
        uint32_t to;
        int64_t cost;

        std::cin >> from;
        std::cin >> to;
        std::cin >> cost;

        graph[i] = {from, to, cost};
    }

    std::vector<uint32_t> parents(vertexes + 1);
    std::vector<uint32_t> rangs(vertexes + 1, 1);

    std::iota(parents.begin(), parents.end(), 0);

    std::sort(graph.begin(), graph.end(), [](auto &a, auto &b) {
       return a.cost < b.cost;
    });

    int64_t mst_cost = Kruskal(graph, vertexes, edges, parents, rangs);
    std::cout << mst_cost << std::endl;
}
