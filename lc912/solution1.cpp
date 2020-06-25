#include <cstdio>
#include <cstdlib>
#include <vector>

int partition(int *arr, int l, int r) {
  int x = arr[l];
  while (l < r) {
    while (l < r && arr[r] >= x) r--;
    if (l < r) {
      arr[l] = arr[r];
      l++;
    }
    while (l < r && arr[l] <= x) l++;
    if (l < r) {
      arr[r] = arr[l];
      r--;
    }
  }
  arr[l] = x;
  return l;
}

void quick_sort(int arr[], int left, int right) {
  if (left < right) {
    int i = partition(arr, left, right);
    quick_sort(arr, left, i - 1);
    quick_sort(arr, i + 1, right);
  }
}

void print(const char *tag, const int arr[], int len) {
  printf("%s:", tag);
  for (int i = 0; i < len; ++i) {
    printf("%d", arr[i]);
    if (i != len - 1) {
      printf(",");
    }

    else {
      printf(";");
    }
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  int arr[10];
  for (int i = 0; i < 10; ++i) {
    arr[i] = ::rand() % 100;
  }
  print("input", arr, 10);
  quick_sort(arr, 0, 9);
  print("output", arr, 10);
}
