#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sizes_rows는 2차원 배열 sizes의 행 길이, sizes_cols는 2차원 배열 sizes의 열 길이입니다.
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int answer = 0;
    int cmp_row1 = 0;
    int cmp_row2 = 0;
    // 1. 포인터 배열내에서 각 배열에 가장작은 수가 앞으로 오도록 구성
    for (int i = 0; i < sizes_rows; i++)
    {
        if(sizes[i][0] > sizes[i][1])
        {
            int temp;
            temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
        if(sizes[i][0] > cmp_row1)
             cmp_row1 = sizes[i][0];
        if(sizes[i][1] > cmp_row2)
            cmp_row2 = sizes[i][1];
    }
    
    answer = cmp_row1 * cmp_row2;
    // 2. 배열내 첫번째 인자가 가장 큰 수와 두번째 인자가 가장 큰 수를 선별
    
    // 3. 가장 큰 두 인자를 곱하여 결과를 출력
    
    
    
    return answer;
}