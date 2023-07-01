#include <iostream>

template <class T> class Array {
private:
  int size;   // Number of spaces in the array
  int length; // Number of elements inside the array
  T *A;
  void Swap(T *x, T *y);

public:
  Array() {
    this->size = 10;
    this->length = 0;
    this->A = new T[size];
  }
  Array(T size) {
    this->size = size;
    this->length = 0;
    this->A = new T[size];
  }
  ~Array() {
    delete[] A;
    std::cout << "Array Deleted" << std::endl;
  }

  // Algorithms for Operations
  void Display();
  void Append(T x);
  void Insert(T x, int index);
  int Del(int index); // delete
  int LinearSearch(T key);
  int BinarySearch(int low, int high, T key);
  int Get(int index);
  int Set(int index, T newValue);
  int Sum();
  float Avg();
  int Max();
  int Min();
  void ReverseArray();
  void ReverseArray2();
  Array *Merge(Array arr2);
  Array *Union(Array arr2);
  Array *Interseciton(Array arr2);
  Array *Difference(Array arr2);
};

template <class T> void Array<T>::Display() {
  std::cout << "The elements are: " << std::endl;
  for (int i = 0; i < this->length; i++) {
    std::cout << this->A[i] << " ";
  }
  std::cout << " =================" << std::endl;
}

// Add element to the end of the array
template <class T> void Array<T>::Append(T x) {
  if (this->length < this->size) {
    this->A[this->length] = x;
    this->length++;
  } else {
    std::cout << "Array full!" << std::endl;
  }
}

// Insert array on particular index
template <class T> void Array<T>::Insert(T x, int index) {
  if (index >= 0 && index <= this->length) {
    for (int i = this->length; i > index; i--) {
      this->A[i] = this->A[i - 1]; // Move the elements position
    }
    this->A[index] = x; // Change the element on the index
    this->length++;     // Increase length size.
  } else {
    std::cout << "The index is invalid on this array" << std::endl;
  }
}

template <class T> int Array<T>::Del(int index) {
  int x = 0;

  if (index >= 0 && index <= this->length) {
    x = this->A[index];

    for (int i = index; i < this->length; i++) {
      this->A[i] = this->A[i + 1];
    }

    this->length--;
    return x; // When the element is deleted we return it
  }

  return 0; // if the index is invalid we return 0
}

// Swap two numbers on the array
template <class T> void Array<T>::Swap(T *x, T *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

/************************************************************/
/*  Basic linear search without MOVE TO FRONT/TRANSPOSITION */
/************************************************************/
/*
int Array ::LinearSearch(int key)
{
  for (int i = 0; i < this->length; i++) {
    if(key == this->A[i]) {
      return i;
    }
  }
  return -1;
} */

/************************************************************/
/*  Linear Search With Transposition                        */
/************************************************************/
/*
int Array ::LinearSearch(int key)
{
    for (int i = 0; i < this->length; i++) {
    if(key == this->A[i]) {
      swap(&this->A[i], &this->A[i-1]);
      return i - 1;
    }
  }
  return -1; // Not found = -1
} */

/************************************************************/
/*  Linear Search With Move To Front                        */
/************************************************************/
template <class T> int Array<T>::LinearSearch(T key) {
  for (int i = 0; i < this->length; i++) {
    if (key == this->A[i]) {
      swap(&this->A[i], &this->A[0]);
      return 0;
    }
  }
  return -1;
}

/************************************************************/
/*  Binary Search With Recursive Function                   */
/************************************************************/
/*
int Array ::binarySearch(int low, int high, int key)
{
    if(low <= high) {
    int mid = (low + high) / 2;

    if(key == this->A[mid]) {
      return mid;
    } else if(key < this->A[mid]) {
      return this.binarySearch(low, mid - 1, key);
    } else {
      return this.binarySearch(mid + 1, high, key);
    }
  }

  return -1; // If nothing found
} */

/************************************************************/
/*  Binary Search                                           */
/************************************************************/
template <class T> int Array<T>::BinarySearch(int low, int high, T key) {
  int mid = (low + high) / 2;
  while (low <= high) {
    if (key == this->A[mid]) {
      return mid;
    } else if (key < this->A[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return -1;
}

template <class T> int Array<T>::Get(int index) {
  if (index >= 0 && index < this->length) {
    return this->A[index];
  }

  return 0;
}

template <class T> int Array<T>::Set(int index, T newValue) {
  if (index >= 0 && index < this->length) {
    return this->A[index] = newValue;
  }

  return 0;
}

template <class T> int Array<T>::Sum() {
  int sum = 0;

  for (int i = 0; i < this->length; i++) {
    sum = sum + this->A[i];
  }

  return sum;
}

template <class T> float Array<T>::Avg() {
  return (float)this->sum() / this->length;
}

template <class T> int Array<T>::Max() {
  int max = this->A[0];

  for (int i = 1; i < this->length; i++) {
    if (this->A[i] > max) {
      max = this->A[i];
    }
  }

  return max;
}

template <class T> int Array<T>::Min() {
  int min = this->A[0];

  for (int i = 1; i < this->length; i++) {
    if (this->A[i] < min) {
      min = this->A[i];
    }
  }

  return min;
}

// Reverse the array using temp array
template <class T> void Array<T>::ReverseArray() {
  int *tempArray;

  tempArray = new int[this->length];

  for (int i = this->length, j = 0; i <= 0; i--, j++) {
    tempArray[j] = this->A[i];
  }

  for (int i = 0; i < this->length; i++) {
    this->A[i] = tempArray[i];
  }
}

// Less code, a little bit worse to read
template <class T> void Array<T>::ReverseArray2() {
  for (int i = 0, j = this->length - 1; i < j; i++, j--) {
    swap(&this->A[i], &this->A[j]);
  }
}

template <class T> Array<T> *Array<T>::Merge(Array arr) {
  int i, j, k;
  i = j = k = 0;

  Array *newArr = new Array(this->length + arr.length);

  while (i < this->length && j < arr.length) {
    if (this->A[i] < arr.A[j]) {
      newArr->A[k++] = this->A[i++];
    } else {
      newArr->A[k++] = arr.A[j++];
    }
  }

  for (; i < this->length; i++) {
    newArr->A[k++] = this->A[i];
  }
  for (; j < arr->length; j++) {
    newArr->A[k++] = arr->A[j];
  }

  newArr->length = this->length + arr.length;

  return newArr;
}

template <class T> Array<T> *Array<T>::Union(Array arr) {
  int i, j, k;
  i = j = k = 0;

  Array *newArr = new Array(this->length + arr.length);

  while (i < this->length && j < arr.length) {
    if (this->A[i] < arr.A[j]) {
      newArr->A[k++] = this->A[i++];
    } else {
      newArr->A[k++] = arr.A[j++];
    }
  }

  for (; i < this->length; i++) {
    newArr->A[k++] = this->A[i];
  }
  for (; j < arr->length; j++) {
    newArr->A[k++] = arr->A[j];
  }

  newArr->length = k;

  return newArr;
}

int main(int argc, char *argv[]) {
  std::cout << "Welcome to the Array Operations ADT Program" << std::endl;

  return 0;
}
