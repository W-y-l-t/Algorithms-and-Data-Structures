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
#include <map>

bool Kuhn(uint32_t current,
          std::vector<std::vector<uint32_t>> &graph,
          std::vector<bool> &used,
          std::map<uint32_t, uint32_t> &match) {

    if (!used[current]) {
        used[current] = true;

        for (auto &next : graph[current]) {
            if (!match.contains(next) ||
                Kuhn(match[next], graph, used, match)) {

                match[next] = current;
                return true;
                }
        }
    }

    return false;
}

void PrintMatching(std::map<uint32_t, uint32_t> &match, size_t pivot) {
    for (size_t i = 1; i <= pivot; ++i) {
        if (match.contains(i)) {
            std::cout << match[i] << " " << i << std::endl;
        }
    }
}

int main() {
    size_t vertexes;
    size_t edges;
    size_t pivot;

    std::cin >> vertexes;
    std::cin >> edges;
    std::cin >> pivot;

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

    std::vector<bool> used(vertexes + 1, false);
    std::map<uint32_t, uint32_t> match;

    for (size_t i = 1; i <= vertexes; ++i) {
        used.assign(vertexes + 1, false);

        Kuhn(i, graph, used, match);
    }

    PrintMatching(match, pivot);
}
