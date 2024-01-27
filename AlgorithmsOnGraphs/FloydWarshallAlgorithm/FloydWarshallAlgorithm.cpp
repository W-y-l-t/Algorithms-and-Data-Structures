/*
 * Time Complexity: O(V^3),
 * where V - count of vertexes,
 *
 * Auxiliary Space: O(1)
 */

#include <iostream>
#include <cinttypes>
#include <vector>
#include <queue>

void FloydWarshall(size_t vertexes, std::vector<std::vector<uint32_t>> &graph) {
    for (size_t i = 0; i < vertexes; ++i) {
        for (size_t j = 0; j < vertexes; ++j) {
            for (size_t k = 0; k < vertexes; ++k) {
                if (i == j) {
                    continue;
                }

                graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main() {
    size_t vertexes;

    std::cin >> vertexes;

    std::vector<std::vector<uint32_t>> graph(vertexes,
                                            std::vector<uint32_t>(vertexes));

    for (size_t i = 0; i < vertexes; ++i) {
        for (size_t j = 0; j < vertexes; ++j) {
            std::cin >> graph[i][j];
        }
    }
    for (size_t i = 0; i < vertexes; ++i) {
        for (size_t j = 0; j < vertexes; ++j) {
            graph[i][j] = (graph[i][j] < 0 ? UINT16_MAX : graph[i][j]);
        }
    }

    FloydWarshall(vertexes, graph);

    uint32_t from;
    uint32_t to;

    std::cin >> from;
    std::cin >> to;

    uint64_t path_length = graph[from - 1][to - 1];
    std::cout << path_length << std::endl;
}
