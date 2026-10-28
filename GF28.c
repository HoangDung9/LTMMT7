#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

uint8_t gf2_8(uint8_t a, uint8_t b, uint8_t c);

uint8_t gf2_8(uint8_t a, uint8_t b, uint8_t c) {
uint8_t ket_qua = 0;

    for (int i = 0; i < 8; i++) {
        if (b & 1) {
            ket_qua ^= a; 
        }

        bool kiem_tra = (a & 0b10000000) != 0; 
        a = (a << 1); 

        if (kiem_tra) {
            a ^= c; 
        }

        b >>= 1; // Dịch phải b 
    }

    return ket_qua;
}

int main() {
    int nhap_a, nhap_b;
    scanf("%d %d", &nhap_a, &nhap_b);

    uint8_t c = 0x1B; 
    uint8_t a = (uint8_t)nhap_a;
    uint8_t b = (uint8_t)nhap_b;
    
    uint8_t ket_qua = gf2_8(a, b, c);
 
    printf("KET_QUA : %d(0x%X)\n", ket_qua, ket_qua);  

    return 0;
}