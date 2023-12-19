#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void printArray(int arr[], int n);
void bubbleSort(int arr[], int n, int order, int showSteps);
void insertionSort(int arr[], int n, int order, int showSteps);
void selectionSort(int arr[], int n, int order, int showSteps);
void mergeSort(int arr[], int left, int right, int order, int showSteps);
void merge(int arr[], int left, int mid, int right, int order);
void quickSort(int arr[], int low, int high, int order, int showSteps);
int partition(int arr[], int low, int high, int order);
void heapSort(int arr[], int n, int order, int showSteps);
void buildHeap(int arr[], int n, int order);
void radixSort(int arr[], int n, int order, int showSteps);
void bucketSort(int arr[], int n, int order, int showSteps);

int main() {
    int choice, order, showSteps;
    int *arr = NULL;
    int n;
    char repeat;

    do {
        system("cls"); // Clear screen (for Windows)

        // Color codes
        printf("\033[1;36m"); // Cyan text

        // Header
        printf("===========================================\n");
        printf("             Sorting Algorithm Menu         \n");
        printf("===========================================\n");

        // Menu options
        printf(" 1. Bubble Sort\n");
        printf(" 2. Insertion Sort\n");
        printf(" 3. Selection Sort\n");
        printf(" 4. Merge Sort\n");
        printf(" 5. Quick Sort\n");
        printf(" 6. Heap Sort\n");
        printf(" 7. Radix Sort\n");
        printf(" 8. Bucket Sort\n");
        printf(" 0. Exit\n");

        // Color reset
        printf("\033[0m"); // Reset text color

        // User input
        printf("Enter your choice (0-8): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the program.\n");
            break;
        }

        // Choose sorting order
        printf("Choose sorting order:\n");
        printf("1. Ascending\n");
        printf("2. Descending\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &order);

        // Choose whether to show sorting steps
        printf("Do you want to see sorting steps? (1 for Yes, 0 for No): ");
        scanf("%d", &showSteps);

        if (showSteps != 0 && showSteps != 1) {
            printf("Invalid choice for showing sorting steps. Exiting the program.\n");
            return 1;
        }

        // Input array size and elements
        printf("Enter the maximum number of elements in the array: ");
        scanf("%d", &n);

        if (n <= 0) {
            printf("Invalid array size. Exiting the program.\n");
            return 1;
        }

        // Allocate memory for the array
        arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed. Exiting the program.\n");
            return 1;
        }

        printf("Enter the number of elements (up to %d): ", n);
        scanf("%d", &n);

        if (n <= 0 || n > 100) {
            printf("Invalid number of elements. Exiting the program.\n");
            free(arr);
            return 1;
        }

        printf("Enter the elements:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        // Sorting based on user's choice and order
        switch (choice) {
            case 1:
                bubbleSort(arr, n, order, showSteps);
                break;
            case 2:
                insertionSort(arr, n, order, showSteps);
                break;
            case 3:
                selectionSort(arr, n, order, showSteps);
                break;
            case 4:
                mergeSort(arr, 0, n - 1, order, showSteps);
                break;
            case 5:
                quickSort(arr, 0, n - 1, order, showSteps);
                break;
            case 6:
                heapSort(arr, n, order, showSteps);
                break;
            case 7:
                radixSort(arr, n, order, showSteps);
                break;
            case 8:
                bucketSort(arr, n, order, showSteps);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        // Print the sorted array
        printf("Sorted array: ");
        printArray(arr, n);

        // Check if the user wants to continue
        printf("Do you want to continue sorting or exit? (y/n): ");
        scanf(" %c", &repeat);

        // Free allocated memory
        free(arr);

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort
void bubbleSort(int arr[], int n, int order, int showSteps) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((order == 1 && arr[j] > arr[j + 1]) || (order == 2 && arr[j] < arr[j + 1])) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // Print array at each step
                if (showSteps) {
                    printf("Bubble Sort Step %d: ", i * (n - 1) + j + 1);
                    printArray(arr, n);
                }
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n, int order, int showSteps) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while ((j >= 0) && ((order == 1 && arr[j] > key) || (order == 2 && arr[j] < key))) {
            arr[j + 1] = arr[j];
            j = j - 1;

            // Print array at each step
            if (showSteps) {
                printf("Insertion Sort Step %d: ", i * n + j + 1);
                printArray(arr, n);
            }
        }

        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n, int order, int showSteps) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if ((order == 1 && arr[j] < arr[min_idx]) || (order == 2 && arr[j] > arr[min_idx])) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;

        // Print array at each step
        if (showSteps) {
            printf("Selection Sort Step %d: ", i + 1);
            printArray(arr, n);
        }
    }
}

