#include<stdio.h>

// Mathematically, given a function f, we recursively define fk(n) as follows: if k = 1, f1(n) = f(n).
// Otherwise, for k > 1, fk(n) = f(fk-1(n)). Assume that a function, f, which takes in a single integer and
// returns an integer already exists. Write a recursive function fcomp, which takes in both n and k (k > 0),
// and returns fk(n).

int f(int n) {
    return n;
}

int fcomp(int n, int k) {
    if (k == 1) {
        return f(n);
    }
    return f(fcomp(n, k - 1));
}

int zeros(int n) {
    int res = 0;
    while (n != 0) {
        res += n / 5;
        n /= 5;
    }
    return res;
}

//Rewrite this method recursively:

int zerosRec(int n) {
    if (n == 0) {
        return 0;
    }
    return n / 5 + zerosRec(n / 5);
}


/*
Write a recursive function that returns the sum of all of the even elements in an
integer array vals, in between the indexes low and high, inclusive. For example,
 for the function call sumEven(vals, 3, 8) with the array vals shown below,
 the function should return 24 + 8 + 10 = 42, since these three numbers are
the only even numbers stored in the array in between index 3 and index 8, inclusive.
*/

int sumEven(int vals[], int low, int high) {
    if (high < low) {
        return 0;
    }

    int res = vals[high];

    if (vals[high] % 2 == 0) {
        return res + sumEven(vals, low, high - 1);
    }

    return sumEven(vals, low, high - 1);
}

// Write a recursive function that returns the product of the digits of its 
//integer input parameter, n. You may assume that n is non-negative. For example,
// productDigits(274) should return 56, since 2 x 7 x 4 = 56.

int productDigits(int n) {
    if (n < 10) {
        return n;
    }
    int res = 0;
    res = 10 * productDigits(n % 10);
}

int main(void) {
    printf("\nResult: %d\n", zerosRec(25));
    return 0;
}
