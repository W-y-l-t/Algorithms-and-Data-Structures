/*
 * Let`s solve next problem using BFS:
 * In an undirected graph, you need to find the length of the shortest path between two vertices.
 *
 * Time Complexity: O(V + E),
 * where V - count of vertexes,
 * E - count of edges in graph
 *
 * Auxiliary Space: O(V)
 */

#include <iostream>
#include <cinttypes>
#include <vector>
#include <queue>

uint64_t Bfs(size_t from,
             size_t to,
             const std::vector<std::vector<uint32_t>> &graph,
             size_t vertexes,
             size_t edges) {

    std::vector<bool> used(vertexes + 1, false);
    std::queue<std::pair<uint32_t, uint64_t>> queue;

    queue.emplace(from, 0);
    while (!queue.empty()) {
        auto [current_vertex, path_length] = queue.front();
        queue.pop();

        if (used[current_vertex]) {
            continue;
        }
        used[current_vertex] = true;

        if (current_vertex == to) {
            return path_length;
        }

        for (auto neighbour : graph[current_vertex]) {
            queue.emplace(neighbour, path_length + 1);
        }
    }

    return -1;
}

int main() {
    size_t vertexes;
    size_t edges;

    std::cin >> vertexes;
    std::cin >> edges;

    std::vector<std::vector<uint32_t>> graph(vertexes + 1,
                                            std::vector<uint32_t>(0));

    for (size_t i = 0; i < edges; ++i) {
        uint32_t from;
        uint32_t to;

        std::cin >> from;
        std::cin >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    uint32_t from;
    uint32_t to;

    std::cin >> from;
    std::cin >> to;

    uint64_t path_length = Bfs(from, to, graph, vertexes, edges);
    std::cout << path_length << std::endl;
}
