#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <time.h>
#include <thread>
#define N_SIZE 10000
#define MAX_NUM 100

void merge(std::vector<int>& arr, std::vector<int> temp, int low, int mid, int high){
    for(int i = low; i <= high; i++){
        temp[i] = arr[i];
    }

    int leftIndex = low; //index of left array
    int rightIndex = mid+1; //index of right array
    int sortIndex = low; //index of array to sort

    //if leftIndex > mid then we have gotten every element from left array
    //if rightIndex > high then we have gotten every element from right array
    while(leftIndex <= mid && rightIndex <= high){
        if(temp[leftIndex] < temp[rightIndex]){
            arr[sortIndex] = temp[leftIndex];
            leftIndex++;
        } else{ //if current element on right side is less than the one on the left
            arr[sortIndex] = temp[rightIndex];
            rightIndex++;
        }
        sortIndex++;
    }

    //at this point we have used all elements on one side of the array so copy
    //the rest to the end of the array to sort

    if(leftIndex > mid){ //if left side is done then copy rest of right side
        for(int i = sortIndex; i <= high; i++){
            arr[i] = temp[rightIndex];
            rightIndex++;
        }
    } else{ //if right side is done then copy rest of left side
        for(int i = sortIndex; i <= high; i++){
            arr[i] = temp[leftIndex];
            leftIndex++;
        }
    }
}

void mergeSort(std::vector<int>& arr, std::vector<int>& temp, int low, int high){
    if(low < high){ //when low = high there is only one element
        int mid = (low+high) / 2;
        mergeSort(arr, temp, low, mid); //sort left side
        mergeSort(arr, temp, mid+1, high); //sort right side
        merge(arr, temp, low, mid, high); //merge both sides
    }
}

void threadedMergeSort(std::vector<int>& arr, std::vector<int>& temp, int low, int high){
    if(low < high){ //when low = high there is only one element
        int mid = (low+high) / 2;
        std::thread t1(mergeSort, std::ref(arr), std::ref(temp), low, mid); //sort left side
        std::thread t2(mergeSort, std::ref(arr), std::ref(temp), mid+1, high); //sort right side
        t1.join();
        t2.join();
        merge(arr, temp, low, mid, high); //merge both sides
    }
}

int main(){
    std::vector<int> testArray;
    srand(time(NULL)); //random seed
    for(int i = 0; i < N_SIZE; i++){
        testArray.push_back(rand() % MAX_NUM);
    }

    std::vector<int> temp(testArray.size());
    std::vector<int> tempThreaded(testArray.size());
    std::vector<int> threadedArray(testArray);

    clock_t t1, t2;

    t1 = clock();
    mergeSort(testArray, temp, 0, testArray.size()-1);
    t1 = clock() - t1;

    t2 = clock();
    threadedMergeSort(threadedArray, tempThreaded, 0, threadedArray.size()-1);
    t2 = clock() - t2;

    printf("For %d elements:\nmergeSort took %f seconds\ntreadedMergeSort took %f seconds\n", N_SIZE, ((float)t1)/CLOCKS_PER_SEC, ((float)t2)/CLOCKS_PER_SEC);

    //print sorted threaded array
    /*
    for(int i = 0; i < testArray.size(); i++){
        std::cout << threadedArray[i] << " ";
        //std::cout << testArray[i] << " ";
    }
    std::cout << std::endl << std::endl;
    */

    //print sorted regular array
    /*
    for(int i = 0; i < testArray.size(); i++){
        //std::cout << threadedArray[i] << " ";
        std::cout << testArray[i] << " ";
    }
    std::cout << std::endl;
    */

    return 0;
}

/* NOTES

Compile using "clang++ -std=c++11 threaded_merge_sort.cpp"

There is nothing special about this threaded version since I just created a new
execution thread to deal with a half of the array while another thread dealt
with the other half, then repeated this process recursively, creating logN threads.

*/
