#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n){
    for (int i=0; i<n-1; i++){
        int pos = i;
        for (int j=i+1; j<n; j++){
            if (arr[j] < arr[pos]) pos = j;
        }
        if (pos != i){
            int temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
        }
    }
}

void bubbleSort(int arr[], int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n-i-1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n){
    for (int i=1; i<n; i++){
        int j = i-1;
        int temp = arr[i];

        while (j>=0 && temp <= arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

// utility for merge-sort
void merge(int* arr, int s, int e){
    int mid = (s+e)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int* first = (int*)malloc(sizeof(int)*len1);
    int* second = (int*)malloc(sizeof(int)*len2);

    //copy values
    int mainArrayIndex = s;
    for (int i=0; i<len1; i++)
        first[i] = arr[mainArrayIndex++];

    mainArrayIndex = mid+1;
    for (int i=0; i<len2; i++)
        second[i] = arr[mainArrayIndex++];

    // merge sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2){
        if (first[index1] < second[index2])
            arr[mainArrayIndex++] = first[index1++];
        else
            arr[mainArrayIndex++] = second[index2++];    
    }

    while (index1 < len1)
        arr[mainArrayIndex++] = first[index1++];

    while (index2 < len2)
        arr[mainArrayIndex++] = second[index2++];

}

void mergeSort(int* arr, int s, int e){
    
    //base case
    if (s >= e) return;

    int mid = (s+e)/2;

    // Sort Left Part
    mergeSort(arr, s, mid);

    // Sort Right Part
    mergeSort(arr, mid+1, e);

    // merge result
    merge(arr, s, e);

}

// utility for quickSort
void swap(int* arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int* arr, int l, int r){
    // get last elem as pivot
    int pivot = arr[r];
    int i = l-1;

    // loop and swap for < and >
    for (int j=l; j<r; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr, i, j);
        }
    }

    // set pivot at correct pos
    swap(arr, i+1, r);

    // return new pivot
    return i+1;
}

void quickSort(int* arr, int l, int r){
    if (l >= r) return;

    // get Pivot
    int pivot = partition(arr, l, r);

    // Recursive Call
    quickSort(arr, l, pivot-1);
    quickSort(arr, pivot+1, r);
}



int main(){
    int arr[8] = {1, 2, 10, 8, 9, 7, 13, 5};

    quickSort(arr, 0, 7);

    for (int i=0; i<8; i++)
        printf("%d\t", arr[i]);

    return 0;
}