// Merge Sort
void mergeSort(int arr[], int left, int right, int order, int showSteps) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid, order, showSteps);
        mergeSort(arr, mid + 1, right, order, showSteps);

        // Merge the sorted halves
        merge(arr, left, mid, right, order);

        // Print array at each step
        if (showSteps) {
            printf("Merge Sort Step: ");
            printArray(arr + left, right - left + 1);
        }
    }
}

void merge(int arr[], int left, int mid, int right, int order) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if ((order == 1 && L[i] <= R[j]) || (order == 2 && L[i] >= R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Quick Sort
void quickSort(int arr[], int low, int high, int order, int showSteps) {
    if (low < high) {
        // Partition the array
        int pi = partition(arr, low, high, order);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1, order, showSteps);
        quickSort(arr, pi + 1, high, order, showSteps);

        // Print array at each step
        if (showSteps) {
            printf("Quick Sort Step: ");
            printArray(arr + low, high - low + 1);
        }
    }
}

int partition(int arr[], int low, int high, int order) {
    int pivot = arr[high]; // Choose the rightmost element as the pivot
    int i = (low - 1);     // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller (or larger) than the pivot
        if ((order == 1 && arr[j] < pivot) || (order == 2 && arr[j] > pivot)) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i+1] and arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

// Heap Sort
void heapSort(int arr[], int n, int order, int showSteps) {
    buildHeap(arr, n, order);

    for (int i = n - 1; i > 0; i--) {
        // Swap the root (maximum/minimum) element with the last element
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify the reduced heap
        buildHeap(arr, i, order);

        // Print array at each step
        if (showSteps) {
            printf("Heap Sort Step %d: ", n - i);
            printArray(arr, n);
        }
    }
}

void buildHeap(int arr[], int n, int order) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        // Heapify each non-leaf node (in reverse order)
        heapify(arr, n, i, order);
    }
}

void heapify(int arr[], int n, int i, int order) {
    int largest = i; // Initialize the root as the largest/smallest element
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If the left child is larger/smaller than the root
    if (left < n && ((order == 1 && arr[left] > arr[largest]) || (order == 2 && arr[left] < arr[largest])))
        largest = left;

    // If the right child is larger/smaller than the current largest/smallest
    if (right < n && ((order == 1 && arr[right] > arr[largest]) || (order == 2 && arr[right] < arr[largest])))
        largest = right;

    // If the largest/smallest element is not the root
    if (largest != i) {
        // Swap the root with the largest/smallest element
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(arr, n, largest, order);
    }
}

// Radix Sort
void radixSort(int arr[], int n, int order, int showSteps) {
    int max = getMax(arr, n);

    // Perform counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp, order);

        // Print array at each step
        if (showSteps) {
            printf("Radix Sort Step %d: ", exp);
            printArray(arr, n);
        }
    }
}

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countingSort(int arr[], int n, int exp, int order) {
    const int BASE = 10;
    int output[n];
    int count[BASE] = {0};

    // Count occurrences of digits
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % BASE]++;

    // Update count to store the position of the digits in the output array
    for (int i = 1; i < BASE; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % BASE] - 1] = arr[i];
        count[(arr[i] / exp) % BASE]--;
    }

    // Copy the output array to the original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Bucket Sort
void bucketSort(int arr[], int n, int order, int showSteps) {
    const int BUCKETS = 10;
    int buckets[BUCKETS][n];
    int bucketSize[BUCKETS] = {0};

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] * BUCKETS / getMax(arr, n);
        buckets[bucketIndex][bucketSize[bucketIndex]++] = arr[i];
    }

    // Sort each bucket individually (using another sorting algorithm)
    for (int i = 0; i < BUCKETS; i++) {
        switch (order) {
            case 1:
                insertionSort(buckets[i], bucketSize[i], order, 0);
                break;
            case 2:
                insertionSort(buckets[i], bucketSize[i], order, 0);
                break;
            default:
                break;
        }
    }

    // Concatenate the sorted buckets into the original array
    int index = 0;
    for (int i = 0; i < BUCKETS; i++) {
        for (int j = 0; j < bucketSize[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Print array at each step
    if (showSteps) {
        printf("Bucket Sort Step: ");
        printArray(arr, n);
    }
}
