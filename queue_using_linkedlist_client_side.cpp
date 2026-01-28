#include"queue_using_linkedlist_server_side.h"

int main(void)
{
    int iDeldata;
    queue obj;

    obj.EnQueue(10);
    obj.EnQueue(20);
    obj.EnQueue(30);

    obj.Display();

    iDeldata = obj.DeQueue();
    if(iDeldata != -1)
        cout << "\nDeleted data is " << iDeldata << endl;

    obj.Display();

    obj.DeleteAll();
    obj.Display();

    return 0;
}

