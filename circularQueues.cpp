#include <iostream>
using namespace std;

class Queues 
{
    int front, rear, max = 5;
    int queue_array[5];

public:
    Queues(){
        front = -1;
        rear = -1;
    }

    void insert (){
        int num;
        cout << "Enter a number : ";
        cin >> num;
        cout << endl;
        
        if ((front == 0 && rear == max-1) || (front == rear + 1))
        {
            cout << "\nQueue overflow\n";
            return;
        }

        if (front == -1){
            front =0;
            rear = 0;
        }

        else{
            if (rear== max -1)
                rear = 0;
            else rear=rear+1;
        }
        queue_array[rear] = num;

}

void remove()
{
    if (front == -1){
        cout << "Queue underflow\n";
        return;
    }
    cout <<  "\nThe element deleted from the queue is : " << queue_array[front] << "\n";

    if (front == rear){
        front = -1;
        rear = -1;
    }
    else{
        if(front == max -1)
            front = 0;
        else
            front = front + 1;
    }
}