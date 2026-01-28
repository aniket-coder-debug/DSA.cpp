#include <iostream>

using std :: cout;
using std :: endl;

class list;

class node
{
    node *pPrev;
    int iData;
    node *pNext;

public:
    node()
    {
        pPrev = NULL;
        iData = 0;
        pNext = NULL;
    }

    ~node()
    {
        pPrev = NULL;
        iData = 0;
        pNext = NULL;
    }

    friend class list;
};


class list
{
    node *pFirst;
    node *pLast;

public:
    list()
    {
        pFirst = NULL;
        pLast = NULL;
    }

    ~list()
    {
        if(pFirst != NULL)
        {
            DeleteAll();
            pFirst = NULL;
            pLast = NULL;
        }
    }

    void InsertFirst(int iNo)
    {
        node *pNewNode = NULL;

        pNewNode = new node;
        if(pNewNode == NULL)
        {
            cout << "\nMemory allocation FAILED\n";
            return;
        }

        pNewNode -> iData = iNo;

        if(pFirst == NULL)
        {
            pFirst = pNewNode;
            pLast = pNewNode;
            (pFirst) -> pPrev = pLast;
            (pLast) -> pNext = pFirst;
            return;
        }

        pNewNode -> pNext = pFirst;
        (pFirst) -> pPrev = pNewNode;
        pFirst = pNewNode;
        (pFirst) -> pPrev = pLast;
        (pLast) -> pNext = pFirst;
    }

    void InsertLast(int iNo)
    {
        node *pNewNode = NULL;

        pNewNode = new node;
        if(NULL == pNewNode)
        {
            cout << "\nMemory allocation Failed\n";
            return;
        }

        pNewNode -> iData = iNo;

        if(pFirst == NULL)
        {
            pFirst = pNewNode;
            pLast = pNewNode;
            pFirst -> pPrev = pLast;
            pLast -> pNext = pFirst;

            return;
        }

        pLast -> pNext = pNewNode;
        pNewNode -> pPrev = pLast;
        pLast = pNewNode;
        pLast -> pNext = pFirst;
        pFirst -> pPrev = pLast;
    }

    void InsertAtPosition(int iNo , int iPos)
    {
        node *pNewNode = NULL;
        node *pTemp = NULL;
        int iCount;

        iCount = CountNodes();
        if(iPos <= 0 || iPos > iCount + 1 )
        {
            cout << "\nInvalid position\n";
            return;
        }

        if(1 == iPos)
        {
            InsertFirst(iNo);
            return;
        }

        if(iPos == iCount + 1)
        {
            InsertLast(iNo);
            return;
        }

        pNewNode = new node;
        if(NULL == pNewNode)
        {
            cout << "\nMemory allocation Failed\n";
            return;
        }

        pNewNode -> iData = iNo;

        pTemp = pFirst;
        iCount = 1;
        while(iCount < iPos - 1)
        {
            ++iCount;
            pTemp = pTemp -> pNext;
        }

        pNewNode -> pNext = pTemp -> pNext;
        pTemp -> pNext -> pPrev = pNewNode;
        pNewNode -> pPrev = pTemp;
        pTemp -> pNext = pNewNode;
    }

    int DeleteFirst()
    {
        int iDelData;

        if(NULL == pFirst)
            return -1;

        iDelData = pFirst -> iData;

        if(pFirst == pLast)
        {
            delete pFirst;
            pFirst = pLast = NULL;
        }
        else
        {
            pFirst = pFirst -> pNext;
            delete pLast -> pNext;
            pLast -> pNext = pFirst;
            pFirst -> pPrev = pLast;
        }

        return iDelData;
    }

    int DeleteLast()
    {
        int iDelData;

        if(NULL == pFirst)
            return -1;

        iDelData = pLast -> iData;

        if(pFirst == pLast)
        {
            delete pFirst;
            pFirst = NULL;
            pLast = NULL;
        }
        else
        {
            pLast = pLast -> pPrev;
            delete pLast -> pNext;
            pLast -> pNext = pFirst;
            pFirst -> pPrev = pLast;
        }

        return iDelData;
    }

    int DeleteAtPosition(int iPos)
    {
        node *pTemp = NULL;
        int iCount;

        if(NULL == pFirst)
            return -1;

        iCount = CountNodes();
        if(iPos <= 0 || iPos > iCount)
        {
            cout << "\nInvalid Position\n";
            return -1;
        }

        if(1 == iPos)
            return DeleteFirst();

        if(iPos == iCount)
            return DeleteLast();

        pTemp = pFirst;
        iCount = 1;
        while(iCount < iPos)
        {
            ++iCount;
            pTemp = pTemp -> pNext;
        }

        iCount = pTemp -> iData;
        pTemp -> pPrev -> pNext = pTemp -> pNext;
        pTemp -> pNext -> pPrev = pTemp -> pPrev;
        delete pTemp;

        return iCount;
    }

