//
// Created by AaronLi on 23-5-7.
//

#ifndef CLASSWORK_ADJACENCYLIST_HPP
#define CLASSWORK_ADJACENCYLIST_HPP

/**
 * @title
 *  邻接表表示法无线图
 */

#include <iostream>
#include <queue>
#include <string>

/**
 * 边权值，默认无穷值0
 */
#define Infinite 0
/**
 * 最大顶点数
 */
#define MAXNUMBER 100
/**
 * 边信息类型
 */
typedef std::string OtherInfo;
/**
 * 邻接表结构类型
 */
typedef int AdjList;
/**
 * 顶点信息数据类型
 */
typedef char VertexType;

/**
 * 边节点
 */
typedef struct ArcNode {
    /**
     * 邻接顶点，指示与顶点v<sub>i</sub>邻接的点在图中的位置
     */
    int adjacent_vertex;
    /**
     *  链域，指示与顶点v<sub>i</sub>邻接的下一条边的节点
     */
    struct ArcNode *next_arc;
    /**
     * 数据域，存储与边相关的信息
     */
    OtherInfo info;
} ArcNode;

/**
 * 顶点信息
 */
struct VNode {
    /**
     * 顶点信息
     */
    VertexType data;
    /**
     * 指向第一条依附该顶点的边的指针
     */
    ArcNode *first_arc;
};

/**
 * 
 */
struct ALGraph {
    /**
     * 顶点
     */
    VNode vertices[MAXNUMBER];
    /**
     * 图的当前顶点数
     */
    int vertex_number;
    /**
     * 图的边数
     */
    int arc_number;
};

/**
 * @title
 * <p> 邻接表表示法无向图 </P>
 */
class Graph_AL {
public:
    /**
     * 被访问对象标记
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
    static int LocateVex(ALGraph &graph, VertexType &vertex);

    /**
     * @title
     * <p> 创建邻接表图 </P>
     * @param
     *  graph   邻接表图对象
     */
    static void CreateALGraph(ALGraph &graph);


/**
 * @title
 * <p> 打印邻接矩阵 </P>
 * @param
 *  graph  邻接矩阵对象
 */
    static void PrintAMGraph(ALGraph &graph);

    /**
     * @title
     * <p> 邻接表的深度优先搜索遍历 </P>
     * @param
     *  graph    邻接表图对象
     * @param
     *  index   顶点顺序值
     */
    void DepthFirstSearch_AL(ALGraph &graph, int index);


    /**
     * @title
     * <p> 邻接矩阵的广度优先搜索遍历 </P>
     * @param
     *  graph  邻接矩阵对象
     * @param
     *  index  顶点位置值
     */
    void BreadthFirstSearch_AL(ALGraph &graph, int index);

};

#endif //CLASSWORK_ADJACENCYLIST_HPP
