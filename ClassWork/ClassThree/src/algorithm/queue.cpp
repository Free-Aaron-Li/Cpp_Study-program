/**
 * @author AaronLi
 * @date 2023-04-16-下午12:42
 * @license GPL-3.0
 */
#include "queue.hpp"

void SequentialQueue::InitQueue(Queue *queue) {
    queue->data = new ElemType[MAXSIZE];
    queue->rear = 0;
    queue->front = 0;
}

Status SequentialQueue::QueueIsEmpty(Queue *queue) {
    if (queue->front == queue->rear) {
        return OK;
    } else return ERROR;
}

Status SequentialQueue::QueueIsFull(Queue *queue) {
    if (queue->rear == MAXSIZE - 1) {
        return OK;
    } else return ERROR;
}

Status SequentialQueue::EnQueue(Queue &queue, ElemType &value) {
    if (QueueIsFull(&queue)) {
        return ERROR;
    }

    queue.data[queue.rear++] = value;
    return OK;
}

Status SequentialQueue::DeQueue(Queue &queue, ElemType &value) {
    if (QueueIsEmpty(&queue)) {
        return ERROR;
    }

    value = queue.data[queue.front++];
    return OK;
}

void SequentialQueue::PrintQueue(Queue &queue) {
    if (QueueIsEmpty(&queue)) {
        return;
    } else {
        for (int i = queue.front; i < queue.rear; ++i) {
            std::cout << queue.data[i] << " ";
        }
    }
    std::cout << std::endl;
}

ElemType SequentialQueue::GetQueueHeader(Queue &queue) {
    return queue.data[queue.front];
}
