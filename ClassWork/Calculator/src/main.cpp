// Created by AaronLi
// This program is used to complete integer operations,
// which include addition, subtraction, multiplication, division, set of operations, absolute values, and squared
// operations.
//
// Copyright (C) 2023 AaronLi
//
// Feel free to use it, the program follows the GPL-3.0 license.
// If you find bug, or you can't find the GPL-3.0 license backup, please contact me: <fly_aaron.li@outlook.com>
#include <iostream>
#include <stack>

/** 存储操作数 */
std::stack<double> numbers;
/** 存储运算符 */
std::stack<char> operations;
/** 绝对值符标记 */
int label = 0;
/** 优先级表单<br>
 * 优先级规则：绝对值符号>平方号>(* /)>(+ -)>(# 换行符) */
int priority(char operate) {
    switch (operate) {
            /** #作为栈顶元素，用于确定栈底 */
        case '#':
        case '\n': return 0;
        case '(':
        case ')': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 3;
        case '^': return 4;
        case '|': return 5;
        default:;
    }
    return 0;
}

/** 定义calculate函数 */
void calculate(char);

int  main() {
    std::cout << "计算器\n"
              << "欢迎使用本程序，您可以输入基础运算符+-*/、绝对值符号|、括号()和平方号^。如果您想要退出，请输入q。\n"
              << ": ";
    /** 强制类型转换，get()方法获取的是int类型值，强制类型转换为char类型 */
    char command = static_cast<char>(std::cin.get());
    while (command != 'q') {
        calculate(command);
        if (command == '\n') /** 计算式输入口 */
            std::cout << "\n: ";
        command = static_cast<char>(std::cin.get());
    }
    return 0;
}

/** 运算函数 */
void calculate(char command) {

    /**
     * num：操作数临时值<br>
     * leftNum：运算符左操作数临时值<br>
     * rightNum：运算符右操作数临时值<br>
     * result：计算式终值
     * */
    double num, leftNum, rightNum, result;

    switch (command) {
        /** 如果输入值为操作数，存入操作数栈 */
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': {
            std::cin.putback(command);
            std::cin >> num;
            numbers.push(num);
            break;
        }

        /** 如果输入值为运算符，存入运算符栈 */
        case '(':
        case ')':
        case '^':
        case '|':
        case '+':
        case '-':
        case '*':
        case '/':
        case '\n': {

            /** 初始化运算符栈 */
            if (operations.empty()) operations.push('#');

            /** 如果构成绝对值，删除绝对值前运算符及负号 */
            if (label == 1 && command == '|') {
                label = 0;
                operations.pop();
                operations.pop();
                break;
            }

            /** 标记右绝对值符 */
            if (command == '|') label = 1;

            /** 判断运算符优先级，若优先级高于前运算符或运算符为“(”，存储运算符 */
            if (priority(command) > priority(operations.top()) || command == '(') operations.push(command);

            /** 若前一运算符优先级高于输入运算符，进行运算符计算 */
            else {
                while (priority(command) <= priority(operations.top())) {

                    /** 括号运算符实现，删除左括号且读取下一字符 */
                    if (operations.top() == '(' && command == ')') {
                        operations.pop();
                        std::cin >> command;
                        break;
                    }

                    /** 对运算符减号和负号进行判断，如果为负号则存储于运算符栈中 */
                    if (command == '-' && operations.top() == '|') {
                        operations.push('-');
                        break;
                    }

                    /** 对操作数与其组成的运算符进行计算，分别有加、减、乘、除、平方 */
                    else {
                        /** 获取运算符左右操作数并从操作数栈中推出 */
                        rightNum = numbers.top();
                        numbers.pop();
                        leftNum = numbers.top();
                        numbers.pop();

                        /** 选择计算方式 */
                        switch (operations.top()) {
                            case '+':
                                numbers.push(leftNum + rightNum);
                                operations.pop();
                                break;
                            case '-': {
                                numbers.push(leftNum - rightNum);
                                operations.pop();
                                break;
                            }
                            case '*':
                                numbers.push(leftNum * rightNum);
                                operations.pop();
                                break;
                            case '/':
                                numbers.push(leftNum / rightNum);
                                operations.pop();
                                break;
                            case '^': {
                                int temporary   = static_cast<int>(leftNum);
                                int last_number = 1;
                                for (int i = 0; i < static_cast<int>(rightNum); ++i) {
                                    last_number *= temporary;
                                }
                                numbers.push(static_cast<int>(last_number));
                                operations.pop();
                                break;
                            }
                            default:;
                        }
                    }

                    /** 当输入字符为换行符且运算符栈无运算符，输出终值 */
                    if (operations.top() == '#' && command == '\n') {
                        result = numbers.top();
                        std::cout << "==>" << result << "\n";
                        numbers.pop();
                        operations.pop();
                        break;
                    }
                }

                /** 如果运算符优先级过低，自动提升优先级并存储于运算符栈 */
                if (command != '\n' && label != 1) operations.push(command);
            }
            break;
        }
        default:
            /** 对不属于操作数和运算符的值进行报错 */
            if (priority(command) == -1) {
                std::cout << "您输入有误！";
                return;
            }
    }
}
