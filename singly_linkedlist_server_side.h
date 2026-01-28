#include <iostream>
using std :: cout;
using std :: endl;

class List;
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

    friend class List;
};

class List
{
    node *pFirst;

public:
    List()
    {
        pFirst = NULL;
    }
    ~List()
    {
        if(pFirst != NULL)
        {
            DeleteAll();
            pFirst = NULL;
        }
    }

    void InsertFirst(int iNo)
    {
        node *pNewNode = NULL;

        pNewNode = new node;
        if(NULL == pNewNode)
        {
            cout << "\nMemory allocation FAILED\n";
            return;
        }

        pNewNode -> iData = iNo;

        if(NULL == pFirst)                  // list jr Empty asel tr
            pNewNode -> pNext = NULL;       // new node chya next madhe NULL jato
        else                                // nahitr
            pNewNode -> pNext = pFirst;     // new node chya next madhe junya pahilyacha address jato ani ha pahila hoto

        pFirst = pNewNode;                  // pFirst madhe new node cha address jato
    }

    void InsertLast(int iNo)
    {
        node *pNewNode = NULL;
        node *pTemp = NULL;

        pNewNode = new node;
        if(NULL == pNewNode)
        {
            cout << "\nMemory allocation FAILED\n";
            return;
        }

        pNewNode -> iData = iNo;
        pNewNode -> pNext = NULL;           // ha kadhipn NULL ch asnar

        if(NULL == pFirst)                  // list jr empty asel tr
        {
            pFirst = pNewNode;              // new node cha address pFirst madhe janar
            return;
        }

        pTemp = pFirst;                     // pointing to First node
        while(pTemp -> pNext != NULL)       // pTemp tuzya next madhe jo paryant NULL yet ny to paryant
            pTemp = pTemp -> pNext;

        pTemp -> pNext = pNewNode;          // last node chya next madhe new node cha address janar
    }

    int DeleteFirst()
    {
        int iDelData;
        node *pTemp = NULL;

        if(NULL == pFirst)
            return -1;

        pTemp = pFirst;                     // pointing to first node
        pFirst = pTemp -> pNext;            // second node cha address pFirst madhe

        iDelData = pTemp -> iData;
        pTemp -> pNext = NULL;              // 1st node chya next madhe NULL
        delete pTemp;

        return iDelData;
    }

    int DeleteLast()
    {
        int iDelData;
        node *pTemp = NULL;

        if(NULL == pFirst)
            return -1;

        pTemp = pFirst;

        if(NULL == pTemp -> pNext)                              // one node asel tr
        {
            iDelData = pTemp -> iData;
            delete pTemp;
            pFirst = NULL;
        }
        else
        {
            while(pTemp -> pNext -> pNext != NULL)              // pTemp 2nd last node la thambto
                pTemp = pTemp -> pNext;

            iDelData = pTemp -> pNext -> iData;
            delete pTemp -> pNext;                              // 2nd last node la thambun ch tyala free karto
            pTemp -> pNext = NULL;
        }

        return iDelData;
    }

    void Display()
    {
        node *pHead = pFirst;

        if(NULL == pHead)
        {
            cout << "\n\nList is empty\n";
            return ;
        }

        cout << "\n\nList is :\t";

        while(pHead != NULL)
        {
            cout << "|" << pHead -> iData << "|->";
            pHead = pHead -> pNext;
        }
    }

    int CountNodes()
    {
        node *pHead = pFirst;

        int iCount = 0;

        while(pHead != NULL)
        {
            iCount++;
            pHead = pHead -> pNext;
        }

        return iCount;
    }

    int SearchFirstOccurrence(int iKey)
    {
        node *pHead = pFirst;

        int iPos = 0;

        while(pHead != NULL)
        {
            iPos++;

            if(pHead -> iData == iKey)
                return iPos;

            pHead = pHead -> pNext;
        }

        return 0;           //  If List is empty or Data Not Found
    }

    int SearchLastOccurrence(int iKey)
    {
        node *pHead = pFirst;

        int iPos = 0;
        int iLastPos = 0;

        while(pHead != NULL)
        {
            iPos ++;

            if(pHead -> iData == iKey)
                iLastPos = iPos;

            pHead = pHead -> pNext;
        }

        return iLastPos;        // data jr ny sapdla ani list jr empty asel tr 0 return karto
    }

    int SearchAllOccurrences(int iKey)
    {
        node *pHead = pFirst;
        
        int iPos = 0;

        while(pHead != NULL)
        {
            if(pHead -> iData == iKey)
                iPos ++;

            pHead = pHead -> pNext;
        }

        return iPos;            // data jr ny sapdla ani list jr empty asel tr 0 return karto
    }

