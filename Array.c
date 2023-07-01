// Copyright 2023 Elton R. Soares
#include <stdio.h>
#include <stdlib.h>

/*********************************************************
 *
 *                ARRAYS ADT
 *
 *********************************************************/

struct Array {
  int *A;
  int size;
  int length;
};

void Swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void Display(struct Array pArr) {
  for (int i = 0; i < pArr.length; i++) {
    printf("%d ", pArr.A[i]);
  }

  printf("\n");
}

void Append(struct Array *pArr, int n) {
  if (pArr->size > pArr->length) {
    pArr->A[pArr->length] = n;
    pArr->length++;
  }
}

void Insert(struct Array *pArr, int index, int n) {
  if (index < pArr->size && index >= 0) {
    for (int i = pArr->length; i > index; i--) {
      pArr->A[i] = pArr->A[i - 1];
    }

    pArr->length++;
    pArr->A[index] = n;
  }
}

// Delete from array by shifting the elements
int Delete(struct Array *pArr, int index) {
  int x = 0;

  if (index < pArr->length && index > 0) {
    x = pArr->A[index];

    for (int i = index; i < pArr->length - 1; i++) {
      pArr->A[i] = pArr->A[i + 1];
    }

    pArr->length--;
    return x;
  }

  return 0;
}

/*
int LinearSearch(struct Array arr, int element) {
  for (int i = 0; i < arr.length; i++) {
    if (arr.A[i] == element) {
      return i;
    }
  }

  return -1;
} */

// Linear Search With TRANSPOSITION
int LinearSearch(struct Array *arr, int element) {
  for (int i = 0; i < arr->length; i++) {
    if (arr->A[i] == element) {
      arr->A[i - 1];
      Swap(&arr->A[i - 1], &arr->A[i]);
      return i;
    }
  }

  return -1;
}

