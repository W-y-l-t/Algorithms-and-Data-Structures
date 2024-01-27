/*
* Time Complexity: O(V + E),
 * where V - count of vertexes,
 * E - count of edges in graph
 *
 * Auxiliary Space: O(V)
 */

#include <iostream>
#include <cinttypes>
#include <vector>

void IsBiparite(size_t current,
                uint8_t color,
                const std::vector<std::vector<uint32_t>> &graph,
                std::vector<uint8_t> &colors) {

    colors[current] = color;
    for (auto &next : graph[current]) {
        if (colors[next] == 0) {
            IsBiparite(next, color == 1 ? 2 : 1, graph, colors);
        } else if (colors[next] == color) {
            std::cout << "ISN`T BIPARiTE" << std::endl;
            exit(0);
        }
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
        graph[to].push_back(from);
    }

    std::vector<uint8_t> colors(vertexes + 1, 0);

    for (size_t i = 1; i <= vertexes; ++i) {
        if (colors[i] == 0) {
            IsBiparite(i, 1, graph, colors);
        }
    }

    std::cout << "BIPARITE" << std::endl;
}
