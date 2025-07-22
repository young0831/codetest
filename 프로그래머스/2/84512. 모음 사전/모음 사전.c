#include <stdio.h>

#include <string.h>

int solution(const char* word) {

    char dict[6] = "AEIOU";  // 5개 모음

    int weight[5] = {781, 156, 31, 6, 1};  // 각 자리 가중치

    int answer = 0;

    for (int i = 0; word[i] != '\0'; i++) {

        for (int j = 0; j < 5; j++) {

            if (word[i] == dict[j]) {

                answer += j * weight[i];  // 현재 문자 위치에서 가능한 모든 조합 수 더하기

                break;

            }

        }

        answer += 1;  // 자기 자신을 포함하기 위해 +1

    }

    return answer;

}