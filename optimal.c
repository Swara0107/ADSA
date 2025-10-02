#include <stdio.h>
int main() {
    int n;
    // Take input for number of arrays/files
    printf("Number of Array: ");
    if (scanf("%d", &n) != 1 || n <= 0)  
    {
        printf("Invalid number!\n");
        return 1; // Exit if invalid
    }
    int arr[n]; // Array to hold lengths of the arrays/files
    // Take input for array lengths
    printf("Enter Array lengths:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Sort array lengths in ascending order (Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    // Print the optimal storage order
    printf("Optimal storage order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Calculate Minimum Retrieval Time (MRT)
    long cumulative = 0, total = 0;
    for (int i = 0; i < n; i++) {
        cumulative += arr[i]; // cumulative sum at step i
        total += cumulative;  // add cumulative to total
    }
    double mrt = (double) total / n;
    // Print the result
    printf("Minimum Retrieval Time (MRT): %.2f\n", mrt);
    return 0;
}
