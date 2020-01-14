#include <time.h>
#include <cstdlib>
#include <iostream>

#define RANDOM_SIZE 100000  // 排序量级

using namespace std;

void merge(int arr[], int p, int q, int r) {
  int *temp = new int[r - p + 1];
  int i = p, j = q + 1, k = 0;

  if (!temp) return;

  while (i <= q && j <= r) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }
  // 判断子数组是否还有数据
  int start = i, end = q;
  if (j <= r) {
    start = j;
    end = r;
  }
  while (start <= end) {
    temp[k++] = arr[start++];
  }

  // 将temp数组拷贝回arr数组
  for (int i = 0; i <= r - p; i++) {
    arr[p + i] = temp[i];
  }
  // delete[] temp;
}

void merge_sort(int arr[], int p, int r) {
  if (p >= r) return;

  int q = (p + r) / 2;
  merge_sort(arr, p, q);
  merge_sort(arr, q + 1, r);
  merge(arr, p, q, r);
}

// 数组拆分，返回pivot的位置
int partition(int arr[], int p, int r) {
  int pivot = arr[r];
  int i = p;
  for (int j = p; j < r; j++) {
    if (arr[j] < pivot) {
      if (i!=j) {
        swap(arr[i], arr[j]);
      }
      i++;
    }
  }
  swap(arr[i], arr[r]);

  return i;
}

void quicksort(int arr[], int p, int r) {
  if (p >= r) return;
  int q = partition(arr, p, r);
  quicksort(arr, p, q - 1);
  quicksort(arr, q+1, r);
}

int main() {
  int arr[RANDOM_SIZE] = {0};
  for (int i = 0; i < RANDOM_SIZE; i++) {
    arr[i] = rand() % 1000;
  }

  // merge sort
  int arr1[RANDOM_SIZE];
  copy(begin(arr), end(arr), begin(arr1));
  clock_t start_t, end_t;
  start_t = clock();
  merge_sort(arr1, 0, RANDOM_SIZE - 1);
  end_t = clock();
  cout << "merge sort " << RANDOM_SIZE << ", use time: " << (end_t - start_t)
       << "ms" << endl;

  // quicksort
  int arr2[RANDOM_SIZE];
  copy(begin(arr), end(arr), begin(arr2));
  clock_t start_t2, end_t2;
  start_t2 = clock();
  quicksort(arr2, 0, RANDOM_SIZE - 1);
  end_t2 = clock();
  cout << "quicksort " << RANDOM_SIZE << ", use time: " << (end_t2 - start_t2)
       << "ms" << endl;
  // for (int i=0;i<RANDOM_SIZE;i++) {
  //   cout << arr1[i] << endl;
  // }

  return 0;
}