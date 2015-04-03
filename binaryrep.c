/**
 * @author Matthew Scott Levan
 * @university CSU, Dominguez Hills
 * @professor Malcolm McCullough
 * @semester Spring 2015
 * @course CSC-321 Programming Languages
 * @project Programming Project 01
 *
 * A program that reads in a 32-bit unsigned int and a 32-bit
 * unsigned float, then prints the values and their respective
 * binary representations by using bitwise operators (&, |, <<).
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, m, i; // user int, iterator
    float f; // user float
    int mask = (1 << 31); // mask with 32nd bit = 1

    printf("Enter an integer to display its binary representation: ");
    scanf("%d", &n);

    printf("Enter a float to display its binary representation: ");
    scanf("%f", &f);

    printf("\n%d in binary is:", n);

    // loop through and check each bit
    for (i = 31; i >= 0; i--) {
        if ((i+1) % 8 == 0) {
            printf(" ");
        }

        if ((n & mask) > 0) {
            printf("1");
        }
        else {
            printf("0");
        }

        mask = (1 << (i-1));
    }

    // reset mask
    mask = (1 << 31);

    // cast f to int m
    m = *(int*)&f;

    printf("\n%.2f in binary is:", f);

    for (i = 31; i >= 0; i--) {
        if ((i+1) % 8 == 0) {
            printf(" ");
        }

        if ((m & mask) > 0) {
            printf("1");
        }
        else {
            printf("0");
        }

        mask = (1 << (i-1));
    }

    printf("\n");

    return EXIT_SUCCESS;
}