    int CountNodes()
    {
        node *pHead = pFirst;
        node *pTail = pLast;

        int iCount = 0;

        if(NULL == pHead)
            return 0;

        do
        {
            ++iCount;
            pHead = pHead -> pNext;

        } while (pHead != pTail -> pNext);

        return iCount;
        
    }

    int SearchFirstOccurrence(int iKey)
    {
        node *pHead = pFirst;
        node *pTail = pLast;

        int iPos = 0;

        if(NULL == pHead)
            return 0;

        do
        {
            ++iPos;

            if(iKey == pHead -> iData)
                return iPos;

            pHead = pHead -> pNext;

        } while (pHead != pTail -> pNext);

        return 0;
    }

    int SearchLastOccurrence(int iKey)
    {
        node *pHead = pFirst;
        node *pTail = pLast;

        int iPos = 0;
        int iLastPos = 0;

        if(NULL == pHead)
            return 0;

        do
        {
            ++iPos;

            if(iKey == pHead -> iData)
                iLastPos = iPos;

            pHead = pHead -> pNext;

        } while (pHead != pTail -> pNext);

        return iLastPos;
    }

    int SearchAllOccurrences(int iKey)
    {
        node *pHead = pFirst;
        node *pTail = pLast;

        int iCount = 0;

        if(NULL == pHead)
            return 0;

        do
        {
            if(iKey == pHead -> iData)
                ++iCount;

            pHead = pHead -> pNext;

        } while (pHead != pTail -> pNext);

        return iCount;
    }

    void Display()
    {
        node *pHead = pFirst;
        node *pTail = pLast;

        if(NULL == pHead)
        {
            cout << "\nList is Empty\n";
            return;
        }

        cout << "\nList is:\n";

        do
        {
            cout << "<-|" << pHead -> iData << "|->";
            pHead = pHead -> pNext;

        } while (pHead != pTail -> pNext);

        cout << endl;
        
    }

    void PhysicalReverse()
    {
        node *pCurrent = pFirst;
        node *pNext = NULL;

        if(NULL == pFirst)
            return;

        do
        {
            pNext = pCurrent -> pNext;
            pCurrent -> pNext = pCurrent -> pPrev;
            pCurrent -> pPrev = pNext;
            pCurrent = pNext;

        } while (pCurrent != pFirst);

        pLast = pCurrent;
        pFirst = pLast -> pNext;
    }

    void ReverseDisplay()
    {
        node *pHead = pFirst;
        node *pTail = pLast;

        if(NULL == pHead)
        {
            cout << "\nList is Empty\n";
            return ;
        }

        do
        {
            cout << "<-|" << pTail -> iData << "|->";
            pTail = pTail -> pPrev;

        } while (pTail != pHead -> pPrev);

        cout << endl;
        
    }

    void DeleteAll()
    {
        node *pTemp = NULL;

        pLast -> pNext = NULL;

        while(pFirst != NULL)
        {
            pTemp = pFirst;
            pFirst = pTemp -> pNext;
            delete pTemp;
        }

        pLast = NULL;
    }

    void ConcatLists(list &refobj)
    {
        if(NULL == refobj.pFirst)
            return ;

        if(NULL == pFirst)
        {
            pFirst = refobj.pFirst;
            pLast = refobj.pLast;

            refobj.pFirst = refobj.pLast = NULL;
            return;
        }

        pLast -> pNext = refobj.pFirst;
        refobj.pFirst -> pPrev = pLast;
        pLast = refobj.pLast;
        pFirst -> pPrev = pLast;
        pLast -> pNext = pFirst;

        refobj.pFirst = refobj.pLast = NULL;
    }

    void ConcatAtPosition(list &refobj ,int iPos)
    {
        int iCount;
        node *pTemp = NULL;

        iCount = CountNodes();
        if(iPos <= 0 || iPos > iCount + 1)
        {
            cout << "\nInvalid Position\n";
            return ;
        }

        if(NULL == refobj.pFirst)
            return;

        if(1 == iPos)
        {
            ConcatLists(refobj);
            pFirst = refobj.pFirst;
            pLast = refobj.pLast;

            refobj.pFirst = refobj.pLast = NULL;
            return;
        }

        if(iPos == iCount + 1)
        {
            ConcatLists(refobj);
            return;
        }

        pTemp = pFirst;
        iCount = 1;
        while(iCount < iPos - 1)
        {
            ++iCount;
            pTemp = pTemp -> pNext;
        }

        pTemp -> pNext -> pPrev = refobj.pLast;
        refobj.pLast -> pNext = pTemp -> pNext;
        pTemp -> pNext = refobj.pFirst;
        refobj.pFirst -> pPrev = pTemp;

        refobj.pFirst = refobj.pLast = NULL;
    }

};