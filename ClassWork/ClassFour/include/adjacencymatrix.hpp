//
// Created by AaronLi on 23-5-2.
//

#ifndef CLASSWORK_ADJACENCYMATRIX_HPP
#define CLASSWORK_ADJACENCYMATRIX_HPP

/**
 * @title
 * <p> 邻接矩阵——无向表 </P>
 */

#include <iostream>
#include <queue>

/**
 * 边权值，默认无穷值0
 */
#define Infinite 0
/**
 * 最大顶点数
 */
#define MAXNUMBER 100
/**
 * @title
 * <p> 图顶点 </P>
 * @description
 *  默认数据类型为char
 */
typedef char VertexType;

/**
 * @title
 * <p> 边权值 </P>
 * @description
 *  默认数据类型为int
 */
typedef int ArcType;

/**
 * @title
 * <p> 元素类型 </P>
 * @description
 *  默认为int
 */
typedef int ElementType;

/**
 * @title
 * <p> 邻接矩阵图(Adjacency Matrix Graph AMGraph) </P>
 * @param
 *  
 */
typedef struct {
    /**
     * 顶点表
     */
    VertexType vertex[MAXNUMBER];
    /**
     * 邻接矩阵
     */
    ArcType arcs[MAXNUMBER][MAXNUMBER];
    /**
     * 图的当前点数
     */
    ElementType vertex_number;
    /**
     * 图的当前边数
     */
    ElementType arc_number;
} AMGraph;

/**
 * @title
 * <p> 邻接矩阵图 </P>
 * @description
 */
class Graph_AM {
public:
    /**
     * 被访问顶点标记
     */
    bool visited[MAXNUMBER]{};
    /**
     * 累计点
     * */
    int point = 1;
public:

    /**
     * @title
     * <p> 初始化顶点标记 </P>
     */
    void init_visited();

    /**
     * @title
     * <p> 顶点定位 </P>
     * @description
     *  获取目标顶点位于顶点图的下标值
     * @param
     *  graph 顶点图对象
     * @param
     *  vertex 顶点元素值
     */
    static ElementType LocateVex(AMGraph &graph, VertexType &vertex);

/**
 * @title
 * <p> 创建邻接矩阵图 </P>
 * @param
 *  graph 邻接矩阵对象
 */
    static void CreateAMGraph(AMGraph &graph);

/**
 * @title
 * <p> 打印邻接矩阵 </P>
 * @param
 *  graph  邻接矩阵对象
 */
    static void PrintAMGraph(AMGraph &graph);

    /**
     * @title
     * <p> 邻接矩阵的深度优先搜索遍历 </P>
     * @description
     *  深度优先遍历邻接矩阵，从index个顶点出发遍历
     * @param
     *  graph  邻接矩阵对象
     * @param
     *  index  顶点顺序值
     */
    void DepthFirstSearch_AM(AMGraph &graph, int index);

    /**
     * @title
     * <p> 邻接矩阵的广度优先搜索遍历 </P>
     * @description
     *   从index个顶点开始进行遍历
     * @param
     *  graph  邻接矩阵对象
     * @param
     *  index  顶点位置值
     */
    void BreadthFirstSearch_AM(AMGraph &graph, int index);

    /**
     * @title
     * <p> 查询第index顶点的第一个邻接点 </P>
     * @param
     *  graph  邻接矩阵对象
     * @param
     *  index  顶点位置值
     */
    int FirstAdjVex_AM(AMGraph &graph, int index);

    /**
     * @title
     * <p> 查询第index顶点的下一个节点 </P>
     * @param
     *  graph  邻接矩阵对象
     * @param
     *  front_value 顶点位置值
     * @param
     *  index   第一个邻接点的位置值
     */
    int NextAdjVex_AM(AMGraph &graph, int front_value, int index);

};

#endif //CLASSWORK_ADJACENCYMATRIX_HPP
