#include <iostream>
#include "MergeSort.h"
#include "Insertion.h"
#include "Heap.h"
#include "Quick.h"
#include "Selection.h"
#include "Bubble.h"

using namespace std;

template <typename T>
void runMySort(BaseSort<T>&& sortObj) {
    cout << "Running sort: " << sortObj.getName() << endl;
    sortObj.loadRandomValues();
    sortObj.printValues();
    auto t1 = std::chrono::high_resolution_clock::now();
    sortObj.runSort();
    auto t2 = std::chrono::high_resolution_clock::now();

    sortObj.printValues();
    sortObj.verifySort();
    std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
    std::cout << "Sort completed in " << fp_ms.count() << " milliseconds" << endl;

}


int main() {


    //BaseSort<unsigned int> badIdea("cant", 10);

    runMySort(Bubble<unsigned int>(20000));
    runMySort(Selection<unsigned int>(20000));
    runMySort(Insertion<unsigned int>(20000));
    runMySort(Quick<unsigned int>(20000));
    runMySort(Heap<unsigned int>(20000));
    runMySort(Merge<unsigned int>(20000));
    return 0;
}