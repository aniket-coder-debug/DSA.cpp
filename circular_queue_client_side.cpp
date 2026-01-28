#include"circular_queue_server_side.h"

int main(void)
{
    int iDelData;
    queue obj;

    obj.EnQueue(10);
    obj.EnQueue(20);
    obj.EnQueue(30);
    obj.EnQueue(40);

    obj.Display();              //  10 20 30 40

    iDelData = obj.DeQueue();
    if(iDelData != -1)
        cout << "\ndeleted data is " << iDelData << endl;       //  deleted data is 10

    obj.EnQueue(50);

    obj.Display();              //  20 30 40 50

    return 0;

}
