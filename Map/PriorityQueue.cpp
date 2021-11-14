//
// Created by oleg on 08.11.2021.
//

#include <exception>
#include <iostream>
#include "PriorityQueue.h"


PriorityQueue::PriorityQueue(const int &_size, const std::pair<int, int> *_array): array_size(_size), heap_size(_size), array(new std::pair<int, int>[_size]) {
    for (int i = 0; i < heap_size; ++i) {
        array[i] = _array[i];
    }
}

PriorityQueue::PriorityQueue(const PriorityQueue &queue):array_size(queue.array_size), heap_size(queue.heap_size), array(new std::pair<int, int>[queue.array_size]) {
    for (int i = 0; i < heap_size; ++i) {
        array[i] = queue.array[i];
    }
}

std::pair<int, int> PriorityQueue::findMin() {
    if (empty())
        throw std::exception();
    return *array;
}

void PriorityQueue::correct(int &index) {
    int i;
    while (index != 0) {
        i = (index-1)/2;
        if (array[index].second == array[i].second || array[index].second == -1)
            return;
        if (array[i].second == -1 || array[i].second > array[index].second) {
            swap(array[i], array[index]);
            index = i;
        } else { return; }
    }
}

void PriorityQueue::decreaseKey(const int &index, const int &distance) {
//
//    std::cout << "begin " << index << " " << distance << std::endl;
//    for (int i = 0; i < heap_size; ++i)
//        std::cout << array[i].first << " " << array[i].second << std::endl;
//    std::cout << "------------\n";
    for (int i = 0; i < heap_size; ++i) {
        if (array[i].first == index) {
            array[i].second = distance;
            correct(i);
            //for (int i = 0; i < heap_size; ++i)
            //    std::cout << array[i].first << " " << array[i].second << std::endl;
            //std::cout << "end\n";
            return;
        }
    }

}

std::pair<int, int> PriorityQueue::extractMim() {
    std::pair<int, int> value = findMin();

    --heap_size;

    array[0] = array[heap_size];
    int i = 0;

    while (i*2+1 < heap_size) {
        if (i*2+2 == heap_size || array[i*2+2].second == -1) {
            if (array[i*2+1].second == -1 || array[i].second == array[i*2+1].second)
                break;
            if (array[i].second == - 1 || array[i].second > array[i*2+1].second) {
                swap(array[i], array[i*2+1]);
                i = i*2+1;
            } else { break; }
        } else if (array[i*2+1].second == -1) {
            if (array[i].second == - 1 || array[i].second > array[i*2+2].second) {
                swap(array[i], array[i*2+2]);
                i = i*2+2;
            }
        }
    }

    return value;
}

