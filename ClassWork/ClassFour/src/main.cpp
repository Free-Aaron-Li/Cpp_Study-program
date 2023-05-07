/**
 * @author AaronLi
 * @date 2023-04-24-下午8:25
 * @license GPL-3.0
 */
#include "adjacencymatrix.hpp"
#include "adjacencylist.hpp"

int main() {
    AMGraph am_graph;
    Graph_AM graph{};
    Graph_AM::CreateAMGraph(am_graph);
    std::cout << "\n";
    //Graph_AM::PrintAMGraph(am_graph);
    std::cout << "邻接矩阵表示法：\n";
    graph.DepthFirstSearch_AM(am_graph, 0);
    //graph.init_visited();
    //graph.BreadthFirstSearch_AM(am_graph, 0);

    ALGraph al_graph{};
    Graph_AL graph_al{};
    //Graph_AL::CreateALGraph(al_graph);
    //graph_al.DepthFirstSearch_AL(al_graph, 0);
    //graph_al.init_visited();
    //graph_al.BreadthFirstSearch_AL(al_graph, 0);
}