/*
프로그램설명: 파일을 이용한 선택문제 구현
개발자: 소예찬, 김재경
실습일: 2023-05-06
*/
#include <stdio.h>
#define MAX_SIZE_ARRAY 10
void swap(int* px, int* py)
{
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}
void Read_File(int array[], int size)
{
    int i, num;
    FILE* fp = NULL;
    fp = fopen("data.txt", "r"); //읽기용 파일 열기 

    if (fp == NULL)
        printf("파일열기 실패");

    for (i = 0; i < size; i++)
    {
        if (fscanf(fp, "%d", &num) == 1) // 파일에서 정수 읽기
        {
            array[i] = num;
        }
        else
        {
            printf("읽기 실패\n");
            break;
        }
    }

    printf("파일읽기 성공!\n");

    fclose(fp);
}

int Selection(int array[], int left, int right, int k)
{
    if (left == right)
        return array[left];

    int p = left;
    int i;
    int pivot = (left + right) / 2; // 중간 값을 피봇으로 선택
    swap(&array[pivot], &array[left]);


    for (i = left + 1; i <= right; i++)
    {
        if (array[i] < array[left]) {
            p++;
            swap(&array[p], &array[i]);
        }
    }

    swap(&array[left], &array[p]);

    int S = p - left;

    if (k <= S)
    {
        return Selection(array, left, p - 1, k);
    }
    else if (k == S + 1)
    {
        return array[p];
    }
    else
    {
        return Selection(array, p + 1, right, k - S - 1);
    }
}

int main(void)
{
    int array[MAX_SIZE_ARRAY] = { 0 };
    int num = MAX_SIZE_ARRAY + 1;
    int result;

    while (num > MAX_SIZE_ARRAY)
    {
        printf("몇번째로 작은값을 찾을까요: ");
        scanf("%d", &num);
    }
    Read_File(array, MAX_SIZE_ARRAY);
    result = Selection(array, 0, MAX_SIZE_ARRAY - 1, num);

    printf("%d번째로 작은 수는 %d입니다.", num, result);

    return 0;
}