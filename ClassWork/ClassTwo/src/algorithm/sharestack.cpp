/**
 * @author AaronLi
 * @date 2023-04-16-上午11:39
 * @license GPL-3.0
 */
#include "sharestack.hpp"

void ShareStack::InitShareStack(Stack &stack) {
    int index = 0;
    while (index < MAXSIZE) {
        stack.data[index++] = 0;
    }
}

Status ShareStack::ShareStackIsFull(Stack &stack) const {
    if (top_2 - top_1 == 1) {
        return OK;
    } else return ERROR;
}

Status ShareStack::PushOneStack(Stack &stack, ElemType &value) {
    if (ShareStackIsFull(stack)) {
        std::cerr << "栈满！\n";
        return ERROR;
    }

    stack.data[++top_1] = value;
    return OK;
}

Status ShareStack::PushTwoStack(Stack &stack, ElemType &value) {
    if (ShareStackIsFull(stack)) {
        std::cerr << "栈满！\n";
        return ERROR;
    }

    stack.data[--top_2] = value;
    return OK;
}

Status ShareStack::PopOneStack(Stack &stack, ElemType &value) {
    if (top_1 == -1) {
        std::cerr << "栈1为空！\n";
        return ERROR;
    }

    value = stack.data[top_1];
    stack.data[top_1] = 0;
    top_1--;
    return OK;
}

Status ShareStack::PopTwoStack(Stack &stack, ElemType &value) {
    if (top_2 == MAXSIZE) {
        std::cerr << "栈2为空！\n";
        return ERROR;
    }

    value = stack.data[top_2];
    stack.data[top_2] = 0;
    top_2++;
    return OK;
}

void ShareStack::PrintShareStack(Stack &stack) {
    int index = 0;
    while (index < MAXSIZE) {
        std::cout << stack.data[index] << " ";
        index++;
    }
    std::cout << "\n";
}

