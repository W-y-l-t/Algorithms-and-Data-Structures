/*
 * Time Complexity: O(VE),
 * where V - count of vertexes,
 * E - count of edges in graph
 *
 * Auxiliary Space: O(V)
 */

#include <iostream>
#include <cinttypes>
#include <vector>

struct edge {
    uint32_t from;
    uint32_t to;
    int64_t cost;
};

std::vector<int64_t> BellmanFord(size_t from,
                                  std::vector<edge> &graph,
                                  size_t vertexes,
                                  size_t edges) {

    std::vector<int64_t> dists(vertexes + 1, INT64_MAX);
    dists[from] = 0;

    for (size_t i = 1; i < vertexes; ++i) {
        bool is_shorter = false;

        for (size_t j = 0; j < edges; ++j) {
            if (dists[graph[j].from] < INT64_MAX &&
                dists[graph[j].to] > dists[graph[j].from] + graph[j].cost) {

                dists[graph[j].to] = dists[graph[j].from] + graph[j].cost;
                is_shorter = true;
                }
        }

        if (!is_shorter) {
            break;
        }
    }

    return dists;
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

    uint32_t from;
    uint32_t to;

    std::cin >> from;
    std::cin >> to;


    std::vector<int64_t> dists = BellmanFord(from, graph, vertexes, edges);
    int64_t path_length = dists[to];
    std::cout << path_length << std::endl;
}
