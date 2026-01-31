#include "server.h"

node::node()
{
    iData = NULL;
    pNext = NULL;
}
node::~node()
{
    iData = NULL;
    pNext = NULL;
}

queue::queue()
{
    pPtr = NULL;
}
queue::~queue()
{
    pPtr = NULL;
}

void queue::EnQueue(BST *pRoot)
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

    pNewNode -> iData = pRoot ;
    pNewNode -> pNext = NULL;

    if(pPtr == NULL)
    {
        pPtr = pNewNode;
        return;
    }

    pTemp = pPtr;
    while(pTemp -> pNext != NULL)
        pTemp = pTemp -> pNext;

    pTemp -> pNext = pNewNode;
}

BST* queue::DeQueue()
{
    BST *DelData = NULL ;
    node *pTemp = NULL;

    if(IsQueueEmpty())
    {
        cout << "\nQueue is Empty\n";
        return NULL;
    }

    pTemp = pPtr;
    pPtr = pTemp -> pNext;

    DelData = pTemp -> iData;
    pTemp -> pNext = NULL;
    delete pTemp;

    return DelData ;
}

bool queue::IsQueueFull()
{
    if(CountNodes() == MAX)
        return true;
    return false;
}

bool queue::IsQueueEmpty()
{
    if(NULL == pPtr)
        return true;
    return false;
}

int queue::CountNodes()
{
    node* pTemp = pPtr;
    int iCount = 0;

    while(pTemp != NULL)
    {
        iCount++;
        pTemp = pTemp -> pNext;
    }

    return iCount;
}
