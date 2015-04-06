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
    signed int userInt, castInt, i; // user int, int for casting to, iterator
    float userFloat; // user float value
    int mask = (1 << 31); // mask with 32nd bit = 1

    // get integer
    printf("Enter an integer to display its binary representation: ");
    scanf("%d", &userInt);

    // get float
    printf("Enter a float to display its binary representation: ");
    scanf("%f", &userFloat);

    printf("\n%d in binary is:", userInt);

    // loop 32 times and check each bit against the mask
    for (i = 31; i >= 0; i--) {
        // print a space between every 8 bits for readability
        if ((i+1) % 8 == 0) {
            printf(" ");
        }
        // use bitwise & to compare userInt with mask
        // if > 0, current bit of userInt is 1; print it
        if ((userInt & mask) > 0) {
            printf("1");
        }
        else {
            printf("0");
        }
        // shift mask by i
        mask = (1 << (i-1));
    }

    // reset mask
    mask = (1 << 31);

    // cast userFloat to castInt by casting the address of userFloat to an int *
    // then dereferencing it, thereby simply taking the raw bits
    // from the float userFloat and storing them in the int castInt 
    //    m = *(int*)&userFloat;

    castInt = (int) &userFloat;

    printf("\n%.2f in binary is:", userFloat);

    for (i = 31; i >= 0; i--) {
        if ((i+1) % 8 == 0) {
            printf(" ");
        }

        if ((castInt & mask) > 0) {
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
