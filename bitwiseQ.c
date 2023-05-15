#define SIZE 20
#include <stdio.h>
#include <math.h>

int canWinNIM(int piles[], int numPiles) {
    int mask = 1;
    for (int i = 0; i < numPiles; i++) {
        if (piles[i] ^ mask == 0) {
            return 0;
        }
        mask << 1;
    }
    return 1;
}

int paintFence(int pattern, int paintLoc[], int paintLen) {
    int fenceState = 0;
    for (int i = 0; i < paintLen; i++) {
        fenceState += paintLoc[i] & pattern;
    }
    return fenceState;
}

//33
//100001
//answered yes to 0 & 5
//score is 0 bc 8 is highest priority

int score(int preferences[], int applicant) {
    int res = 0;
    for (int i = 0; i < SIZE; i++) {
        if (preferences[i] & applicant != 0) {
            res++;
            applicant >> 1;
        }
        else break;
    }
    return res;
}

int lowestOneBit(int n) {
    int lowest;
    for (lowest = 0; lowest < n; lowest++) {
        if (n & (1 << lowest) == 1) {
            break;
        }
    }
    return pow(2, lowest);
}

int highestOneBit(int n) {
    int highest;
    for (highest = 0; highest < n; highest++) {
        if (n & (1 << highest) == 1) {
            break;
        }
    }
    return pow(2, highest);
}

int main(void) {
    int piles[] = { 10, 14, 20, 50 };
    printf("Result: %d\n", canWinNIM(piles, 4));
    return 0;
}
