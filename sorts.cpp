#include <iostream>
#include <vector>

#include "sorts.h"
#include "printer.h"

using namespace std;

void quickSort(vector<int>& v, int l, int r) {
    if (l < r) {
        int piv = v[(l + r) / 2];
        int i = l;
        int j = r;
        while (true) {
            while (v[i] < piv)
                i++;
            while (v[j] > piv)
                j--;
            if (i >= j) {
                piv = j;
                break;
            }
            swap(v[i++], v[j--]);
        }
        quickSort(v, l, piv);
        quickSort(v, piv + 1, r);
    }

}

void mergeSort(vector<int>& v) {
    int n = v.size();
    if (n == 1)
        return;
    if (n == 2) {
        if (v[0] > v[1])
            swap(v[0], v[1]);
        return;
    }

    int mid = n / 2;

    vector<int> L(v.begin(), v.begin() + mid);
    mergeSort(L);
    vector<int> R(v.begin() + mid, v.end());
    mergeSort(R);

    int l_n = L.size();
    int r_n = R.size();
    int i = 0, j = 0, k = 0;
    while (i < l_n && j < r_n)
        if (L[i] < R[j])
            v[k++] = L[i++];
        else
            v[k++] = R[j++];

    while (i < l_n)
        v[k++] = L[i++];

    while (j < r_n)
        v[k++] = R[j++];
}