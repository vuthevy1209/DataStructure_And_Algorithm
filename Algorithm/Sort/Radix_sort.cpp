// Radix Sort in C++ Programming

#include <iostream>
using namespace std;

// Function to get the largest element from an a
int getMax(int a[], int n) {
  int max = a[0];
  for (int i = 1; i < n; i++)
    if (a[i] > max)
      max = a[i];
  return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int a[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(a[i] / place) % 10]++;

  // Calculate cumulative count
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(a[i] / place) % 10] - 1] = a[i];
    count[(a[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    a[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int a[], int size) {
  // Get maximum element
  int max = getMax(a, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(a, size, place);
}

// Print an a
void printa(int a[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << a[i] << " ";
  cout << endl;
}

// Driver code
int main() {
  int a[] = {121, 432, 564, 23, 1, 45, 788};
  int n = sizeof(a) / sizeof(a[0]);
  radixsort(a, n);
  printa(a, n);
}