int BinarySearch(struct Array arr, int element) {
  int start = 0;
  int end = arr.length;
  int mid = (start + end) / 2;

  while (start <= end) {
    if (arr.A[mid] == element) {
      return mid;
    } else if (arr.A[mid] > element) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return -1;
}

// Recursive Binary Search
int RBinarySearch(struct Array arr, int start, int end, int key) {
  if (start <= end) {
    int mid = (start + end) / 2;

    if (key == arr.A[mid]) {
      return mid;
    } else if (key > arr.A[mid]) {
      return RBinarySearch(arr, mid + 1, end, key);
    } else {
      return RBinarySearch(arr, start, mid - 1, key);
    }
  }

  return -1;
}

int Get(struct Array arr, int index) {
  if (index >= 0 && index < arr.length) {
    return arr.A[index];
  }

  return -1;
}

void Set(struct Array *arr, int index, int value) {
  if (index >= 0 && index < arr->length) {
    arr->A[index] = value;
  } else {
    printf("Number out of range");
  }
}

int Max(struct Array arr) {
  int max = arr.A[0];

  for (int i = 1; i < arr.length; i++) {
    if (arr.A[i] > max) {
      max = arr.A[i];
    }
  }

  return max;
}

int Min(struct Array arr) {
  int min = arr.A[0];

  for (int i = 1; i < arr.length; i++) {
    if (arr.A[i] < min) {
      min = arr.A[i];
    }
  }

  return min;
}

int Sum(struct Array arr) {
  int sum = arr.A[0];

  for (int i = 1; i < arr.length; i++) {
    sum = sum + arr.A[i];
  }

  return sum;
}

void ReverseArray(struct Array *arr) {
  int i = 0;
  int j = arr->length - 1;

  for (i, j; i < j; i++, j--) {
    Swap(&arr->A[i], &arr->A[j]);
  }
}

float Avg(struct Array arr) { return (float)Sum(arr) / arr.length; }

void RotateLeft(struct Array *arr) {
  for (int i = 1; i < arr->length; i++) {
    Swap(&arr->A[i - 1], &arr->A[i]);
  }
}

void RotateRight(struct Array *arr) {
  for (int i = arr->length; i >= 0; i--) {
    Swap(&arr->A[i], &arr->A[i - 1]);
  }
}

void LeftShift(struct Array *arr) {
  for (int i = 0; i <= arr->length; i++) {
    arr->A[i] = arr->A[i + 1];
  }
}

void RightShift(struct Array *arr) {
  for (int i = arr->length; i >= 0; i--) {
    arr->A[i] = arr->A[i - 1];
  }
}

void InsertSort(struct Array *arr, int x) {
  int i = arr->length - 1;

  if (arr->length == arr->size) {
    return;
  }

  while (i >= 0 && arr->A[i] > x) {
    arr->A[i + 1] = arr->A[i];
    i--;
  }

  arr->A[i + 1] = x;
  arr->length++;
}

int isSorted(struct Array arr) {
  for (int i = 0; i < arr.length - 1; i++) {
    if (arr.A[i] > arr.A[i + 1]) {
      return 0;
    }
  }

  return 1;
}

void InsertionSort(struct Array *arr) {
  for (int i = 1; i < arr->length; i++) {
    int key = arr->A[i];
    int j = i - 1;

    while (j >= 0 && arr->A[j] > key) {
      arr->A[j + 1] = arr->A[j];
      j = j - 1;
    }

    arr->A[j + 1] = key;
  }
}

// O(n)
void Rearrange(struct Array *arr) {
  int i = 0;
  int j = arr->length - 1;

  while (i < j) {
    while (arr->A[i] < 0) {
      i++;
    }
    while (arr->A[j] >= 0) {
      j--;
    }

    if (i < j) {
      Swap(&arr->A[i], &arr->A[j]);
    }
  }
}

// O(n + m)
struct Array *Merge(struct Array *arr, struct Array *arr2) {
  int i = 0;
  int j = 0;
  int k = 0;

  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
  arr3->A = (int *)malloc(sizeof(int) * (arr->size + arr2->size));

  while (i < arr->length && j < arr2->length) {
    if (arr->A[i] < arr2->A[j]) {
      arr3->A[k++] = arr->A[i++];
    } else {
      arr3->A[k++] = arr2->A[j++];
    }
  }

  // Copy remaining elements
  for (; i < arr->length; i++) {
    arr3->A[k++] = arr->A[i];
  }
  for (; j < arr2->length; j++) {
    arr3->A[k++] = arr2->A[j];
  }
  arr3->length = arr->length + arr2->length;
  arr3->size = 10;

  return arr3;
}

// O(n) with a sorted set
struct Array *UnionSorted(struct Array *arr, struct Array *arr2) {
  int i = 0;
  int j = 0;
  int k = 0;

  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
  arr3->A = (int *)malloc(sizeof(int) * (arr->size + arr2->size));

  while (i < arr->length && j < arr2->length) {
    if (arr->A[i] < arr2->A[j]) {
      arr3->A[k++] = arr->A[i++];
    } else if (arr2->A[j] < arr->A[i]) {
      arr3->A[k++] = arr2->A[j++];
    } else {
      arr3->A[k++] = arr->A[i++];
      j++;
    }
  }

  // Copy remaining elements
  for (; i < arr->length; i++) {
    arr3->A[k++] = arr->A[i];
  }
  for (; j < arr2->length; j++) {
    arr3->A[k++] = arr2->A[j];
  }
  arr3->length = k;
  arr3->size = 10;

  return arr3;
}

struct Array *Intersection(struct Array *arr, struct Array *arr2) {
  int i = 0;
  int j = 0;
  int k = 0;

  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
  arr3->A = (int *)malloc(sizeof(int) * (arr->size + arr2->size));

  while (i < arr->length && j < arr2->length) {
    if (arr->A[i] < arr2->A[j]) {
      i++;
    } else if (arr2->A[j] < arr->A[i]) {
      j++;
    } else if (arr->A[i] == arr2->A[j]) {
      arr3->A[k++] = arr->A[i++];
      j++;
    }
  }

  arr3->length = k;
  arr3->size = 10;

  return arr3;
}

struct Array *Difference(struct Array *arr, struct Array *arr2) {
  int i = 0;
  int j = 0;
  int k = 0;

  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
  arr3->A = (int *)malloc(sizeof(int) * (arr->size + arr2->size));

  while (i < arr->length && j < arr2->length) {
    if (arr->A[i] < arr2->A[j]) {
      arr3->A[k++] = arr->A[i++];
    } else if (arr2->A[j] < arr->A[i]) {
      j++;
    } else {
      i++;
      j++;
    }
  }

  // Copy remaining elements
  for (; i < arr->length; i++) {
    arr3->A[k++] = arr->A[i];
  }

  arr3->length = k;
  arr3->size = 10;

  return arr3;
}

int FindMissingElement() {
  struct Array arr;
  arr.size = 10;
  arr.length = 1;
  arr.A = (int *)malloc(arr.size * sizeof(int));
  Append(&arr, 1);
  Append(&arr, 2);
  Append(&arr, 3);
  Append(&arr, 4);
  Append(&arr, 5);
  Append(&arr, 7);
  Append(&arr, 8);
  Append(&arr, 9);
  Append(&arr, 10);

  int sum = Sum(arr);
  int lastElement = arr.A[arr.length - 1];

  int s = (lastElement * (lastElement + 1)) / 2;

  printf("The missing element: %d\n", s - sum);

  return s - sum;
}

int FindMissingElementAnywhere() {
  struct Array arr;
  arr.size = 10;
  arr.length = 1;
  arr.A = (int *)malloc(arr.size * sizeof(int));
  Append(&arr, 6);
  Append(&arr, 7);
  Append(&arr, 8);
  Append(&arr, 10);
  Append(&arr, 11);
  Append(&arr, 12);
  Append(&arr, 13);
  Append(&arr, 14);
  Append(&arr, 15);

  int first = arr.A[0];
  int lastElement = arr.A[arr.length - 1];
  int nLength = arr.length;



  return s - sum;
}

int main() {
  struct Array arr;
  int ch;
  int x, index;

  printf("Enter size of the array\n");
  scanf("%d", &arr.size);
  arr.A = (int *)malloc(arr.size * sizeof(int));

  printf("Menu\n");
  printf("1. Insert\n");
  printf("2. Delete\n");
  printf("3. Search\n");
  printf("4. Sum\n");
  printf("5. Display\n");
  printf("6. Find Missing Element\n");
  printf("7. Exit\n");

  do {
    printf("Enter your Choice ");
    scanf("%d", &ch);

    switch (ch) {
    case 1:
      printf("Enter an element and index ");
      scanf("%d %d", &x, &index);
      Insert(&arr, index, x);
      break;
    case 2:
      printf("Enter index ");
      scanf("%d", &index);
      Delete(&arr, index);
      break;
    case 3:
      printf("Enter element to search ");
      scanf("%d", &x);
      index = LinearSearch(&arr, x);
      printf("Index is: %d\n", index);
      break;
    case 4:
      printf("Sum is: %d\n", Sum(arr));
      break;
    case 5:
      Display(arr);
      break;
    case 6:
      FindMissingElement();
      break;
    }
  } while (ch < 6);

  return 0;
}
