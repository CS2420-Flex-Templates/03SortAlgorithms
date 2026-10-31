//
// Created by kmurphy on 10/26/2026.
//

#ifndef MERGE_H
#define MERGE_H
#include "BaseSort.h"


template <typename T>
class Merge : public BaseSort<T> {
public:
    Merge(const unsigned int capacity)
        : BaseSort<T>("Two-Way Merge", capacity) {}

    void runSort();

private:
    unsigned int findMiddle(unsigned int firstIndex,
                            unsigned int lastIndex);

    void merge(unsigned int firstIndex,
               unsigned int middleIndex,
               unsigned int lastIndex);

    void mergeArrays(T* leftArray,
                     unsigned int leftSize,
                     T* rightArray,
                     unsigned int rightSize,
                     unsigned int arrIndex);

    void mergeSort(unsigned int firstIndex,
                      unsigned int lastIndex);

};

template <typename T>
void Merge<T>::runSort() {
    mergeSort(0, this->capacity);
}


/*
 * This function should calculate midpoint of the list
 *  given the start and end indicies
 */
template <typename T>
unsigned int Merge<T>::findMiddle(unsigned int firstIndex,
                        unsigned int lastIndex) {
    return (firstIndex + lastIndex) / 2;
}


/*
 * Merge two sorted temporary arrays into the original array (arr)
 *  at position firstIndex
 */
template <typename T>
void Merge<T>::mergeArrays(T* leftArray,
                 unsigned int leftSize,
                 T* rightArray,
                 unsigned int rightSize,
                 unsigned int arrIndex) {
    int leftIndex = 0;
    int rightIndex = 0;

    while (leftIndex < leftSize &&
         rightIndex < rightSize) {

        // Which value should be copied next?
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            this->arr[arrIndex] = leftArray[leftIndex];
            leftIndex++;
        }
        else {
            this->arr[arrIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        // Update the appropriate index.

        // Advance arrIndex.
        arrIndex++;
         }
    // Copy remaining values from the left array
    while (leftIndex < leftSize) {
        this->arr[arrIndex] = leftArray[leftIndex];
        leftIndex++;
        arrIndex++;
    }

    // Copy remaining values from the right array
    while (rightIndex < rightSize) {
        this->arr[arrIndex] = rightArray[rightIndex];
        rightIndex++;
        arrIndex++;
    }
}

template <typename T>
void Merge<T>::merge(unsigned int firstIndex,
           unsigned int middleIndex,
           unsigned int lastIndex) {
    unsigned int leftHalfSize = middleIndex - firstIndex;
    unsigned int rightHalfSize = lastIndex - middleIndex;

    // Create temporary arrays
    T* leftArray = new T[leftHalfSize];
    T* rightArray = new T[rightHalfSize];

    // Copy the left half
    for (unsigned int i = 0; i < leftHalfSize; i++) {
        leftArray[i] = this->arr[firstIndex + i];
    }

    // Copy the right half
    for (unsigned int i = 0; i < rightHalfSize; i++) {
        rightArray[i] = this->arr[middleIndex + i];
    }

    // Merge the temporary arrays into the original array
    mergeArrays(leftArray, leftHalfSize,
                rightArray, rightHalfSize,
                firstIndex);

    // Release dynamically allocated memory
    delete[] leftArray;
    delete[] rightArray;

}

/*
 * Sort Range: Implement the SortRange...
 *  1. Stop when the array region contains fewer than 2 elements
 *  2. Calculate the middle index
 *  3. Recursively sort the left half
 *  4. Recursively sort the right half
 *  5. Merge the two sorted halves
 */
template <typename T>
void Merge<T>::mergeSort(unsigned int firstIndex,
                     unsigned int lastIndex) {
    // Base case: zero or one element is already sorted
    if (lastIndex - firstIndex < 2) {
        return;
    }

    // Find the midpoint
    unsigned int middleIndex = findMiddle(firstIndex, lastIndex);

    // Recursively sort each half
    mergeSort(firstIndex, middleIndex);
    mergeSort(middleIndex, lastIndex);

    // Merge the two sorted halves
    merge(firstIndex, middleIndex, lastIndex);
}


#endif //MERGE_H
