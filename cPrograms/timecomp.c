#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void generateRandom(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % n + 1;
    }
}

void ascending(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

void descending(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        arr[i] = n - i; 
    }
}

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int* arr,int n) {
    for(int i = 0; i < n; i++) {
        int swapped = 0;
        for(int j = 0; j < n - i -1; j++){
            if(arr[j] > arr[j + 1]) {
                swap(arr, j, j+1);
                swapped = 1;
            }
        }
        if(swapped == 0) break;
    }
}

void selectionSort(int* arr,int n){
    for(int i = 0; i < n - 1; i++) {
        int min1 = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min1]) {
                min1 = j;
            }
        }
        if(min1 != i){
            swap(arr, min1 ,i);
        }
    }
}

void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    struct timeval te;
    int size = 8000;
    int step = 4000;

    for(int i = 0; i < 8; i++) {
        int arr[size];
        generateRandom(arr, size);
        
        gettimeofday(&te,NULL);
        long long start = te.tv_sec * 1000LL + te.tv_usec/1000;
        quickSort(arr, 0, size - 1);
        gettimeofday(&te,NULL);
        long long end = te.tv_sec * 1000LL + te.tv_usec/1000;

        printf("%lld\n",end - start);
        size += step;
    }

    return 0;
}