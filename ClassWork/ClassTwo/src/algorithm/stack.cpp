/**
 * @author AaronLi
 * @date 2023-04-16-下午12:41
 * @license GPL-3.0
 */
#include "stack.hpp"

Status SequentialStack::StackIsEmpty(Stack *stack) {
    if (stack->top == -1) {
        return OK;
    } else return ERROR;
}

Status SequentialStack::StackIsFull(Stack *stack) {
    if (stack->top == MAXSIZE - 1) {
        return OK;
    } else return ERROR;
}

Status SequentialStack::Push(Stack *stack, ElemType &value) {
    if (StackIsFull(stack)) {
        return ERROR;
    }

    stack->data[++stack->top] = value;
    return OK;
}

Status SequentialStack::Pop(Stack *stack, ElemType &value) {
    if (StackIsEmpty(stack)) {
        return ERROR;
    }

    value = stack->data[stack->top--];
    return OK;
}

Status SequentialStack::GetTop(Stack *stack, ElemType &value) {
    if (StackIsEmpty(stack)) {
        return ERROR;
    }

    value = stack->data[stack->top];
    return OK;
}

void SequentialStack::PrintStack(Stack *stack) {
    while (stack->top != -1) {
        std::cout << stack->data[stack->top--] << " ";
    }
    std::cout << std::endl;
}


    
    
    