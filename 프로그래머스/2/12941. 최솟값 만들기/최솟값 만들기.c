#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); // 오름차순
}

int desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a); // 내림차순
}

int solution(int A[], size_t A_len, int B[], size_t B_len) {
    int answer = 0;
    qsort(A, A_len, sizeof(int), cmp);
    qsort(B, B_len, sizeof(int), desc);
    
    for( int i = 0; i < A_len; i++ )
    {
        answer += A[i] * B[i];
    }
    
    return answer;
}