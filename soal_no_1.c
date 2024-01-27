#include <stdio.h>

int main() {
    int arr[] = {1,2,2,3,4,4,5,7,7,5,9,9};
    int indeks = sizeof(arr) / sizeof(arr[0]);

    printf("array duplikat:\n ");
    for(int i=0; i < indeks; i++) {
        for(int j = i + 1; j < indeks; j++) {
            if(arr[i] == arr[j]) {
                printf("%d", arr[i]);
                printf(", ");
            }
        }
    }
    printf("\n");
    return 0;
}