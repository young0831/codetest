#include <stdio.h>
#include <stdlib.h>

#define MAX 100000000  // 귤 크기 최대값 (입력 범위에 따라 조절 가능)

// 비교 함수: 내림차순 정렬용
int desc(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int solution(int k, int tangerine[], size_t tangerine_len) {
    int count[MAX] = {0};  // 크기별 등장 횟수 저장
    int freq[100000];      // 등장 횟수만 따로 저장 (종류 수만큼)

    // 1. 크기별 등장 횟수 세기
    for (size_t i = 0; i < tangerine_len; i++) {
        count[tangerine[i]]++;
    }

    // 2. freq 배열에 등장 횟수만 저장
    int freq_len = 0;
    for (int i = 0; i < MAX; i++) {
        if (count[i] > 0) {
            freq[freq_len++] = count[i];
        }
    }

    // 3. 내림차순 정렬
    qsort(freq, freq_len, sizeof(int), desc);

    // 4. 앞에서부터 누적합하며 k 이상이면 종류 수 반환
    int sum = 0;
    for (int i = 0; i < freq_len; i++) {
        sum += freq[i];
        if (sum >= k)
            return i + 1;  // 종류 수
    }

    return freq_len;
}
