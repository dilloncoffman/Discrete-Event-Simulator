#include "Queues.h"

/*
 Creates, allocates memory for and returns a Queue
*/
Queue initializeQueue(int capacity) {
	Queue *newQueue = malloc(sizeof(Queue));
	newQueue->capacity = capacity;
	newQueue->currentSize = 0;
	newQueue->front = 0; // points to first index in queue
	newQueue->rear = capacity - 1;
	newQueue->eventList = malloc(sizeof(Event) * newQueue->capacity);
	return *newQueue;
}

/*
 Prints the count, length and elements of a vector to
 screen.
 */
void printQueue(Queue q) {
    if (q.eventList == NULL) {
        printf("No queue to print!\n");
        exit(5);
    }
    int i = 0;
	printf("\n\nTESTING PRINT \n");
    printf("\ncapacity =  %d", q.capacity);
    printf("\ncurrent size = %d", q.currentSize);
    for (i = 0; i < q.currentSize; i++) {
		// print event structs (the jobSequenceNumber)
        printf("\nhere it is: %d", q.eventList[q.front].eventType);
    }
    printf("\n");
}

/*
 Frees the memory allocated for the queue, and sets the members to 0
 */
void destroy(Queue *q) {
	if (q->eventList == NULL) {
		printf("No queue to free!\n");
		exit(1);
	}
	//set currentSize and capacity to 0
    q->currentSize = 0;
    q->capacity = 0;
    free(q->eventList); //free queue
}

Event create_event(int eventType, int jobSequenceNumber, int time) { //in reality may have to pass in eventType, time, and jobSequenceNumber here
	Event newEvent;
	newEvent.event = malloc(sizeof(Event));
	newEvent.eventType = eventType; // 1 for job arrives at Event queue
	newEvent.jobSequenceNumber = jobSequenceNumber; // it's the first job
	newEvent.time = time; // the time randomly computed for entering the event queue
	return newEvent;
}

/*
 Checks if the Queue q is empty, returns 1 if true and 0 if it's not
 */
int isEmpty(Queue *q) {
	if(q->eventList == NULL) {
		printf("No queue to check if empty.\n");
		exit(1);
	}
	return q->currentSize == 0;
}

/*
 Checks if the Queue q is full, returns 1 if true and 0 if it's not
 */
int isFull(Queue *q) {
	return q->currentSize == q->capacity;
}

/*
 Pushes new event onto queue
 */
void push(Queue *q, Event e) {
	if (isFull(q)) return; // if the queue is full, return
	q->rear = (q->rear + 1);
	q->eventList[q->rear] = e;
	q->currentSize += 1; // increment size of queue by 1, since event successfully pushed to queue
	printf("\nPushed event to queue successfully.");
}

Event pop(Queue *q) {
	if (isEmpty(q)) return create_event(0, 0, 0); // if the queue is empty, nothing to pop, return an empty event
	Event e = q->eventList[q->front];
	q->front = (q->front + 1);
	q->currentSize -= 1; // decrement the size of the queue since you've popped off an item
	printf("\nPopped from queue successfully.");
	return e;
}

// int push(Queue *q, Event *e) {
// 	if(!isEmpty(q)) {
// 		// NOTICE THAT ONLY LINES 30, 33, and 34 are the errors!
// 		q->rear->next = e->event;
// 		q->rear = e->event;
// 		return 1;
// 	} else {
// 		q->front = e->event;
// 		q->rear = e->event;
// 		return 1;
// 	}

// 	return
// }
// int push(Queue *q, Event *e) {
// 	// if queue's capacity is 0, initialize its size
// 	if (q->capacity == 0) { 
//         q->capacity = INIT_SIZE;
//     }

//     if (q->currentSize == q->capacity) { //if the current size is equal to the capacity, dynamically reallocate space by doubling capacity
//         q->capacity *= 2;
//         int *temp = (int*) malloc(sizeof(e) * q->capacity); //reallocate double the space
//         if (temp == NULL) {
//             printf("Error reallocating!\n");
//             exit(0); // error reallocating space
//         }
//         int i = 0;
//         for (i = 0; i < q->capacity; i++) {
//             temp[i] =  (&q->queue[i]); //put event to be inserted into reallocated queue, and should copy over already allocated events
//         }
//         double *temp2 = q->queue; //temp copy address into other pointer
//         q->queue = temp;
//         free(temp2); //free old vector;
//     }
//     (int*)q->queue[q->currentSize] = &e; //if there's enough space, just insert the event
//     (q->currentSize)++; // increment currentSize since an event has been inserted
//     return 1;
// }