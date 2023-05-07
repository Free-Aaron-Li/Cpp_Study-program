/**
 * @author AaronLi
 * @date 2023-05-07-下午11:05
 * @license GPL-3.0
 */
#include "panel.hpp"

void Panel::Menu() {
    std::cout << "-------------------------------\n"
                 "**********图的建立与遍历**********\n"
                 "1.邻接矩阵建立图\n"
                 "2.邻接表建立图\n"
                 "3.退出\n"
                 "请选择您要建立的图的类型：";
}


void Panel::AlgorithmMenu() {
    std::cout << "------------------------\n"
                 "1.深度优先搜索遍历\n"
                 "2.广度优先搜索遍历\n"
                 "3.退出\n"
                 "请选择您要使用的算法：";
}

int Panel::RunMatrix() {
    std::cin.sync();
    AlgorithmMenu();
    int number;
    std::cin >> number;
    AMGraph am_graph;
    Graph_AM graph{};
    if (number == 1) {
        Graph_AM::CreateAMGraph(am_graph);
        std::cout << "\n";
        Graph_AM::PrintAMGraph(am_graph);
        graph.DepthFirstSearch_AM(am_graph, 0);
        std::cout << "\n";
        return 0;
    } else if (number == 2) {
        Graph_AM::CreateAMGraph(am_graph);
        std::cout << "\n";
        graph.init_visited();
        Graph_AM::PrintAMGraph(am_graph);
        graph.BreadthFirstSearch_AM(am_graph, 0);
        std::cout << "\n";
        return 0;
    } else if (number == 3) {
        std::cout << "Goodbye!";
        return 0;
    }
    return -1;
}

int Panel::RunList() {
    AlgorithmMenu();
    ALGraph al_graph{};
    Graph_AL graph{};
    int number;
    std::cin >> number;
    if (number == 1) {
        Graph_AL::CreateALGraph(al_graph);
        graph.DepthFirstSearch_AL(al_graph, 0);
        std::cout << "\n";
        return 0;
    } else if (number == 2) {
        Graph_AL::CreateALGraph(al_graph);
        graph.init_visited();
        graph.BreadthFirstSearch_AL(al_graph, 0);
        std::cout << "\n";
        return 0;
    } else if (number == 3) {
        std::cout << "Goodbye!";
        return 0;
    }
    return -1;
}


void Panel::Run() {
    Start:
    Menu();
    int number;
    std::cin >> number;
    if (number == 1) {
        RunMatrix();
    } else if (number == 2) {
        RunList();
    } else if (number == 3) {
        std::cout << "GoodBye!";
        return;
    }
    goto Start;
}
