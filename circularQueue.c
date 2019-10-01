typedef int ElemType;
typedef struct {
    ElemType *data;
    int front;
    int rear;
    int size;
} MyCircularQueue;
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);
/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *Q;
    Q = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    Q->data = (ElemType *)malloc(k*sizeof(ElemType));
    Q->front = -1;
    Q->rear = -1;
    Q->size = k;
    return Q;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;
    if (myCircularQueueIsEmpty(obj))
    {
        obj->front = 0;
        obj->rear = 0;
        obj->data[obj->rear] = value;
        return true;
    }
    obj->rear = (obj->rear + 1)%obj->size;
    obj->data[obj->rear] = value;
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;
    if (obj->front == obj->rear)
    {
        obj->front = -1;
        obj->rear = -1;
        return true;
    }
    obj->front = (obj->front + 1)%obj->size;
    return true;
    
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->data[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->data[obj->rear];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {

    if (obj->front == -1 && obj->rear == -1)
        return true;
    else
        return false;


  
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
  
    if (obj->front < obj->rear)
    {
        if ((obj->rear - obj->front + 1) != obj->size) 
            return false;
        else
            return true;
    }
    else if (obj->front > obj->rear)
    {
        if (obj->front - obj->rear == 1)
            return true;
        else
            return false;
    }
    
    else
        return false;

}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
