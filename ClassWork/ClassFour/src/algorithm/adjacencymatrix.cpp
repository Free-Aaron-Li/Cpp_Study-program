/**
 * @author AaronLi
 * @date 2023-05-02-下午8:47
 * @license GPL-3.0
 */
#include "adjacencymatrix.hpp"

void Graph_AM::CreateAMGraph(AMGraph &graph) {
    std::cout << "请输入邻接矩阵的总顶点数和总边数：";
    std::cin >> graph.vertex_number >> graph.arc_number;
    std::cout << "请依次输入各顶点信息：\n";
    for (int i = 0; i < graph.vertex_number; ++i) {
        std::cin >> graph.vertex[i];
    }

    /* 初始化邻接矩阵，将所有边的权值设置为极大值 */
    for (int i = 0; i < graph.vertex_number; ++i) {
        for (int j = 0; j < graph.vertex_number; ++j) {
            graph.arcs[i][j] = Infinite;
        }
    }

    /* 构建邻接矩阵 */
    std::cout << "请依次输入一条边依附顶点及权值，例如 a b 4：\n";
    for (int k = 0; k < graph.arc_number; ++k) {
        VertexType vertex_1, vertex_2;
        ArcType arc_number;
        ElementType i, j;

        while (std::cin >> vertex_1 >> vertex_2 >> arc_number) {
            /* 确定顶点vertex_1和顶点vertex_2位于邻接矩阵的位置（数组下标）*/
            i = LocateVex(graph, vertex_1);
            j = LocateVex(graph, vertex_2);

            /* 设置邻接矩阵（无向表）权值 */
            graph.arcs[i][j] = arc_number;
            graph.arcs[j][i] = graph.arcs[i][j];
            if (std::cin.get() == '\n') break;
        }
    }
}

ElementType Graph_AM::LocateVex(AMGraph &graph, VertexType &vertex) {
    for (int i = 0; i < sizeof(graph.vertex) / sizeof(graph.vertex[0]); ++i) {
        if (vertex == graph.vertex[i])
            return i;
    }
    return -1;
}

void Graph_AM::PrintAMGraph(AMGraph &graph) {
    for (int i = 0; i < graph.vertex_number; ++i) {
        for (int j = 0; j < graph.vertex_number; ++j) {
            std::cout << graph.arcs[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void Graph_AM::DepthFirstSearch_AM(AMGraph &graph, int index) {
    /** 累计点 */
    std::cout << graph.vertex[index];
    if (graph.vertex_number != point) {
        std::cout << "->";
        point++;
    }
    visited[index] = true;
    for (int i = 0; i < graph.vertex_number; ++i) {
        /* 使用i表示第index个顶点的邻接点，若邻接点从未被访问，则递归调用 */
        if ((graph.arcs[index][i] != Infinite) && (!visited[i])) DepthFirstSearch_AM(graph, i);
    }
}

void Graph_AM::BreadthFirstSearch_AM(AMGraph &graph, int index) {
    std::queue<int> queue;
    queue.push(index);
    visited[index] = true;

    while (!queue.empty()) {
        int value = queue.front();
        std::cout << graph.vertex[value];
        if (graph.vertex_number != point) {
            std::cout << "->";
            point++;
        }
        queue.pop();
        for (int i = 0; i < graph.vertex_number; ++i) {
            if (graph.arcs[value][i] != Infinite && !visited[i]) {
                queue.push(i);
                visited[i] = true;
            }
        }
    }
}


void Graph_AM::init_visited() {
    for (bool &i: visited) {
        i = false;
    }
}
