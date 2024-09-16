#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Argument error", argv[0]);
        return 1;
    }

    int total_elements = argc - 1;
    int numbers[total_elements];

   
    for (int i = 0; i < total_elements; i++) {
        numbers[i] = atoi(argv[i + 1]);
    }

    
    for (int i = 0; i < total_elements - 1; i++) {
        for (int j = i + 1; j < total_elements; j++) {
            if (numbers[i] < numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    
    printf("Sorted array in descending order:\n");
    for (int i = 0; i < total_elements; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
