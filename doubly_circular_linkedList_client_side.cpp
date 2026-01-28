#include"doubly_circular_linkedList_server_side.h"

int main(void)
{
    int iNumber;
    list obj1;
    list obj2;

    obj1.Display();                                      // List is empty

    obj1.InsertFirst(30);
    obj1.InsertFirst(20);
    obj1.InsertFirst(10);

    obj1.Display();                                      // <-|10|-><-|20|-><-|30|->

    obj1.InsertLast(40);
    obj1.InsertLast(50);
    obj1.InsertLast(60);

    obj1.Display();                                      // <-|10|-><-|20|-><-|30|-><-|40|-><-|50|-><-|60|->

    obj1.InsertAtPosition(20 , 4);

    obj1.Display();                                      // <-|10|-><-|20|-><-|30|-><-|20|-><-|40|-><-|50|-><-|60|->

    iNumber = obj1.DeleteFirst();
    if(iNumber != -1)
        cout << "\n\nDeleted data is " << iNumber << endl;                // Deleted data is 10

    obj1.Display();                                      // <-|20|-><-|30|-><-|20|-><-|40|-><-|50|-><-|60|->

    iNumber = obj1.DeleteLast();
    if(iNumber != -1)
        cout << "\n\nDeleted data is " << iNumber << endl;                // Deleted data is 60

    obj1.Display();                                      // <-|20|-><-|30|-><-|20|-><-|40|-><-|50|->

    iNumber = obj1.DeleteAtPosition(2);
    if(iNumber != -1)
        cout << "\n\nDeleted data is " << iNumber << endl;                // Deleted data is 30

    obj1.Display();                                      //  <-|20|-><-|20|-><-|40|-><-|50|->

    iNumber = obj1.SearchFirstOccurrence(20);
    if(iNumber != 0)
        cout << "\n\nFirst Occurrence of 20 is at " << iNumber << "position" << endl;     // First Occurrence of 20 is at 1 position

    iNumber = obj1.SearchLastOccurrence(20);
    if(iNumber != 0)
        cout << "\n\nLast Occurrence of 20 is at " << iNumber << "position" << endl;      // Last Occurrence of 20 is at 2 position

    iNumber = obj1.SearchFirstOccurrence(20);
    if(iNumber != 0)
        cout <<"\n\n20 Found " << iNumber << "times" << endl;              // 20 Found 1 times

    obj1.Display();                                      //  <-|20|-><-|20|-><-|40|-><-|50|->
    iNumber = obj1.CountNodes();
    cout << "\n\nTotal node count is " << iNumber << endl;                 // Total node count is 4

    obj1.PhysicalReverse();
    obj1.Display();                                      // <-|50|-><-|40|-><-|20|-><-|20|->
    obj1.PhysicalReverse();
    obj1.Display();                                      // <-|20|-><-|20|-><-|40|-><-|50|->
    obj1.ReverseDisplay();                               // <-|50|-><-|40|-><-|20|-><-|20|->
    obj1.Display();                                      // <-|20|-><-|20|-><-|40|-><-|50|->

    obj2.InsertLast(100);
    obj2.InsertLast(200);
    obj2.InsertLast(300);
    obj1.Display();                                      // <-|20|-><-|20|-><-|40|-><-|50|->
    obj2.Display();                                      // <-|100|-><-|200|-><-|300|->
    obj1.ConcatLists(obj2);
    obj1.Display();                                      // <-|20|-><-|20|-><-|40|-><-|50|-><-|100|-><-|200|-><-|300|->
    obj2.Display();                                      // List is empty
    
    obj2.InsertLast(400);
    obj2.InsertLast(500);
    obj2.InsertLast(600);
    obj1.Display();                                      // <-|20|-><-|20|-><-|40|-><-|50|-><-|100|-><-|200|-><-|300|->
    obj2.Display();                                      // <-|400|-><-|500|-><-|600|->
    obj1.ConcatAtPosition(obj2 , 3);
    obj1.Display();                                      // <-|20|-><-|20|-><-|400|-><-|500|-><-|600|-><-|40|-><-|50|-><-|100|-><-|200|-><-|300|->
    obj2.Display();                                      // List is empty

    return 0;
}

