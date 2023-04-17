/**
 * @author AaronLi
 * @date 2023-04-16-上午11:37
 * @license GPL-3.0
 */
#include "baseconversion.hpp"

Status BaseConversion::BinaryConversion(Stack &stack, ElemType &value) {
    ElemType temporary = 0;
    while (value / 2 != 0) {
        temporary = value % 2;
        value /= 2;
        SequentialStack::Push(&stack, temporary);
    }
    SequentialStack::Push(&stack, value);
    return OK;
}

Status BaseConversion::HexadecimalConversion(Stack &stack, ElemType &value) {
    ElemType temporary = 0;
    while (value / 16 != 0) {
        temporary = value % 16;
        value /= 16;
        SequentialStack::Push(&stack, temporary);
    }
    SequentialStack::Push(&stack, value);
    return OK;
}

Stack BaseConversion::InitBaseConversion() {
    Stack stack{};
    SequentialStack::InitStack(&stack);
    return stack;
}

void BaseConversion::PrintConversionValue(Stack &stack) {
    while (SequentialStack::StackIsEmpty(&stack)) {
        return;
    }

    char temporary;
    while (stack.top != -1) {
        if (stack.data[stack.top] < 10) {
            std::cout << stack.data[stack.top];
        } else {
            temporary = (char) (stack.data[stack.top] - 10 + 'A');
            std::cout << temporary;
        }
        stack.top--;
    }
}
