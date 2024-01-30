/*
* Time Complexity: O(E log V),
 * where V - count of vertexes,
 * E - count of edges in graph
 *
 * Auxiliary Space: O(V)
 */

#include <iostream>
#include <cinttypes>
#include <iterator>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

struct edge {
    uint32_t to;
    int64_t cost;
};

template<typename T>
std::ostream& operator<<(std::ostream &out, std::vector<T> &data) {
    std::ranges::copy(data, std::ostream_iterator<T>(out, " "));

    return out;
}

std::vector<int64_t> Dijkstra(size_t from,
                                 std::map<uint32_t, std::vector<edge>> &graph,
                                 size_t vertexes,
                                 size_t edges) {

    std::vector<int64_t> dists(vertexes + 1, INT64_MAX);
    std::vector<bool> used(vertexes + 1, false);
    std::priority_queue<uint32_t> queue;
    queue.push(from);
    dists[from] = 0;

    while (!queue.empty()) {
        uint32_t current = queue.top();
        queue.pop();

        if (used[current]) {
            continue;
        }
        used[current] = true;

        for (auto &e : graph[current]) {
            if (dists[e.to] > dists[current] + e.cost) {
                dists[e.to] = dists[current] + e.cost;
                queue.push(e.to);
            }
        }
    }

    return dists;
}

int main() {
    size_t vertexes;
    size_t edges;

    std::cin >> vertexes;
    std::cin >> edges;

    std::map<uint32_t, std::vector<edge>> graph;


    for (size_t i = 0; i < edges; ++i) {
        uint32_t from;
        uint32_t to;
        int64_t cost;

        std::cin >> from;
        std::cin >> to;
        std::cin >> cost;

        graph[from].push_back({to, cost});
        graph[to].push_back({from, cost});
    }

    uint32_t from;

    std::cin >> from;

    std::vector<int64_t> dists = Dijkstra(from, graph, vertexes, edges);
    std::cout << dists << std::endl;
}
