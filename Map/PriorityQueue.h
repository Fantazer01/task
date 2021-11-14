//
// Created by oleg on 08.11.2021.
//

#ifndef TASK1_PRIORITYQUEUE_H
#define TASK1_PRIORITYQUEUE_H

#include <utility>

class PriorityQueue {
private:
    int array_size;
    int heap_size;
    std::pair<int, int> *array;//first - index, second - distance

    void correct(int &index);
public:
    PriorityQueue(): array_size(0), heap_size(0), array(nullptr) {}
    PriorityQueue(const int &_size, const std::pair<int, int> *_array);
    PriorityQueue(const PriorityQueue &queue);
    ~PriorityQueue() {delete [] array;}

    bool empty() const {return heap_size == 0;}
    int size() const { return heap_size; }
    std::pair<int, int> findMin();
    int getHeapSize() const {return heap_size;}
//    void insert();
    std::pair<int, int> extractMim();
//    void deleteMin();
    void decreaseKey(const int &index, const int &distance);

};


#endif //TASK1_PRIORITYQUEUE_H
