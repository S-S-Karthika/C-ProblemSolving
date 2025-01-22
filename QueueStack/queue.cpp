#include<iostream>
using namespace std;
#define SIZE 5 

class Queue
{
private:
   int arr[SIZE];
   int front , rear,size;
public:
    // constructor that have the same name as the class;
    Queue(){
        front = -1;   //start
        rear = -1;    //end
        size =0;
    }
    // to check the queue is empty or not
    bool isEmpty(){
        if(front==-1 || rear <front){
            return true;
        }
            return false;
    }

    // to check the queue is full or not 
    bool isFull(){
        if(rear == SIZE-1){
            return true;
        }
        return false;
    }
    //Enqueue operation
    void enqueue(int val){
        if( isFull() ){
            cout<< "queue is already full"<< endl;
        }else{
            if(front == -1){
                front=0;
            }
            rear++;
            arr[rear]=val;
            size++;
            cout<< "enqueue value is "<< arr[rear] <<endl;
        }
    }

    // Deueue operation

    void dequeue(){
        if(isEmpty()){
            cout<< "It is already empty we not able to delete"<< endl;
        }else{
            cout<<"dequeue element is "<< arr[front]<<endl;
            front++;
            size--;
        }
    }

    // find the top element 
    int isPeek(){
        if(isEmpty()){
            cout<<"queue is empty "<<endl;
             return -1;
        }
        return arr[front];
    }


    int getSize() const {
        return size;
    }

};



int main(){
    Queue q ;

    q.enqueue(19);
    q.enqueue(30);
    q.enqueue(20);
    q.enqueue(20);
    q.enqueue(20);
    q.enqueue(20);

    cout << "Front element :"<< q.isPeek()<<endl;

    q.dequeue();
    q.dequeue();
    
    q.dequeue();
    q.dequeue();
    
    q.dequeue();
    q.dequeue();

    cout << "Front element :"<< q.isPeek()<<endl;
    cout<< q.getSize() <<endl;


}