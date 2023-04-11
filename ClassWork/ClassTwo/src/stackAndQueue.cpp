/**
 * @author AaronLi
 * @date 2023-04-10-下午9:02
 * @license GPL-3.0
 */
#include "stack.hpp"
#include "queue.hpp"

void Exercise_SqStack::InitStack(SqStack &sqStack) {
    sqStack.top = ERROR;
}

bool Exercise_SqStack::IsEmpty(SqStack sqStack) {
    std::cout << "判断栈空的结果为：";
    if (sqStack.top == ERROR) {
        std::cout << "栈为空" << std::endl;
        return true;
    } else {
        std::cout << "栈不为空" << std::endl;
        return false;
    }
}

bool Exercise_SqStack::Push(SqStack &sqStack, ElemType &elemType) {
    /* 栈满 */
    if (sqStack.top == MAXSIZE - 1) {
        std::cerr << "栈已满！" << std::endl;
        return false;
    }

    sqStack.data[++sqStack.top] = elemType;
    return true;
}

ElemType Exercise_SqStack::Pop(SqStack &sqStack, ElemType &elemType) {
    /* 栈空 */
    if (sqStack.top == ERROR) {
        std::cerr << "栈为空！" << std::endl;
        return false;
    }

    elemType = sqStack.data[sqStack.top--];
    return elemType;
}

bool Exercise_SqStack::GetTop(SqStack sqStack, ElemType &elemType) {
    /* 栈空 */
    if (sqStack.top == ERROR) {
        std::cerr << "栈为空！" << std::endl;
        return false;
    }

    elemType = sqStack.data[sqStack.top];
    std::cout << "栈顶元素值为：" << elemType << std::endl;
    return true;
}

void Exercise_SqStack::PrintStack(SqStack sqStack) {
    std::cout << "栈中元素值为（自顶向下）：" << std::endl;
    while (sqStack.top != ERROR) {
        std::cout << sqStack.data[sqStack.top] << " ";
        sqStack.top--;
    }
    std::cout << std::endl;
}



void Exercise_Queue::InitiateQueue(Queue &queue) {
    if (!queue.data) {
        std::cerr << "队列基地址不存在" << std::endl;
        return;
    }
    queue.data = new ElemType[MAXSIZE];
    queue.rear = 0;
    queue.front = 0;
}

Status Exercise_Queue::isEmpty(Queue &queue) {
    if (queue.front == queue.rear) {
        std::cerr << "队列为空！" << std::endl;
        return OK;
    } else {
        return ERROR;
    }
}

Status Exercise_Queue::isFull(Queue &queue) {
    if (queue.rear == MAXSIZE - 1) {
        std::cerr << "队列已满！" << std::endl;
        return OK;
    } else {
        return ERROR;
    }
}

void Exercise_Queue::EnQueue(Queue &queue, ElemType &value) {
    if (!isFull(queue)) {
        std::cerr << "队列已满！无法再添加数据" << std::endl;
    }
    queue.data[queue.rear++] = value;
}

ElemType Exercise_Queue::DeQueue(Queue &queue, ElemType &value) {
    if (!isEmpty(queue)) {
        std::cerr << "队列已空！无法删除数据" << std::endl;
    }
    value = queue.data[queue.front++];
    return value;
}

void Exercise_Queue::PrintQueue(Queue &queue) {
    if (!isEmpty(queue)) {
        std::cerr << "队列为空！无法打印数据" << std::endl;
    } else {
        std::cout << "队列列表为：" << std::endl;
        for (int i = queue.front; i < queue.rear; ++i) {
            std::cout << queue.data[i] << " ";
        }
    }
    std::cout << std::endl;
}