    void InsertAtPosition(int iNo , int iPos)
    {
        int iCount;
        node *pNewNode = NULL;
        node *pTemp = NULL;

        iCount = CountNodes();

        if(iPos <= 0 || iPos > iCount + 1)
        {
            cout << "\nPosition is Invalid\n";
            return;
        }

        if(1 == iPos)            
        {
            InsertFirst(iNo);
            return;
        }

    /*    if(iPos == iCount + 1)       
        {
            InsertLast(iNo);
            return ;
        }
    */

    // khali yety mhanje 2 node chi teri list ahe

        pNewNode = new node;
        if(NULL == pNewNode)
        {
            cout << "\nMemory allocation FAILED\n";
            return ;
        }

        pNewNode -> iData = iNo;

        pTemp = pFirst;
        iCount = 1;
        while(iCount < iPos - 1)                // ji position deli tyachya adhichya node la jaun thambaych
        {
            iCount ++;
            pTemp = pTemp -> pNext;
        }

        pNewNode -> pNext = pTemp -> pNext;     // new node chya next madhe ptemp chya next cha address
        pTemp -> pNext = pNewNode;              // pTemp chya next madhe new node cha address
    }

    int DeleteAtPosition(int iPos)
    {
        int iCount;
        node *pTemp1 = NULL;
        node *pTemp2 = NULL;

        iCount = CountNodes();

        if(iPos <= 0 || iPos > iCount)
        {
            cout << "\nPosition is Invalid\n";
            return -1;
        }

        if(1 == iPos)                       // 1st node delete karaychya asel tr
            return DeleteFirst();

    //    if(iPos == iCount)
    //        return DeleteLast(ppHead);

        pTemp1 = pFirst;                    // pointing to first node
        iCount = 1;
        while(iCount < iPos - 1)            // position chya adhichya node la jaun thambto
        {
            iCount++;
            pTemp1 = pTemp1 -> pNext;
        }

        pTemp2 = pTemp1 -> pNext;           // pointing to deleting node

        pTemp1 -> pNext = pTemp2 -> pNext;  // jo node delete hoylay tyachya adhichya node chya next madhe tyachya pudhchyacha address taktoy
        iCount = pTemp2 -> iData;

        delete pTemp2;

        return iCount;
    }

    void ConcatLists(List &refObj)
    {
        node *pTemp = NULL;

        if(NULL == refObj.pFirst)             // scenerio 1 & 2
            return;

        // khali alay mhanje second list ahe

        if(NULL == pFirst)              // scenerio 3
        {
            pFirst = refObj.pFirst;           // dusrila pahil banvl
            refObj.pFirst = NULL;             // 2nd list empty
            return;
        }

        // khali alay mhanje donhi lists ahet
        // scenerio 4

        pTemp = pFirst;                 // pointing to first node
        while(pTemp -> pNext != NULL)   // jo paryant tuzya next madhe NULL yet ny
            pTemp = pTemp -> pNext;

        pTemp -> pNext = refObj.pFirst;       // 1st list chya last node chya next madhe 2nd list chya 1st node cha address
        refObj.pFirst = NULL;                 // 2nd list empty
    }

    void ReverseDisplay()
    {
        node *pHead = pFirst;

        if(NULL == pHead)
        {
            cout << "\nList is empty\n";
            return;
        }

        PhysicalReverse();
        Display();
        PhysicalReverse();
    }

    void PhysicalReverse()
    {
        node *pNext = NULL;
        node *pCurrent = pFirst;
        node *pPrev = NULL;

        while(pCurrent != NULL)             // pCurrent madhe jo paryant NULL jat nay
        {
            pNext = pCurrent -> pNext;      // pCurrent chya pudhchya node la pNext set kela
            pCurrent -> pNext = pPrev;      // pCurrent chya next madhe tyachya magchyacha address takla
            pPrev = pCurrent;               // pPrev pCurrent chya jagi anla
            pCurrent = pNext;               // pCurreant pNext chya jagi nela
        }

        pFirst = pPrev;   // last la jevha pCurrent madhe NULL jaun loop chya baher yenar tevha prev ha last node la asnar manun tyacha address pFirst madhe
    }

    void DeleteAll()
    {
        struct node *pTemp = NULL;

        while(pFirst != NULL)
        {
        pTemp = pFirst;
        pFirst = pTemp -> pNext;
        delete pTemp;
        }
    }

    void ConcatAtPosition(List &refobj , int iPos)
    {
        int iCount;
        node *pTemp1 = NULL;
        node *pTemp2 = NULL;


        iCount = CountNodes();

        if(iPos <= 0 || iPos > iCount + 1)
        {
            cout << "\nPosition is Invalid\n";
            return;
        }

    // we dont know 2nd list is present or not
    // we dont know 1st list is present or not
    // we surely know if 1st list empty then iPos == 1

        if(NULL == refobj.pFirst)
            return;

    // surely 2nd list is present
    // we dont know 1st list is present or not
    // we surely know if 1st list empty then iPos == 1

        if(1 == iPos)
        {
            ConcatLists(refobj);                      // dusri list philya list la jodun ali
            pFirst = refobj.pFirst;                   // 2nd become 1st
            refobj.pFirst = NULL;                     // 2nd become empty
            return;
        }

    // surely both list are present

        pTemp1 = pFirst;
        iCount = 1;
        while(iCount < iPos - 1)
        {
            iCount ++;
            pTemp1 = pTemp1 -> pNext;
        }

        pTemp2 = refobj.pFirst;
        while(pTemp2 -> pNext != NULL)
            pTemp2 = pTemp2 -> pNext;

        pTemp2 -> pNext = pTemp1 -> pNext;
        pTemp1 -> pNext = refobj.pFirst;

        refobj.pFirst = NULL;
    }
};

