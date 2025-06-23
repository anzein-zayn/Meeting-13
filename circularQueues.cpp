/**
 * @mainpage Documentation
 * 
 * @section Introduction
 * Project ini merupakan project struktur data
 * menggunakan struktur data queues dengan pendekatan circular arrays.abort
 * 
 * @section Operations
 * - en queues for insert elements into queues
 * - de queues for delete elements from queues
 * - show data / display data from queues
 * 
 * @section How to use
 * 1. Insert 
 * 2. Delete
 * 3. Display
 * 4. Exit
 * 
 * 
 * @author yProfil
 * - Nama    :Andy Zaky Zein 
 * - NIM     :20240140209
 * - Kelas   :TI E
 * 
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Gibran@umy.ac.id (c) 2025
 * 
 */
#include <iostream>
using namespace std;


/**
 * @class Queues
 * @brief This class is for operation queues
 * 
 */
class Queues 
{
private:
    int front;/// private variable for front of queues
    int rear;/// private variable rear for indicate the last element
    int max = 5;/// private variable max for maximum capasity of element
    int queue_array[5];/// private variable array of queues for store data

public:
/**
 * @brief Construct a new Queues object
 * set default queues null
 * with front = -1 and rear = -1
 */
    Queues(){
        front = -1;
        rear = -1;
    }

    /**
     * @brief method to insert data into queues
     * 
     */
    void insert (){
        int num;/// public variable num for saved data
        cout << "Enter a number : ";
        cin >> num;
        cout << endl;
        
        /// function to check if queue is underflow
        if ((front == 0 && rear == max-1) || (front == rear + 1))
        {
            cout << "\nQueue overflow\n";
            return;
        }

        ///if queue is empty then front and rear will be 0
        if (front == -1){
            front =0;
            rear = 0;
        }

        else{ ///if queue is not empty then rear will be increment by 1
            if (rear== max -1)
                rear = 0;
            else rear=rear+1;
        }
        queue_array[rear] = num;

}

/**
 * @brief method to delete data from queues
 * delete front element of the queues and adjust front index
 * 
 */
void remove()
{
    /// check if the queues is underflow
    if (front == -1){
        cout << "Queue underflow\n";
        return;
    }
    cout <<  "\nThe element deleted from the queue is : " << queue_array[front] << "\n";

    ///if only one element is present in the queue then front and rear will be -1
    if (front == rear){
        front = -1;
        rear = -1;///reset queues
    }
    else{/// repair front with circular
        if(front == max -1)
            front = 0;
        else
            front = front + 1;
    }
}

/**
 * @brief method to display the queue
 *print element from front to rear, if queues is empty, display message 
 * 
 */
void display(){
    int front_position = front ; /// public variable front is used to get the front position of the queue
    int rear_position = rear;/// public variable rear is used to get the rear position of the queue

    if(front == -1)///method to check if the queue is empty
    {
        cout << "Queue is empty\n";
        return;
    }

    cout << "\nElements in the queue are...\n";

    if (front_position <= rear_position)/// if front position is less than or equal to rear position then print from front to rear
    {
        while(front_position <= rear_position){
            cout << queue_array[front_position] << "  ";/// display the element
            front_position++;
        }
        cout<<endl;
    }
    else{/// display element from front to rear in circular manner
        while(front_position <= max - 1) {
            cout << queue_array[front_position] << "  ";/// display the element
            front_position++;
        }

        front_position = 0;/// set front position = 0

        while(front_position <=rear_position){
            cout << queue_array[front_position] << "  ";
            front_position++;
        }
        cout<<endl;
    }
}
};
/**
 * @brief main variable for running data queues
 * 
 * @return int 
 */
int main(){
    Queues q;/// create object from the class Queues
    char ch;///create a object ch with type data char 

    while(true)
    {/// 
    try
    {
        cout << "Menu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Implement delete operation" << endl;
        cout << "3. Display values" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4) : " ;
        cin >> ch ;
        cout << endl;

        switch(ch)///create 
        {
        case '1':
        {
            q.insert();
            break;
        }
        case '2':
        {
            q.remove();
            break;
        }
        case '3':
        {
            q.display();
            break;
        }
        case '4':
        {
            return 0;
        }

        }
    }
        catch (exception &e)
        {
            cout << "Check for the values entered." << endl;/// display the error message
        }
    }
}
