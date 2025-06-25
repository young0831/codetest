#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    int a = 1;  // dp[i-2]
    int b = 2;  // dp[i-1]
    int result = 0;

    for (int i = 3; i <= n; i++) {
        result = (a + b) % 1234567;
        a = b;
        b = result;
    }
    return result;
}