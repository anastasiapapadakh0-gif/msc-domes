#include <stdio.h>

int main() {
    
    int b = 100; // βασική διεύθυνση
    int L = 8;   // μήκος συνιστώσας
    
    // όρια δεικτών (lower και upper bounds)
    int l1 = 1, u1 = 3;
    int l2 = 1, u2 = 2;
    int l3 = 2, u3 = 2;
    int l4 = 1, u4 = 2;

    // υπολογισμός μεγέθους κάθε διάστασης
    int d1 = u1 - l1 + 1;
    int d2 = u2 - l2 + 1;
    int d3 = u3 - l3 + 1;
    int d4 = u4 - l4 + 1;

    printf("Memory Addresses of array A(1:3, 1:2, 2:2, 1:2)\n");
    printf("-------------------------------------------------\n");

    // for για κάθε διάσταση
    for (int i1 = l1; i1 <= u1; i1++) {
        for (int i2 = l2; i2 <= u2; i2++) {
            for (int i3 = l3; i3 <= u3; i3++) {
                for (int i4 = l4; i4 <= u4; i4++) {
                    
                    int offset = (i1 - l1) * (d2 * d3 * d4) + 
                                 (i2 - l2) * (d3 * d4) + 
                                 (i3 - l3) * d4 + 
                                 (i4 - l4);
                    
                    int address = b + (L * offset);
                    printf("A(%d, %d, %d, %d) -> address: %d\n", i1, i2, i3, i4, address);
                }
            }
        }
    }

    return 0;
}