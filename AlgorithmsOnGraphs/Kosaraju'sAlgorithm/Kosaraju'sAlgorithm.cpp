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
#include <iterator>
#include <algorithm>

template<typename T>
std::ostream& operator<<(std::ostream &out, std::vector<T> &data) {
    std::ranges::copy(data, std::ostream_iterator<T>(out, " "));

    return out;
}

void TopSort(uint32_t current,
             std::vector<std::vector<uint32_t>> &graph,
             std::vector<bool> &used,
             std::vector<uint32_t> &order) {

    if (!used[current]) {
        used[current] = true;

        for (auto &next : graph[current]) {
            TopSort(next, graph, used, order);
        }

        order.push_back(current);
    }
}

void GetSCC(uint32_t current,
            std::vector<std::vector<uint32_t>> &reversed_graph,
            std::vector<bool> &used,
            std::vector<uint32_t> &component) {

    if (!used[current]) {
        component.push_back(current);

        used[current] = true;

        for (auto &next : reversed_graph[current]) {
            GetSCC(next, reversed_graph, used, component);
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
    std::vector<std::vector<uint32_t>> reversed_graph(vertexes + 1,
                                                      std::vector<uint32_t>(0));

    for (size_t i = 0; i < edges; ++i) {
        uint32_t from;
        uint32_t to;

        std::cin >> from;
        std::cin >> to;

        graph[from].push_back(to);
        reversed_graph[to].push_back(from);
    }

    std::vector<bool> used(vertexes + 1, false);
    std::vector<uint32_t> order(0);

    for (size_t i = 1; i <= vertexes; ++i) {
        if (!used[i]) {
            TopSort(i, graph, used, order);
        }
    }

    used.assign(vertexes + 1, false);
    std::vector<uint32_t> component(0);

    for (size_t i = 1; i <= vertexes; ++i) {
        uint32_t now = order[vertexes - i];
        if (!used[now]) {
            GetSCC(now, reversed_graph, used, component);

            std::cout << component << std::endl;

            component.clear();
        }
    }
}
