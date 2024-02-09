#include <stdio.h>
#include <string.h>

// Student structure
struct Student {
    int rollNo;
    char name[50];
    float sgpa;
};

// Function to swap two students
void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort for Roll Numbers in ascending order
void bubbleSortByRollNo(struct Student arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j].rollNo > arr[j+1].rollNo) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Insertion Sort for Names alphabetically
void insertionSortByName(struct Student arr[], int n) {
    int i, j;
    struct Student key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && strcmp(arr[j].name, key.name) > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Quick Sort for Top 10 students based on SGPA
int partition(struct Student arr[], int low, int high) {
    float pivot = arr[high].sgpa;
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].sgpa >= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortBySGPA(struct Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortBySGPA(arr, low, pi - 1);
        quickSortBySGPA(arr, pi + 1, high);
    }
}

// Linear Search for students with a particular SGPA
void searchBySGPA(struct Student arr[], int n, float targetSGPA) {
    int found = 0;
    printf("Students with SGPA %.2f:\n", targetSGPA);
    for (int i = 0; i < n; i++) {
        if (arr[i].sgpa == targetSGPA) {
            printf("Roll No: %d, Name: %s\n", arr[i].rollNo, arr[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("No students found with SGPA %.2f\n", targetSGPA);
    }
}

// Binary Search for a student by name
void binarySearchByName(struct Student arr[], int n, char* targetName) {
    int left = 0, right = n - 1, found = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int result = strcmp(arr[mid].name, targetName);
        if (result == 0) {
            printf("Student found - Roll No: %d, SGPA: %.2f\n", arr[mid].rollNo, arr[mid].sgpa);
            found = 1;
            break;
        } else if (result < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        printf("Student with name '%s' not found.\n", targetName);
    }
}

int main() {
    struct Student database[10] = {
        {101, "John", 3.8},
        {102, "Alice", 3.6},
        {103, "Bob", 3.9},
        {104, "Charlie", 3.5},
        {105, "David", 4.0},
        {106, "Emma", 3.7},
        {107, "Frank", 3.9},
        {108, "Grace", 3.8},
        {109, "Henry", 3.6},
        {110, "Ivy", 3.8}
    };

    int n = 10;

    // a) Sort by Roll Numbers using Bubble Sort
    bubbleSortByRollNo(database, n);

    // b) Sort alphabetically by Name using Insertion Sort
    insertionSortByName(database, n);

    // c) Sort to find top 10 students by SGPA using Quick Sort
    quickSortBySGPA(database, 0, n - 1);

    // d) Search students by SGPA
    searchBySGPA(database, n, 3.8); // Change the SGPA value as needed

    // e) Search a student by name using Binary Search
    binarySearchByName(database, n, "David");

    return 0;
}
