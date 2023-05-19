//Q2

//Zain really likes math. He would like to count the number of transitions 
//from k to 1 with 2 simple rules:
// - If k is odd, go to 3k + 1
// - If k is even, go to k / 2
// For example, if k = 5 initially: 5 -> 16 -> 8 -> 4 -> 2 -> 1 = 6 transitions.
// This must be done RECURSIVELY!
int countTransitions(int k) {
    int transitions = 1;
    if (k == 1) {
        return transitions;
    }
    if (k % 2 == 1) {
        transitions += countTransitions(3 * k + 1);
    }
    else {
        transitions += countTransitions(k / 2);
    }
    return transitions;
}


//Q3

// Nicole really likes cookies, however she is picky about which ones so she keeps an 
//integer cookies that represents the bitmask of the cookies she likes. In her city, 
//there are n cookie stores, each of which are an integer that represents the cookies 
//available at that store (bit is set to 1 if in stock, bit is set to 0 if out of stock).
 //Return the number of cookies she will be able to buy after visiting all n stores. 
 //NOTE: Each store only has 1 of any given cookie they have in stock.

// Feel free to use this helper function, assume it works perfectly
// Returns the number of bits on in an integer

//Counts number of bits that = 1 in an int
int countBitsOn(int mask);

int buyCookies(int cookies, int* stores, int n) {
    int cookieNum = 0;
    for (int i = 0; i < n; i++) {
        cookieNum += countBitsOn(cookies & stores[i]);
    }
    return cookieNum;
}
