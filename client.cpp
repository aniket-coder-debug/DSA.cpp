#include "server.h"

int main(void)
{
    Tree obj1;
    bool bRet;

    obj1.InsertBST(100);
    obj1.InsertBST(150);
    obj1.InsertBST(90);
    obj1.InsertBST(120);
    obj1.InsertBST(80);
    obj1.InsertBST(50);
    obj1.InsertBST(140);
    obj1.InsertBST(160);

    obj1.Preorder();                                                            // 100 90 80 50 150 120 140 160
    cout << "\n\n";
    obj1.Inorder();                                                             // 50 80 90 100 120 140 150 160
    cout << "\n\n";
    obj1.Postorder();                                                           // 50 80 90 140 120 160 150 100
    cout << "\n\n";
    obj1.Levelorder();                                                          // 100 90 150 80 120 160 50 140
    cout << "\n\n";

    cout << "\nBST count is " << obj1.CountBSTsVersion1() << endl;              // 8
    cout << "\nBST count is " << obj1.CountBSTsVersion2() << endl;              // 8
    cout << "\nLeaf BST count is " << obj1.CountLeafBSTs() << endl;             // 3
    cout << "\nNonLeaf BST count is " << obj1.CountNonLeafBSTs() << endl;       // 5
    cout << "\nHeight of tree is " << obj1.Height() << endl;                    // 4
    cout << "\nSmallest element is " << obj1.SmallestElement() << endl;         // 50
    cout << "\nLargest element is " << obj1.LargestElement() << endl;           // 160

    bRet = obj1.SearchBSTRecursive(80);
    if(bRet == true)
        cout << "\nData Found\n";                                               // Data Found
    else 
        cout << "\nData Not Found\n";

    bRet = obj1.SearchBSTNonRecursive(120);
    if(bRet == true)
        cout << "\nData found\n\n";                                             // Data Found
    else 
        cout << "\nData Not Found\n\n";

    obj1.DeleteBST(50);                                                         // no childs
    obj1.Levelorder();                                                          // 100 90 150 80 120 160 140
    cout << "\n\n";

    obj1.DeleteBST(90);                                                         // single child
    obj1.Levelorder();                                                          // 100 80 150 120 160 140
    cout << "\n\n";

    obj1.DeleteBST(100);                                                        // both childs
    obj1.Levelorder();                                                          // 120 80 150 140 160
    cout << "\n\n";

    return 0;
}
