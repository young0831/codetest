#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* t, const char* p) {
    int answer = 0;
    int t_len = strlen(t);
    int p_len = strlen(p);

    char t_cmp[21]; // 최대 20자리 숫자 + 널 문자
    long long p_val = atoll(p); // p를 long long으로 변환

    for (int i = 0; i <= t_len - p_len; i++) {
        strncpy(t_cmp, t + i, p_len);
        t_cmp[p_len] = '\0'; // 문자열 끝 표시

        long long t_val = atoll(t_cmp);
        if (t_val <= p_val) {
            answer++;
        }
    }

    return answer;
}
