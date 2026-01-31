#include <iostream>
#include"server.h"

BST::BST()
{
    pLChild = NULL;
    iData = 0;
    pRChild = NULL;
}
BST::~BST()
{
    pLChild = NULL;
    iData = 0;
    pRChild = NULL;
}

Tree::Tree()
{
    pRoot = NULL;
}
Tree::~Tree()
{
    cout << "\nIn Distructor\n";

    if(pRoot != NULL)
    {
        DeleteAll();
        pRoot = NULL;
    }
}


void Tree:: myPreorder(BST* pRoot)
{
    BST *pTemp = pRoot;

    if(NULL == pTemp)
        return ;

    cout << pTemp -> iData << " ";
    myPreorder(pTemp -> pLChild);
    myPreorder(pTemp -> pRChild);
}
void Tree::Preorder()
{
    myPreorder(pRoot);
}


void Tree::myInorder(BST *pRoot)
{
    BST *pTemp = pRoot;

    if(NULL == pTemp)
        return ;

    myInorder(pTemp -> pLChild);
    cout << pTemp -> iData << " ";
    myInorder(pTemp -> pRChild);
}
void Tree::Inorder()
{
    myInorder(pRoot);
}


void Tree::myPostorder(BST *pRoot)
{
    BST *pTemp = pRoot;

    if(NULL == pTemp)
        return ;

    myPostorder(pTemp -> pLChild);
    myPostorder(pTemp -> pRChild);
    cout << pTemp -> iData << " ";

}
void Tree::Postorder()
{
    myPostorder(pRoot);
}


void Tree::myLevelorder(BST *pRoot)
{
    queue obj;
    BST *pPtr = NULL;

    if(NULL == pRoot)
        return;

    obj.EnQueue(pRoot);

    while(! obj.IsQueueEmpty())
    {   
        pPtr = obj.DeQueue();

        cout << pPtr -> iData << " ";

        if(pPtr -> pLChild != NULL)
            obj.EnQueue(pPtr -> pLChild);

        if(pPtr -> pRChild != NULL)
            obj.EnQueue(pPtr -> pRChild);
    }
}

void Tree::Levelorder()
{
    myLevelorder(pRoot);
}

void Tree::myDeleteAll(BST **ppRoot)
{
    if(NULL == *ppRoot)
        return;

    myDeleteAll(&(*ppRoot) -> pLChild);
    myDeleteAll(&(*ppRoot) -> pRChild);
    delete *ppRoot;
    *ppRoot = NULL;
}

void Tree::DeleteAll()
{
    myDeleteAll(&pRoot);
}

int Tree::myCountBSTsVersion1(BST *pRoot)
{
    static int iCount = 0;

    if(NULL == pRoot)
        return 0;

    iCount ++;

    myCountBSTsVersion1(pRoot -> pLChild);
    myCountBSTsVersion1(pRoot -> pRChild);

    return iCount;

}

int Tree::CountBSTsVersion1()
{
    return myCountBSTsVersion1(pRoot);
}

int Tree::myCountBSTsVersion2(BST *pRoot)
{
    BST *pTemp = pRoot;

    if(NULL == pRoot)
        return 0;

    return myCountBSTsVersion2(pTemp -> pLChild) + myCountBSTsVersion2(pTemp -> pRChild) + 1 ;
}

int Tree::CountBSTsVersion2()
{
    return myCountBSTsVersion2(pRoot);
}

int Tree::myCountLeafBSTs(BST *pRoot)
{
    BST *pTemp = pRoot;

    static int iCount = 0;

    if(NULL == pRoot)
        return 0;

    if(pTemp -> pLChild == NULL && pTemp -> pRChild == NULL)
        iCount++;

    myCountLeafBSTs(pTemp -> pLChild);
    myCountLeafBSTs(pTemp -> pRChild);

    return iCount;
}

int Tree::CountLeafBSTs()
{
    return myCountLeafBSTs(pRoot);
}

int Tree::myCountNonLeafBSTs(BST *pRoot)
{
    BST *pTemp = pRoot;

    static int iCount = 0;

    if(NULL == pRoot)
        return 0;

    if(pTemp -> pLChild != NULL || pTemp -> pRChild != NULL)
        iCount++;

    myCountNonLeafBSTs(pTemp -> pLChild);
    myCountNonLeafBSTs(pTemp -> pRChild);

    return iCount;
}

int Tree::CountNonLeafBSTs()
{
    return myCountNonLeafBSTs(pRoot);
}

