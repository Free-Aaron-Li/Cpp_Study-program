/**
 * @author AaronLi
 * @date 2023-04-09-上午10:46
 * @license GPL-3.0
 */
#include "queue.hpp"
#include "stack.hpp"


void test_sqStack() {
    ElemType value_push, value_pop, value;
    SqStack sqStack;
    std::cout << "*******************************" << std::endl;
    std::cout << "*    Exercises for SqStack    *" << std::endl;
    std::cout << "*******************************" << std::endl;
    Exercise_SqStack::InitStack(sqStack);
    std::cout << "初始化栈··········" << std::endl;
    Exercise_SqStack::IsEmpty(sqStack);
    std::cout << "元素进栈··········" << std::endl;
    std::cout << "请输入进栈元素：";
    while (std::cin >> value_push) {
        Exercise_SqStack::Push(sqStack, value_push);
        if (std::cin.get() == '\n')break;
    }
    Exercise_SqStack::PrintStack(sqStack);
    std::cout << "*******************************" << std::endl;
    std::cout << "请输入出栈顺序列表：";
    while (std::cin >> value_pop) {
        if (value_pop != Exercise_SqStack::Pop(sqStack, value)) {
            std::cerr << "NO" << std::endl;
            return;
        }
        if (std::cin.get() == '\n')break;
    }
    std::cout << "YES" << std::endl;
}

void test_queue() {
    ElemType value_add, value_delete, value;
    Queue queue;
    std::cout << "*******************************" << std::endl;
    std::cout << "*     Exercises for Queue     *" << std::endl;
    std::cout << "*******************************" << std::endl;
    Exercise_Queue::InitiateQueue(queue);
    std::cout << "元素入队··········" << std::endl;
    std::cout << "请输入入队元素：";
    while (std::cin >> value_add) {
        Exercise_Queue::EnQueue(queue, value_add);
        if (std::cin.get() == '\n')break;
    }
    Exercise_Queue::PrintQueue(queue);
    std::cout << "*******************************" << std::endl;
    std::cout << "请输入出队顺序列表：";
    while (std::cin >> value_delete) {
        if (value_delete != Exercise_Queue::DeQueue(queue, value)) {
            std::cerr << "NO" << std::endl;
            return;
        }
        if (std::cin.get() == '\n')break;
    }
    std::cout << "YES" << std::endl;
}

int main() {
    std::cout << "*******************************" << std::endl;
    std::cout << "*    Exercise number three    *" << std::endl;
    std::cout << "*******************************" << std::endl;
    std::cout << "******************************************************" << std::endl;
    test_sqStack();
    test_queue();
    return 0;
}








