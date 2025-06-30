#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 중복 없는 정수 저장용 hash set
#define MAX_SUM 1000000
bool visited[MAX_SUM + 1] = { false };

int solution(int elements[], size_t elements_len) {
    int answer = 0;

    // 원형 수열을 처리하기 위해 두 배로 복사
    int double_elements[2 * elements_len];
    for (int i = 0; i < 2 * elements_len; i++) {
        double_elements[i] = elements[i % elements_len];
    }

    // 부분 수열 길이 1부터 elements_len까지
    for (int len = 1; len <= elements_len; len++) {
        for (int start = 0; start < elements_len; start++) {
            int sum = 0;
            for (int k = 0; k < len; k++) {
                sum += double_elements[start + k];
            }
            if (!visited[sum]) {
                visited[sum] = true;
                answer++;
            }
        }
    }

    return answer;
}
