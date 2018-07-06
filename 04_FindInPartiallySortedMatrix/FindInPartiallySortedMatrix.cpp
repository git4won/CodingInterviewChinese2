/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。


/* 修改
 * 
 * 日期：20180706
 * 1、增加从左下角开始查找的方法（原方法为从右上角开始查找）
 * 2、对Test函数第一个参数增加const修饰符，避免警告： 
 *    warning: ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]
 *
 * by won
 */

#include <cstdio>

#if 0
/* 从右上角开始 */
bool Find(int* matrix, int rows, int columns, int number)
{
    bool found = false;

    if(matrix != nullptr && rows > 0 && columns > 0)
    {
        int row = 0;
        int column = columns - 1;
        while(row < rows && column >=0)
        {
            if(matrix[row * columns + column] == number)
            {
                found = true;
                break;
            }
            else if(matrix[row * columns + column] > number)
                -- column;
            else
                ++ row;
        }
    }

    return found;
}

#else

/* 从左下角开始 */
bool Find(int *matrix, int rows, int columns, int number)
{
    bool found = false;
    
    if (matrix == nullptr || rows < 1 || columns < 1)
    {
        return false;
    }

    int row = rows - 1;
    int column = 0;

    while (row >= 0 && column < columns)
    {
        //printf("matrix[%d][%d] = %d\n", row, column, matrix[row * columns + column]);
        if (matrix[row * columns + column] == number)
        {
            found = true;
            break;
        }
        else if (matrix[row * columns + column] > number)
        {
            row--;
        }
        else
        {
            column++;
        }
    }

    return found;
}
#endif

// ====================测试代码====================
void Test(const char* testName, int* matrix, int rows, int columns, int number, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    bool result = Find(matrix, rows, columns, number);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数在数组中
void Test1()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test1", (int*)matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数不在数组中
void Test2()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test2", (int*)matrix, 4, 4, 5, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最小的数字
void Test3()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test3", (int*)matrix, 4, 4, 1, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最大的数字
void Test4()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test4", (int*)matrix, 4, 4, 15, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最小的数字还小
void Test5()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test5", (int*)matrix, 4, 4, 0, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最大的数字还大
void Test6()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test6", (int*)matrix, 4, 4, 16, false);
}

// 鲁棒性测试，输入空指针
void Test7()
{
    Test("Test7", nullptr, 0, 0, 16, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}

