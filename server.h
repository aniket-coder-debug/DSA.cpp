#include<iostream>
using std :: cout;
using std :: endl;

#define MAX 5

class stack;

class node
{
    int iData;
    node *pNext;

public:
    node()
    {
        iData = 0;
        pNext = NULL;
    }

    ~node()
    {
        iData = 0;
        pNext = NULL;
    }

    friend class stack;
};

class stack
{
    node *pStack;

public:
    stack()
    {
        pStack = NULL;
    }
    ~stack()
    {
        if(pStack != NULL)
        {
            DeleteAll();
            pStack = NULL;
        }
    }
    
    void Push(int iNo)
    {
        node *pNewNode = NULL;

        if(IsFull())
        {
            cout << "\nStack Overflow\n";
            return;
        }

        pNewNode = new node;
        if(pNewNode == NULL)
        {
            cout << "\nMemory allocation FAILED\n";
            return;
        }

        pNewNode -> iData = iNo;

        if(NULL == pStack)
            pNewNode -> pNext = NULL;
        else
            pNewNode -> pNext = pStack;

        pStack = pNewNode;
    }

    int Pop()
    {
        int iDelData;
        node *pTemp = NULL;

        if(IsEmpty())
        {
            cout << "\nStack is empty\n";
            return -1;
        }

        pTemp = pStack;
        pStack = pTemp -> pNext;

        iDelData = pTemp -> iData;
        pTemp -> pNext = NULL;
        delete pTemp;

        return iDelData;
    }

    int IsFull()
    {
        node *pHead = pStack;

        if(CountNodes() == MAX)
            return 1;
        return 0;
    }

    int IsEmpty()
    {
        node *pHead = pStack;

        if(NULL == pHead)
            return 1;
        return 0;
    }

    void Display()
    {
        node *pHead = pStack;

        if(NULL == pHead)
        {
            cout << "\n\nStack is emtpy\n";
            return;
        }

        cout << "List is:\n";
        while(pHead != NULL)
        {
            cout << "|" << pHead -> iData << "|-> ";
            pHead = pHead -> pNext;
        }
    }

    int CountNodes()
    {
        node *pHead = pStack;

        int iCount = 0;

        while(pHead != NULL)
        {
            iCount++;
            pHead = pHead -> pNext;
        }

        return iCount;
    }

    void DeleteAll()
    {
        struct node *pTemp = NULL;

        while(NULL != pStack)
        {
            pTemp = pStack;
            pStack = pTemp -> pNext;
            delete pTemp;
        }
    }
};