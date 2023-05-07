/**
 * @author AaronLi
 * @date 2023-04-24-下午8:25
 * @license GPL-3.0
 */
#include "adjacencymatrix.hpp"

int main() {
    AMGraph amGraph;
    Graph_AM graph{};
    Graph_AM::CreateAMGraph(amGraph);
    std::cout << "\n";
    Graph_AM::PrintAMGraph(amGraph);
    graph.DepthFirstSearch_AM(amGraph, 0);
    graph.init_visited();
    graph.BreadthFirstSearch_AM(amGraph, 0);
}