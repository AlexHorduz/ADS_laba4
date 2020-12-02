#include <iostream>
#include <vector>
#include <time.h>
#include <random>
#include <chrono>

#include "sorts.h"
#include "printer.h"

using namespace std;
using namespace std::chrono;


vector<int> createRandomArray(int n) {
    srand(static_cast<unsigned int>(time(0)));
    vector<int> v;
    for (int i = 0; i < n; i++)
        v.push_back(rand() % 2001 - 1000);
    return v;
}

vector<int> createSortedArray(int n, bool reversed = false) {
    vector<int> v;
    while (n--)
        v.push_back(n);
    if (!reversed)
        reverse(v.begin(), v.end());

    return v;
}

void testForSorted(int n) {
    vector<int> v = createSortedArray(n);
    vector<int> v1 = v;

    auto start_time = high_resolution_clock::now();

    quickSort(v, 0, v.size() - 1);

    auto end_time = high_resolution_clock::now();
    auto time = end_time - start_time;
    cout << "Quick sort with sorted " << v.size() << " elements: " << (duration_cast<microseconds>(time).count()) / 1000.0 << " ms\n";


    start_time = high_resolution_clock::now();

    mergeSort(v1);

    end_time = high_resolution_clock::now();
    time = end_time - start_time;
    cout << "Merge sort with sorted " << v1.size() << " elements: " << (duration_cast<microseconds>(time).count()) / 1000.0 << " ms\n";
}

void testForReversed(int n) {
    vector<int> v = createSortedArray(n, true);
    vector<int> v1 = v;

    auto start_time = high_resolution_clock::now();

    quickSort(v, 0, v.size() - 1);

    auto end_time = high_resolution_clock::now();
    auto time = end_time - start_time;
    cout << "Quick sort with reversed-sorted " << v.size() << " elements: " << (duration_cast<microseconds>(time).count())/1000.0 << " ms\n";


    start_time = high_resolution_clock::now();

    mergeSort(v1);

    end_time = high_resolution_clock::now();
    time = end_time - start_time;
    cout << "Merge sort with reversed-sorted " << v1.size() << " elements: " << (duration_cast<microseconds>(time).count())/1000.0 << " ms\n";
}

void testForRandom(int n) {
    vector<int> v = createRandomArray(n);
    vector<int> v1 = v;

    auto start_time = high_resolution_clock::now();

    quickSort(v, 0, v.size() - 1);

    auto end_time = high_resolution_clock::now();
    auto time = end_time - start_time;
    cout << "Quick sort with random " << v.size() << " elements: " << (duration_cast<microseconds>(time).count()) / 1000.0 << " ms\n";


    start_time = high_resolution_clock::now();

    mergeSort(v1);

    end_time = high_resolution_clock::now();
    time = end_time - start_time;
    cout << "Merge sort with random " << v1.size() << " elements: " << (duration_cast<microseconds>(time).count())/1000.0 << " ms\n";
}

int main()
{
    testForRandom(10000);
    cout << '\n';
    testForRandom(100000);
    cout << '\n';
    testForRandom(1000000);
    cout << "\n\n\n";
    testForSorted(10000);
    cout << '\n';
    testForSorted(100000);
    cout << '\n';
    testForSorted(1000000);
    cout << "\n\n\n";
    testForReversed(10000);
    cout << '\n';
    testForReversed(100000);
    cout << '\n';
    testForReversed(1000000);
}
