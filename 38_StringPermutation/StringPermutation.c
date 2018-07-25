/*================================================================
*   File Name   : StringPermutation.c
*   Author      : ZhengFuYuan
*   Create Date : 2018-07-25
*   Description : String permutation program write with C Language.
================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Permutation(char *pStr, char *pBegin)
{
    /* �������� */
    if (*pBegin == '\0')
    {
        printf("%s\n", pStr);
    }
    else
    {
        for (char *pCh = pBegin; *pCh != '\0'; ++pCh)
        {
            /* �������ַ����n���ַ���λ�� */
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;

            Permutation(pStr, pBegin + 1);

            /* �����ַ���������������һ��ѭ���Ļ��� */
            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
        }
    }
}

void PermutationString(char *pStr)
{
    if (pStr != NULL)
    {
        Permutation(pStr, pStr);
    }
}

int main()
{
    char string1[] = "abcd";
    PermutationString(string1);

    char string2[] = "a";
    PermutationString(string2);

    char string3[] = "";
    PermutationString(string3);

    return 0;
}
