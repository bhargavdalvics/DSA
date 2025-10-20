//operations on queue
//1.enqueue
//2.dequeue
//3.isEmpty
//4.isFull
//5.front
//6.rear

//queue using array
//1.queue using single pointer
//2.using two pointers(front and rear)

//drawback of queue using array
//1.fixed size
//2.rear cannot be increased after reaching end even if there is space in front

//initially front=rear=-1
//1.enqueue-insert at rear
//2.dequeue-delete from front
//3.isEmpty- front==rear
//4.isFull- rear==size-1
//5.front-element at front+1
//6.rear-element at rear


//NOTE:to overcome drawback of queue using array
//1.reseting  pointers when queue becomes empty(reinitialize front and rear to -1 when queue is empty)
//2.circular queue- front and rear move in circular manner by using mod operation 
