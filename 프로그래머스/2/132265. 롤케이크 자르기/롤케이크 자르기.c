#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

#define MAX_TOPPING 10001

int solution(int topping[], size_t topping_len) {

    int answer = 0;

    int left[MAX_TOPPING] = {0};   // 왼쪽 토핑 종류별 개수

    int right[MAX_TOPPING] = {0};  // 오른쪽 토핑 종류별 개수

    int left_kind = 0;             // 왼쪽 종류 개수

    int right_kind = 0;            // 오른쪽 종류 개수

    // 초기: 오른쪽 전부 다 넣어두기

    for (int i = 0; i < topping_len; i++) {

        if (right[topping[i]] == 0) right_kind++;

        right[topping[i]]++;

    }

    for (int i = 0; i < topping_len - 1; i++) {

        // 왼쪽에 하나 추가

        if (left[topping[i]] == 0) left_kind++;

        left[topping[i]]++;

        // 오른쪽에서 하나 제거

        right[topping[i]]--;

        if (right[topping[i]] == 0) right_kind--;

        // 공평하게 나눠졌는지 확인

        if (left_kind == right_kind) answer++;

    }

    return answer;

}