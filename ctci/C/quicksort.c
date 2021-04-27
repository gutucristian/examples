#include <stdio.h>

void swap(int* a, int* b) {
  //printf("&a = %p, &b = %p\n", &a, &b);
  //printf("a = %p, b = %p\n", a, b);
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[], int left, int right, int pivot) {
  while (left <= right) {
    while (arr[left] < pivot) {
      left++;
    }

    while (arr[right] > pivot) {
      right--;
    }

    if (left <= right) {
      swap(&left, &right);
      left++;
      right--;
    }    
  }

  return left;
}

void quicksort(int arr*, int left, int right) {
  if (left >= right) {
    return;
  }

  int pivot = *(arr + ((left + right) / 2));
  int index = partition(arr, left, right);
  quicksort(arr, left, index - 1);
  quicksort(arr, right, index + 1);
}

int main() {
  int x = 5;
  int y = 9;
  //printf("&x = %p, &y = %p\n", &x, &y);
  //printf("x = %d, y = %d\n", x, y);
  swap(&x, &y);
  //printf("x = %d, y = %d\n", x, y);
  int arr = {3, 2, 0, 8, 1};
  quicksort(&arr, 0, 5);
}
