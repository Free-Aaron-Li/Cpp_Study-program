/**
 * @author AaronLi
 * @date 2023-04-16-上午11:37
 * @license GPL-3.0
 */
#include "orderofjudgment.hpp"

void Judgment::InitJudgment(Queue &queue) {
    SequentialQueue::InitQueue(&queue);
}

int Judgment::PushQueue(Queue &queue) {
    ElemType value;
    int index = 0;
    std::cout << "请输入猜测的出栈顺序链（包含0）：";
    while (std::cin >> value) {
        SequentialQueue::EnQueue(queue, value);
        if (std::cin.get() == '\n')break;
        ++index;
    }
    std::cout << "队列元素为：\n";
    SequentialQueue::PrintQueue(queue);
    return index;
}

void Judgment::JudgmentStack(Queue &queue) {
    Stack stack{};
    /** 输入链长度 */
    int length = PushQueue(queue);
    /** 栈索引（/入栈元素） */
    ElemType index = 0;
    /** 出队元素 */
    ElemType element = 0;

    SequentialStack::Push(&stack, index);
    while (index <= length) {
        if (stack.data[stack.top] != queue.data[queue.front]) {
            SequentialStack::Push(&stack, ++index);
        } else {
            SequentialQueue::DeQueue(queue, element);
            SequentialStack::Pop(&stack, element);
        }
    }
    if (queue.front == queue.rear) {
        std::cout << "YES\n";
    } else std::cout << "NO\n";
}
