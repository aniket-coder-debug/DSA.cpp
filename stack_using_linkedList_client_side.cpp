#include"stack_using_linkedList_server_side.h"

int main(void)
{
    int iPoppedData;
    stack obj;

    obj.Push(10);
    obj.Push(20);
    obj.Push(30);

    obj.Display();                                           

    iPoppedData = obj.Pop();
    if(iPoppedData != -1)
        cout << "\n\nDeleted data is " << iPoppedData << endl;      

    obj.Display();                                           

    obj.DeleteAll();

    obj.Display();                                         

    return 0;
}

