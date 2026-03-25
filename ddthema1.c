#include <stdio.h>

float retrieve(float arr[], int i) {
    return arr[i - 1]; // δείκτης απο 1...10 σε 0...9
}

void update(float arr[], int i, float value) {
    arr[i - 1] = value; // δείκτης απο 1...10 σε 0...9
}

int main() {
    float A[10], B[10], C[10];
    int i;

    printf("eisagete 10 pragmatikous arithmous gia ton pinaka B:\n");
    for (i = 1; i <= 10; i++) {
        float val;
        scanf("%f", &val);
        update(B, i, val);
    }

    printf("eisagete 10 pragmatikous arithmous gia ton pinaka C:\n");
    for (i = 1; i <= 10; i++) {
        float val;
        scanf("%f", &val);
        update(C, i, val);
    }

    for (i = 1; i <= 10; i++) {
        float sum = retrieve(B, i) + retrieve(C, i);
        update(A, i, sum);
    }

    printf("\npinakas A (B + C):\n");
    for (i = 1; i <= 10; i++) {
        printf("%.2f ", retrieve(A, i));
    }

    return 0;
}