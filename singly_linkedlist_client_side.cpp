#include"singly_linkedlist_server_side.h"

int main(void)
{
    int iDelData;

    List lst;
    List lst1;

    lst.InsertFirst(20);
    lst.InsertFirst(10);

    lst.Display();                      //  |10|->|20|->

    lst.InsertLast(30);
    lst.InsertLast(40);

    lst.Display();                      //  |10|->|20|->|30|->|40|->

    lst.InsertAtPosition(60,3);
    lst.Display();                      //  |10|->|20|->|60|->|30|->|40|->
    lst.InsertAtPosition(40,2);
    lst.Display();                      //  |10|->|40|->|20|->|60|->|30|->|40|->

    iDelData = lst.DeleteFirst();
    if(iDelData != -1)
        cout << "\n\nDeleted data is\t" << iDelData << endl;    //  Deleted data is 10
    lst.Display();                                              //  |40|->|20|->|60|->|30|->|40|->

    iDelData = lst.DeleteLast();
    if(iDelData != -1)
        cout << "\n\nDeleted data is\t" << iDelData << endl;    //  Deleted data is 40
    lst.Display();                                              //  |40|->|20|->|60|->|30|->

    iDelData = lst.DeleteAtPosition(2);
    if(iDelData != -1)
        cout << "\n\nDeleted data is\t" << iDelData << endl;    //  Deleted data is 20
    lst.Display();                                              //  |40|->|60|->|30|->

    iDelData = lst.CountNodes();
    cout << "\n\nTotal node count is " << iDelData << endl;     // Total node count is 3

    iDelData = lst.SearchFirstOccurrence(40);
    if(iDelData != 0)
        cout << "\nFirst Occurrence of 40 is at " << iDelData << " position" << endl;   //  First Occurrence of 40 is at 1 position

    iDelData = lst.SearchLastOccurrence(60);
    if(iDelData != 0)
        cout << "\nLast Occurrence of 60 is at " << iDelData << " position" << endl;    //  Last Occurrence of 60 is at 2 position

    iDelData = lst.SearchAllOccurrences(30);
    if(iDelData != 0)
        cout << "\n30 found " << iDelData << " times\n";                                //  30 found 1 times

    lst.PhysicalReverse();
    lst.Display();                      //  |30|->|60|->|40|->
    lst.PhysicalReverse();
    lst.Display();                      //  |40|->|60|->|30|->
    lst.ReverseDisplay();               //  |30|->|60|->|40|->
    lst.Display();                      //  |40|->|60|->|30|->

    lst1.InsertLast(100);
    lst1.InsertLast(200);
    lst1.InsertLast(300);
    lst1.Display();                     //  |100|->|200|->|300|->
    lst.Display();                      //  |40|->|60|->|30|->

    lst.ConcatLists(lst1);
    lst.Display();                      //  |40|->|60|->|30|->|100|->|200|->|300|->
    lst1.Display();                     //  List is empty

    lst1.InsertLast(400);
    lst1.InsertLast(500);
    lst.Display();                      //  |40|->|60|->|30|->|100|->|200|->|300|->
    lst1.Display();                     //  |400|->|500|->
    lst.ConcatAtPosition(lst1 , 2);
    lst.Display();                      //  |40|->|400|->|500|->|60|->|30|->|100|->|200|->|300|->
    lst1.Display();                     //  List is empty

    lst.DeleteAll();
    lst.Display();                      //  List is empty

    return 0;
}

