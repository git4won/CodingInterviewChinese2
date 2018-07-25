/*================================================================
*   File Name   : CopyComplexList.c
*   Author      : ZhengFuYuan
*   Create Date : 2018-07-15
*   Description : Copy complex list program write with C Language.  
================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ComplexListNode
{
    int                        m_nValue;
    struct ComplexListNode*    m_pNext;
    struct ComplexListNode*    m_pSibling;
}ComplexListNode;

/* 生成新节点 */
ComplexListNode *CreateNode(int nValue)
{
    ComplexListNode *pNode = NULL;
    pNode = (ComplexListNode *)malloc(sizeof(ComplexListNode));
    if (pNode == NULL)
    {
        return NULL;
    }

    pNode->m_nValue = nValue;
    pNode->m_pNext = NULL;
    pNode->m_pSibling = NULL;

    return pNode;
}

/* 创建连接 */
void BuildNodes(ComplexListNode *pNode, ComplexListNode *pNext, ComplexListNode *pSibling)
{
    if (pNode != NULL)
    {
        pNode->m_pNext = pNext;
        pNode->m_pSibling = pSibling;
    }
}

/* 打印链表 */
void PrintList(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    
    while (pNode != NULL)
    {
        printf("The value of this node is %d.\n", pNode->m_nValue);
    
        if (pNode->m_pSibling != NULL)
        {
            printf("The value of its sibling is %d.\n", pNode->m_pSibling->m_nValue);
        }
        else
        {
            printf("This node does not have a sibling.\n");
        }
        printf("\n");
    
        pNode = pNode->m_pNext;
    }
}

/* 在原来的链上复制节点 */
void CloneNodes(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    while (pNode != NULL)
    {
        ComplexListNode *pClone = NULL;
        pClone = (ComplexListNode *)malloc(sizeof(ComplexListNode));
        if (pClone != NULL)
        {
            pClone->m_nValue = pNode->m_nValue;
            pClone->m_pNext = pNode->m_pNext;
            pClone->m_pSibling = NULL;

            pNode->m_pNext = pClone;

            pNode = pClone->m_pNext;
        }
    }
}

/* 复制 m_pSibling 指针 */
void ConnectSiblingNodes(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    while (pNode != NULL)
    {
        if (pNode->m_pSibling != NULL)
        {
            pNode->m_pNext->m_pSibling = pNode->m_pSibling->m_pNext;
        }
        pNode = pNode->m_pNext->m_pNext;
    }
}

/* 修改指针，将原链表和Clone链表分离 */
ComplexListNode *ReconnectNodes(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    ComplexListNode *pClonedHead = NULL;
    ComplexListNode *pClonedNode = NULL;

    if (pNode != NULL)
    {
        pClonedHead = pClonedNode = pNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;

        while (pNode != NULL)
        {
            pClonedNode->m_pNext = pNode->m_pNext;
            pClonedNode = pClonedNode->m_pNext;

            pNode->m_pNext = pClonedNode->m_pNext;
            pNode = pNode->m_pNext;
        }
    }

    return pClonedHead;
}

/* 复制链表 */
ComplexListNode *Clone(ComplexListNode *pHead)
{
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}

ComplexListNode *BuildListTest()
{
    ComplexListNode *pNode1 = CreateNode(1);
    ComplexListNode *pNode2 = CreateNode(2);
    ComplexListNode *pNode3 = CreateNode(3);
    ComplexListNode *pNode4 = CreateNode(4);
    ComplexListNode *pNode5 = CreateNode(5);
    
    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, NULL);
    BuildNodes(pNode4, pNode5, pNode2);

    return pNode1;
}

int main()
{
    ComplexListNode *pHead = BuildListTest();
    if (pHead != NULL)
    {
        PrintList(pHead);
    }

    ComplexListNode *pClonedHead = Clone(pHead);
    if (pClonedHead != NULL)
    {
        PrintList(pClonedHead);
    }

    return 0;
}
