#include<iostream>
#define MAX 25

using std :: cout;
using std :: endl;

class queue;
class node;
class Tree;
class BST
{
    BST *pLChild;
    int iData;
    BST *pRChild;

public:
    BST();
    ~BST();

    friend class Tree;
    friend class node;
};

class Tree
{
    BST *pRoot;
    
public:
    Tree();
    ~Tree();

private:
    void myPreorder(BST*);
    void myInorder(BST*);
    void myPostorder(BST*);
    void myLevelorder(BST*);
    void myDeleteAll(BST**);
    int myCountBSTsVersion1(BST*);
    int myCountBSTsVersion2(BST*);
    int myCountLeafBSTs(BST*);
    int myCountNonLeafBSTs(BST*);
    int myLargestElement(BST*);
    int mySmallestElement(BST*);
    int myHeight(BST*);

    bool mySearchBSTRecursive(BST*,int);
    bool mySearchBSTNonRecursive(BST*,int);

public:
    void Preorder();
    void Inorder();
    void Postorder();
    void Levelorder();

    void DeleteAll();
    int CountBSTsVersion1();
    int CountBSTsVersion2();
    int CountLeafBSTs();
    int CountNonLeafBSTs();
    int LargestElement();
    int SmallestElement();
    int Height();

    bool SearchBSTRecursive(int);
    bool SearchBSTNonRecursive(int);

    void InsertBST(int);
    void DeleteBST(int);
};



class node
{
    BST *iData;
    node *pNext;

public:
    node();
    ~node();

    friend class queue;
};

class queue
{
    node *pPtr;

public:
    queue();
    ~queue();

    void EnQueue(BST*);
    BST* DeQueue();
    bool IsQueueFull();
    bool IsQueueEmpty();
    int CountNodes();
};



