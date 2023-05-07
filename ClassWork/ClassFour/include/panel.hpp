//
// Created by AaronLi on 23-5-7.
//

#ifndef CLASSWORK_PANEL_HPP
#define CLASSWORK_PANEL_HPP

/**
 * @title
 * 显示菜单面板
 */

#include "adjacencylist.hpp"
#include "adjacencymatrix.hpp"

/* 菜单面板 */
class Panel {
public:
    /**
     * 主显示菜单
     */
    static void Menu();

    /**
     * 算法显示菜单
     */
    static void AlgorithmMenu();

    /**
     * 运行邻接矩阵表示法图
     */
    int RunMatrix();
    
    /**
     * 运行邻接表表示法图
     */
    int RunList();
    
    /**
     * 运行
     */
    void Run();
};

#endif //CLASSWORK_PANEL_HPP
