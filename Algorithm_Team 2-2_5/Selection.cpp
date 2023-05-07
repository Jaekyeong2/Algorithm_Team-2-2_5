/*
���α׷�����: ������ �̿��� ���ù��� ����
������: �ҿ���, �����
�ǽ���: 2023-05-06
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
    fp = fopen("data.txt", "r"); //�б�� ���� ���� 

    if (fp == NULL)
        printf("���Ͽ��� ����");

    for (i = 0; i < size; i++)
    {
        if (fscanf(fp, "%d", &num) == 1) // ���Ͽ��� ���� �б�
        {
            array[i] = num;
        }
        else
        {
            printf("�б� ����\n");
            break;
        }
    }

    printf("�����б� ����!\n");

    fclose(fp);
}

int Selection(int array[], int left, int right, int k)
{
    if (left == right)
        return array[left];

    int p = left;
    int i;
    int pivot = (left + right) / 2; // �߰� ���� �Ǻ����� ����
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
        printf("���°�� �������� ã�����: ");
        scanf("%d", &num);
    }
    Read_File(array, MAX_SIZE_ARRAY);
    result = Selection(array, 0, MAX_SIZE_ARRAY - 1, num);

    printf("%d��°�� ���� ���� %d�Դϴ�.", num, result);

    return 0;
}