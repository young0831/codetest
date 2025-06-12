#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* k = s;
    int len = strlen(s);
    char* answer = (char*)malloc(len);
    for ( int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            //ascii code를 적용한 문제 인듯
            // 
            if(k[i] >= k[j])
            {
                char temp;
                temp = k[j];
                k[j] = k[i];
                k[i] = temp;
            }
        }
    }
    strcpy(answer, k);
    return answer;
}