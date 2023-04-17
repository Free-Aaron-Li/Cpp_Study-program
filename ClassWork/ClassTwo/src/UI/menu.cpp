/**
 * @author AaronLi
 * @date 2023-04-16-下午2:43
 * @license GPL-3.0
 */
#include "menu.hpp"

void Menu::MenuOption() {
    std::cout << "\n************************************\n"
              << "* ①、题目一：进制转换                 \n"
              << "* ②、题目二：共享栈                   \n"
              << "* ③、题目三：判断出栈顺序              \n"
              << "* ④、退出                           \n"
              << "***********************************\n";
}

void Menu::MenuJudgment() {
    /** 选项值 */
    int option = 0;

    MenuOption();
    Start:
    std::cout << "请输入您想要进行的程序编号（1~4）：";
    std::cin >> option;
    if (option / 4 != 0 && option / 4 != 1 && option != 0) {
        std::cerr << "您输入的程序编号错误，请重新输入！\n";
        goto Start;
    }
    switch (option) {
        case 1:
            BaseConversionOption();
            MenuJudgment();
            break;
        case 2:
            ShareStackOption();
            MenuJudgment();
            break;
        case 3:
            OrderOfJudgmentOption();
            MenuJudgment();
            break;
        case 4:
            if (ExitOption()) {
                return;
            }
            MenuJudgment();
        default:
            std::cerr << "输入选项编号错误！\n";
            goto Start;
    }

}

Status Menu::ExitOption() {
    char temporary;
    std::cout << "是否确认？（y/n）：";
    std::cin >> temporary;
    if (temporary == 'y' || temporary == 'Y') {
        return OK;
    } else return ERROR;
}

bool BinaryConversionUI() {
    Stack stack_a = BaseConversion::InitBaseConversion();
    std::cout << "请输入你想要转换的十进制值：";
    ElemType value_a = 0;
    std::cin >> value_a;
    BaseConversion::BinaryConversion(stack_a, value_a);
    std::cout << "转换得到的二进制值为：";
    BaseConversion::PrintConversionValue(stack_a);
    return true;
}

bool HexadecimalConversionUI() {
    Stack stack_b{};
    stack_b = BaseConversion::InitBaseConversion();
    std::cout << "请输入你想要转换的十进制值：";
    int value_b;
    value_b = 0;
    std::cin >> value_b;
    BaseConversion::HexadecimalConversion(stack_b, value_b);
    std::cout << "转换得到的十六进制值为：";
    BaseConversion::PrintConversionValue(stack_b);
    return true;
}

Status Menu::BaseConversionOption() {
    DividingLine();
    std::cout << "请选择那种进制转换？\n"
              << "a.十进制转二进制\n"
              << "b.十进制转十六进制\n"
              << "c.退出\n"
              << "请输入选项（a/b/c）：";
    char option;
    std::cin >> option;
    if (option != 'a' && option != 'b' && option != 'c') {
        DividingLine();
        std::cerr << "您输入的选项错误！请重新输入";
        DividingLine();
        BaseConversionOption();
    }

    switch (option) {
        case 'a':
            BinaryConversionUI();
            BaseConversionOption();
            break;
        case 'b':
            HexadecimalConversionUI();
            BaseConversionOption();
            break;
        case 'c':
            if (ExitOption()) {
                return ERROR;
            }
            BaseConversionOption();
            break;
    }
    return OK;
}

void Menu::DividingLine() {
    std::cout << "\n***********************************\n";
}

Status Menu::ShareStackOption() {
    Stack stack{};
    ShareStack shareStack;
    ElemType value;
    ShareStack::InitShareStack(stack);
    std::cout << "请输入栈1的顺序链：";
    while (std::cin >> value) {
        shareStack.PushOneStack(stack, value);
        if (std::cin.get() == '\n')break;
    }
    std::cout << "请输入栈2的顺序链：";
    while (std::cin >> value) {
        shareStack.PushTwoStack(stack, value);
        if (std::cin.get() == '\n')break;
    }
    std::cout << "共享栈的元素为：\n";
    ShareStack::PrintShareStack(stack);
    std::cout << "是否选择出栈元素？\n";
    if (ExitOption()) {
        State_ShareStack_1:
        /** 出栈索引 */
        int index = 1;
        /** 出栈元素 */
        ElemType value_1 = 0;
        std::cout << "请输入出栈1元素个数（从1开始）：";
        int number_1 = 0;
        std::cin >> number_1;
        if (number_1 - shareStack.top_1 >= 2) {
            std::cerr << "入栈元素未有" << number_1 << "个"
                      << "请重新输入！\n";
            goto State_ShareStack_1;
        }
        while (index <= number_1) {
            shareStack.PopOneStack(stack, value_1);
            index++;
        }
        Start_ShareStack_2:
        std::cout << "请输入出栈2元素个数（从1开始）：";
        int number_2 = 0;
        std::cin >> number_2;
        if ((MAXSIZE - shareStack.top_2) - number_2 < 0) {
            std::cerr << "入栈元素未有" << number_1 << "个"
                      << "请重新输入！\n";
            goto Start_ShareStack_2;
        }
        index = 0;
        while (index < number_2) {
            shareStack.PopTwoStack(stack, value_1);
            index++;
        }
        std::cout << "共享栈的元素为：\n";
        ShareStack::PrintShareStack(stack);
    }
    std::cout << "是否选择退出？\n";
    if (!ExitOption()) {
        DividingLine();
        ShareStackOption();
    }
    return OK;
}

Status Menu::OrderOfJudgmentOption() {
    Judgment judgment;
    Queue queue{};

    Judgment::InitJudgment(queue);
    judgment.JudgmentStack(queue);

    std::cout << "是否选择退出？\n";
    if (!ExitOption()) {
        DividingLine();
        OrderOfJudgmentOption();
    }
    return OK;
}


