#include<iostream>
#define MAX 5

using std :: cout;
using std :: endl;

class queue;

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

    friend class queue;
};

class queue
{
    node *pQueue;

public:
    queue()
    {
        pQueue = NULL;
    }
    ~queue()
    {
        if(pQueue != NULL)
        {
            DeleteAll();
            pQueue = NULL;
        }
    }

    void EnQueue(int iNo)
    {
        node *pNewNode = NULL;
        node *pTemp = NULL;
    
        if(IsQueueFull())
        {
            cout << "\nQueue is Full\n";
            return ;
        }
    
        pNewNode = new node;
        if(NULL == pNewNode)
        {
            cout << "Memory allocation FAILED\n";
            return;
        }
    
        pNewNode -> iData = iNo;
        pNewNode -> pNext = NULL;
    
        if(pQueue == NULL)
        {
            pQueue = pNewNode;
            return;
        }
    
        pTemp = pQueue;
        while(pTemp -> pNext != NULL)
            pTemp = pTemp -> pNext;
    
        pTemp -> pNext = pNewNode;
    
    }

    int DeQueue()
    {
        int iDelData;
        node *pTemp = NULL;

        if(IsQueueEmpty())
        {
            cout << "\nQueue is Empty\n";
            return -1;
        }

        pTemp = pQueue;
        pQueue = pTemp -> pNext;

        iDelData = pTemp -> iData;
        pTemp -> pNext = NULL;
        delete pTemp;

        return iDelData;
    }

    int IsQueueFull()
    {
        node *pHead = pQueue;

        if(CountNodes() == MAX)
            return 1;
        return 0;
    }

    int IsQueueEmpty()
    {
        node *pHead = pQueue;

        if(NULL == pHead)
            return 1;
        return 0;
    }

    void Display()
    {
        node *pHead = pQueue;

        if(NULL == pHead)
        {
            cout << "\nList is emtpy\n";
            return;
        }

        while(pHead != NULL)
        {
            cout << "|" << pHead -> iData << "|->";
            pHead = pHead -> pNext;
        }
    }

    int CountNodes()
    {
        node *pHead = pQueue;

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
        node *pTemp = NULL;

        while(NULL != pQueue)
        {
            pTemp = pQueue;
            pQueue = pTemp -> pNext;
            delete pTemp;
        }
    }
};
