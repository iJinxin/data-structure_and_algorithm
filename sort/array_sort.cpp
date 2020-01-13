#include <time.h>
#include <cstdlib>
#include <iostream>

#define RANDOM_SIZE 10000  // 排序量级

using namespace std;

// 冒泡排序
void bubbleSort(int arr[], int size) {
  clock_t start_t, end_t;
  start_t = clock();
  for (int i = 0; i < size; i++) {
    bool flag = false;
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
      flag = true;
    }
    if (!flag) break;  // 没有数据交换，说明已经有序，退出
  }
  end_t = clock();
  cout << "bubbleSort " << size << ", use time" << double(end_t - start_t)
       << "ms" << endl;
}

// 插入排序
void insertionSort(int arr[], int size) {
  if (size <= 1) return;
  clock_t start_t, end_t;
  start_t = clock();
  for (int i = 1; i < size; ++i) {
    int value = arr[i];
    int j = i - 1;
    for (; j >= 0; --j) {
      if (value < arr[j]) {
        arr[j + 1] = arr[j];  // 数据移动
      } else {
        break;
      }
    }
    arr[j + 1] = value;
  }
  end_t = clock();
  cout << "insertionSort " << size << ", use time: " << double(end_t - start_t)
       << "ms" << endl;
}

// 选择排序
void selectionSort(int arr[], int size) {
  if (size <= 1) return;
  clock_t start_t, end_t;
  start_t = clock();
  for (int i = 0; i < size; ++i) {
    int minIndex = i;
    for (int j = i + 1; j < size; ++j) {
      if (arr[j] < arr[i]) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      int temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }
  end_t = clock();
  cout << "selectionSort " << size << ", use time: " << double(end_t - start_t)
       << "ms" << endl;
}

int main() {
  int arr[RANDOM_SIZE] = {0};
  for (int i = 0; i < RANDOM_SIZE; i++) {
    arr[i] = rand() % 1000;
  }
  // bubble
  int arr1[RANDOM_SIZE];
  copy(begin(arr), end(arr), begin(arr1));
  bubbleSort(arr1, RANDOM_SIZE);
  // insertion
  int arr2[RANDOM_SIZE];
  copy(begin(arr), end(arr), begin(arr2));
  insertionSort(arr2, RANDOM_SIZE);

  // select
  int arr3[RANDOM_SIZE];
  copy(begin(arr), end(arr), begin(arr3));
  selectionSort(arr3, RANDOM_SIZE);


  return 0;
}