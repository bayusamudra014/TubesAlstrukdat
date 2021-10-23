#ifndef H_QUEUE
#define H_QUEUE

#include "../order/order.h"
#include "../boolean.h"

#define Q_SIZE 35

typedef Order QEltype;

typedef struct queue{
  QEltype buffer[Q_SIZE];
  int idxHead;
	int idxTail;
} Queue;

void q_create_queue(Queue* q);

boolean q_is_empty(Queue q);
boolean q_is_full(Queue q);

int q_length(Queue q);

void q_enqueue(Queue* q, QEltype item);
void q_dequeue(Queue* q, QEltype* item);

QEltype q_get_head(Queue q);
QEltype q_get_tail(Queue q);

#endif