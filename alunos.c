#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NOTE 100

typedef struct {
    char name[50];
    int grade;
} Student;

void bucketSort(int arr[], int n);
int interpolationSearch(int arr[], int n, int target);
void printStudentDetails(Student students[], int n);

int main() {
    Student students[] = {
        {"Alice", 88},
        {"Bob", 57},
        {"Charlie", 92},
        {"David", 63},
        {"Eve", 45},
        {"Frank", 77},
        {"Grace", 85},
        {"Hannah", 60}
    };

    int n = sizeof(students) / sizeof(students[0]);
    int grades[n];
    for (int i = 0; i < n; i++) {
        grades[i] = students[i].grade;
    }

    printf("Notas antes da ordenação:\n");
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", students[i].name, students[i].grade);
    }

    bucketSort(grades, n);

    printf("\nNotas ordenadas:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", grades[i]);
    }

    int target;
    printf("\nDigite a nota a ser buscada: ");
    scanf("%d", &target);

    int result = interpolationSearch(grades, n, target);

    if (result != -1) {
        printf("\nAluno com a nota %d encontrado: %s\n", target, students[result].name);
    } else {
        printf("\nNota %d não encontrada.\n", target);
    }

    return 0;
}

void bucketSort(int arr[], int n) {
    if (n <= 0) return;

    int i, j;
    int bucketCount = 10;
    int buckets[bucketCount][n];
    int bucketSize[bucketCount];

    for (i = 0; i < bucketCount; i++) {
        bucketSize[i] = 0;
    }

    for (i = 0; i < n; i++) {
        int index = arr[i] * bucketCount / (MAX_NOTE + 1);
        buckets[index][bucketSize[index]++] = arr[i];
    }

    for (i = 0; i < bucketCount; i++) {
        for (j = 0; j < bucketSize[i] - 1; j++) {
            for (int k = 0; k < bucketSize[i] - j - 1; k++) {
                if (buckets[i][k] > buckets[i][k + 1]) {
                    int temp = buckets[i][k];
                    buckets[i][k] = buckets[i][k + 1];
                    buckets[i][k + 1] = temp;
                }
            }
        }
    }

    int index = 0;
    for (i = 0; i < bucketCount; i++) {
        for (j = 0; j < bucketSize[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int interpolationSearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }

        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]);

        if (arr[pos] == target) {
            return pos;
        }

        if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1;
}

void printStudentDetails(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", students[i].name, students[i].grade);
    }
}
