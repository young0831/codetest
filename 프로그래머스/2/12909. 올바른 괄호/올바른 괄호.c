#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다.
bool solution(const char* s) {
    bool answer = true;
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(')
            count++;
        else
            count--;

        if (count < 0) {
            answer = false;
            break;  // 이미 잘못된 괄호이므로 더 볼 필요 없음
        }
    }

    if (count != 0) {
        answer = false;
    }

    return answer;
}