int Tree::myHeight(BST *pRoot)
{
    BST *pTemp = pRoot;

    int iLeftHeight;
    int iRightHeight;

    if(NULL == pRoot)
        return 0;

    iLeftHeight = myHeight(pTemp -> pLChild);
    iRightHeight = myHeight(pTemp -> pRChild);

    if(iLeftHeight > iRightHeight)
        return iLeftHeight + 1;
    else
        return iRightHeight + 1;
}

int Tree::Height()
{
    return myHeight(pRoot);
}

int Tree::mySmallestElement(BST *pRoot)
{
    BST *pTemp = pRoot;

    if(NULL == pRoot)
        return 0;

    while(pTemp -> pLChild != NULL)
        pTemp = pTemp -> pLChild;

    return pTemp->iData;
}

int Tree::SmallestElement()
{
    return mySmallestElement(pRoot);
}

int Tree::myLargestElement(BST *pRoot)
{
    BST *pTemp = pRoot;

    if(NULL == pTemp)
        return 0;

    while(pTemp -> pRChild != NULL)
        pTemp = pTemp -> pRChild;

    return pTemp->iData;
}

int Tree::LargestElement()
{
    return myLargestElement(pRoot);
}

bool Tree::mySearchBSTRecursive(BST *pRoot, int iKey)
{
    BST *pTemp = pRoot;

    if(NULL == pTemp)
        return false;

    if(iKey < pTemp -> iData)
        return mySearchBSTRecursive(pTemp -> pLChild , iKey);
    else if(iKey > pRoot -> iData)
        return mySearchBSTRecursive(pTemp -> pRChild , iKey);
    else                                                        // mhanjech data found zala
        return true;
}

bool Tree::SearchBSTRecursive(int iKey)
{
    return mySearchBSTRecursive(pRoot,iKey);
}

bool Tree::mySearchBSTNonRecursive(BST *pRoot, int iKey)
{
    BST *pTemp = pRoot;

    while(pTemp != NULL)
    {
        if(iKey < pTemp -> iData)
            pTemp = pTemp -> pLChild;
        else if(iKey > pTemp -> iData)
            pTemp = pTemp -> pRChild;
        else 
            return true;
    }

    return false;
}

bool Tree::SearchBSTNonRecursive(int iKey)
{
    return mySearchBSTNonRecursive(pRoot,iKey);
}

void Tree::InsertBST(int iNo)
{
    BST *pNewBST = NULL;
    BST *pPtr = NULL;
    BST *pParent = NULL;

    pPtr = pRoot;
    while(pPtr != NULL)
    {
        pParent = pPtr;
        if(iNo < pPtr -> iData)
            pPtr = pPtr -> pLChild;
        else if(iNo > pPtr -> iData)
            pPtr = pPtr -> pRChild;
        else
        {
            cout << "\nDuplicate data\n";
            return;
        }
    }

    // khali alyas pParent NULL ch ahe

    pNewBST = new BST;
    if(NULL == pNewBST)
    {
        cout << "Memory allocation FAILED\n";
        return;
    }

    pNewBST -> iData = iNo;
    pNewBST -> pLChild = pNewBST -> pRChild = NULL;

    if(NULL == pParent)
        pRoot = pNewBST;
    else if(iNo < pParent -> iData)
        pParent -> pLChild = pNewBST;
    else
        pParent -> pRChild = pNewBST;
}

void Tree::DeleteBST(int iKey)
{
    BST *pPtr = NULL;
    BST *pParent = NULL;
    BST *pSuccessor = NULL;
    BST *pChild = NULL;

    pPtr = pRoot;
    while(pPtr != NULL)
    {
        if(iKey == pPtr -> iData)
            break;

        pParent = pPtr;

        if(iKey < pPtr -> iData)
            pPtr = pPtr -> pLChild;
        else
            pPtr = pPtr -> pRChild;
    }

    // pParent is NULL if Data not Found at root

    if(pPtr -> pLChild != NULL && pPtr -> pRChild != NULL)      // both childs
    {
        pSuccessor = pPtr -> pRChild;
        pParent = pPtr;

        while(pSuccessor -> pLChild != NULL)
        {
            pParent = pSuccessor;
            pSuccessor = pSuccessor -> pLChild;
        }

        pPtr -> iData = pSuccessor -> iData;
        pPtr = pSuccessor;
    }

    if(pPtr -> pLChild != NULL)
        pChild = pPtr -> pLChild;
    else
        pChild = pPtr -> pRChild;

    if(NULL == pParent)
        pRoot = pChild;
    else if(iKey < pParent -> iData)
        pParent -> pLChild = pChild;
    else
        pParent -> pRChild = pChild;

    delete pPtr;
}
