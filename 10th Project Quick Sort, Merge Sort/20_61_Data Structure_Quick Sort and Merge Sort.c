#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
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

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivot element
    int i = (low - 1);      // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;  // Increment index of smaller element
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i + 1] and arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);

        // Separately sort elements before and after the partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n, choice;

    do {
        // Choose sorting algorithm using switch
        printf("\nChoose sorting algorithm:\n");
        printf("1. Quick Sort\n");
        printf("2. Merge Sort\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting the program.\n");
            exit(0);
        }

        // Get the size of the array
        printf("\nEnter the number of elements in the array: ");
        scanf("%d", &n);

        int arr[n];

        // Get array elements from the user
        printf("Enter %d elements:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        switch (choice) {
            case 1:
                // Perform Quick Sort
                quickSort(arr, 0, n - 1);
                printf("\nSorted array using Quick Sort: ");
                break;
            case 2:
                // Perform Merge Sort
                mergeSort(arr, 0, n - 1);
                printf("\nSorted array using Merge Sort: ");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                continue; // Skip the rest of the loop and go back to the beginning
        }

        // Print the sorted array
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }

        printf("\n\n");
    } while (1); // Infinite loop for returning to the menu

    return 0;
}
