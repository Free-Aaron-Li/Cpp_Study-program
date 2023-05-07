/**
 * @author AaronLi
 * @date 2023-05-07-下午8:44
 * @license GPL-3.0
 */
#include "adjacencylist.hpp"

void Graph_AL::CreateALGraph(ALGraph &graph) {
    std::cout << "请输入图的总顶点数和总边数：";
    std::cin >> graph.vertex_number >> graph.arc_number;
    std::cout << "请依次输入各顶点的信息：\n";
    for (int i = 0; i < graph.vertex_number; i++) {
        std::cin >> graph.vertices[i].data;
        graph.vertices[i].first_arc = nullptr;   /* 初始化表头节点的指针域为nullptr */
    }
    std::cout << "请依次输入一条边依附顶点，例如 a b：\n";
    for (int k = 0; k < graph.arc_number; ++k) {
        VertexType vertex_1, vertex_2;
        int i, j;

        while (std::cin >> vertex_1 >> vertex_2) {
            /* 获取顶点的下标 */
            i = LocateVex(graph, vertex_1);
            j = LocateVex(graph, vertex_2);

            auto *p1 = new ArcNode;
            p1->adjacent_vertex = j;
            p1->next_arc = graph.vertices[i].first_arc;
            graph.vertices[i].first_arc = p1;

            auto *p2 = new ArcNode;
            p2->adjacent_vertex = i;
            p2->next_arc = graph.vertices[j].first_arc;
            graph.vertices[j].first_arc = p2;
            if (std::cin.get() == '\n') break;
        }
    }
}


int Graph_AL::LocateVex(ALGraph &graph, VertexType &vertex) {
    for (int i = 0; i < sizeof(graph.vertices) / sizeof(graph.vertices[0]); ++i) {
        if (vertex == graph.vertices[i].data)
            return i;
    }
    return -1;
}

/* TODO 23-5-7:  打印邻接表 */
void Graph_AL::PrintAMGraph(ALGraph &graph) {

}

void Graph_AL::DepthFirstSearch_AL(ALGraph &graph, int index) {
    std::cout << graph.vertices[index].data;
    visited[index] = true;
    if (graph.vertex_number != point) {
        std::cout << "->";
        point++;
    }

    /* 指定v边链表的第一个边节点 */
    ArcNode *p = graph.vertices[index].first_arc;
    while (p != nullptr) {
        int w = p->adjacent_vertex;
        if (!visited[w]) DepthFirstSearch_AL(graph, w);
        p = p->next_arc;
    }
}

void Graph_AL::BreadthFirstSearch_AL(ALGraph &graph, int index) {
    std::queue<int> queue;
    queue.push(index);
    visited[index] = true;

    while (!queue.empty()) {
        int value = queue.front();
        std::cout << graph.vertices[value].data;
        if (graph.vertex_number != point) {
            std::cout << "->";
            point++;
        }
        queue.pop();
        for (int i = 0; i < graph.vertex_number; ++i) {
            if (!visited[i]) {
                queue.push(i);
                visited[i] = true;
            }
        }
    }
}

void Graph_AL::init_visited() {
    for (bool &i: visited) {
        i = false;
    }
}
