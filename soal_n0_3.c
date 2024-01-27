#include <stdio.h>

void rotatearray(int arr[], int A, int B) {
    B = B%A ;

    for(int i = 0; i < B; i++) {
        int akhir = arr[ A - 1];
        for(int j =  A - 1; j > 0; j--)
            arr[j] = arr[j - 1];
            arr[0] = akhir;
        
    }
}

void cetakArray(int arr[], int A) {
    for(int i = 0; i < A; i++)
    printf("%d", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {1,2,3,4,5,6,7};
    int A= sizeof(arr) / sizeof(arr[0]);
    int B= 3;

    printf("array sebelum di rotate:");
    cetakArray(arr, A);

    rotatearray(arr, A, B);

    printf("array sesudah di rotate:", B);
    cetakArray(arr,A);

    return 0;
}