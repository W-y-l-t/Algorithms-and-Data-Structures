/*
 * Time Complexity: O(V + E),
 * where V - count of vertexes,
 * E - count of edges in graph
 *
 * Auxiliary Space: O(1)
 *
 * !in example,
 * I've written Topological sort algorithm
 * with O(V) auxiliary space!
 */

#include <iostream>
#include <cinttypes>
#include <vector>

void Dfs(size_t current,
         const std::vector<std::vector<uint32_t>> &graph,
         std::vector<bool> &used,
         std::vector<uint32_t> &top_sorted) {

    if (!used[current]) {
        used[current] = true;

        for (auto &next : graph[current]) {
            Dfs(next, graph, used, top_sorted);
        }

        top_sorted.push_back(current);
    }
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
    }

    std::vector<bool> used(vertexes + 1, false);
    std::vector<uint32_t> top_sorted(0);

    for (size_t i = 1; i <= vertexes; ++i) {
        if (!used[i]) {
            Dfs(i, graph, used, top_sorted);
        }
    }

    for (const auto &current : top_sorted) {
        std::cout << current << " ";
    }
    std::cout << std::endl;
}
