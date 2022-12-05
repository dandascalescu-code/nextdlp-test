#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/// @brief Prints bits of a given byte. Credit https://jameshfisher.com/2017/02/23/printing-bits/
/// @param val 8bit character
void print_byte(char val) {
  for (int i = 7; 0 <= i; i--) {
    printf("%c", (val & (1 << i)) ? '1' : '0');
  }
}

/// @brief Prints byte array.
/// @param buffer, array of 8bit characters
/// @param n, number of bytes
void print_bytes(unsigned char* buffer, size_t n) {
  printf("[ ");
  for (size_t i = 0; i < n; i++) {
    print_byte(buffer[i]);
    printf(" ");
  }
  printf("] ");

  printf("[ ");
  for (size_t i = 0; i < n; i++) {
    printf("%c", buffer[i]);
    printf(" ");
  }
  printf("]\n");
}

/// @brief Reverses the bits in a given array of bytes.
/// @param buffer, array of 8bit characters
/// @param n, number of bytes
void reverse_bytes(unsigned char* buffer, size_t n) {
    for (size_t i = 0; i < 4*n; i++) { // counts i bits from 0 to half the length of buffer
        int b = i/8; // byte of buffer to use
        int m = i%8; // bit of byte to mask
        int i = (buffer[b] & (128 >> m)) ? 1 : 0; // counts through the bits of buffer, left-to-right
        int j = (buffer[n-1-b] & (1 << m)) ? 1 : 0; //... and right-to-left, i and j meet in the middle

        if (i != j) {
            buffer[b] ^= (128 >> m);
            buffer[n-1-b] ^=  (1 << m);
        } // if i and j (two opposite bits) don't equal, flip them
    }
}

/* The following is a test of the even_nodes method functionality */

int main() {

    printf( "\n===== Test 1 =====\n");

    unsigned char buffer[4] = {'L', 'b', '$', 'd'};
    size_t n = sizeof(buffer);

    print_bytes(buffer, n);
    reverse_bytes(buffer, n);
    print_bytes(buffer, n);

    printf( "\n===== Test 2 =====\n");

    unsigned char buffer2[1] = {'d'};
    size_t n2 = sizeof(buffer2);

    print_bytes(buffer2, n2);
    reverse_bytes(buffer2, n2);
    print_bytes(buffer2, n2);

    printf("\n");
    
    return 0;
}

/* End of test */
