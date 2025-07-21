#include <stdio.h>

#include <stdlib.h>

int* solution(int numbers[], size_t numbers_len) {

    int* answer = (int*)malloc(sizeof(int) * numbers_len);

    int* stack = (int*)malloc(sizeof(int) * numbers_len); // index 저장용

    int top = -1;

    for (int i = numbers_len - 1; i >= 0; i--) {

        // 스택에서 현재 숫자보다 작거나 같은 수 제거

        while (top >= 0 && numbers[stack[top]] <= numbers[i]) {

            top--;

        }

        // 스택이 비어있으면 뒤에 큰 수 없음

        if (top == -1) {

            answer[i] = -1;

        } else {

            answer[i] = numbers[stack[top]];

        }

        // 현재 인덱스 스택에 push

        stack[++top] = i;

    }

    free(stack);

    return answer;

}