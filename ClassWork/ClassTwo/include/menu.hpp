//
// Created by AaronLi on 23-4-16.
//

#ifndef CLASSWORK_MENU_HPP
#define CLASSWORK_MENU_HPP

/**
 * @title
 * <p> 主菜单 </P>
 */

#include "baseconversion.hpp"
#include "orderofjudgment.hpp"
#include "sharestack.hpp"

class Menu {
public:

    /**
     * @title
     * <p> 菜单选项 </P>
     */

    static void MenuOption();

    /**
     * @title
     * <p> 分割线 </P>
     */

    static void DividingLine();

    /**
     * @title
     * <p> 菜单 </P>
     * @param
     */

    void MenuJudgment();

    /**
     * @title
     * <p> 退出选项 </P>
     */

    static Status ExitOption();

    /**
     * @title
     * <p> 进制转换选项 </P>
     */
    static Status BaseConversionOption();

    /**
     * @title
     * <p> 共享栈选项 </P>
     */

    Status ShareStackOption();
    
    /**
     * @title
     * <p> 判断出栈顺序 </P>
     */
    
    Status OrderOfJudgmentOption();
};

#endif //CLASSWORK_MENU_HPP
