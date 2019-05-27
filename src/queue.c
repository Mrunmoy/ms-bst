/**
 *  @file queue.c
 *  @author championsurfer3044
 *  @date 27 May 2019 
 *  @brief 
 *
 *  LICENSE:-
 *  The MIT License (MIT)
 *  Copyright (c) 2019 Mrunmoy Samal
 *
 *  Permission is hereby granted, free of charge, to any person
 *  obtaining a copy of this software and associated documentation
 *  files (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use,
 *  copy, modify, merge, publish, distribute, sublicense, and/or
 *  sell copies of the Software, and to permit persons to whom
 *  the Software is furnished to do so, subject to the following
 *  conditions:
 *
 *  The above copyright notice and this permission notice shall
 *  be included in all copies or substantial portions of the
 *  Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 *  OR OTHER DEALINGS IN THE SOFTWARE.
 */


/*
*----------------------------------------------------------------------
*   Include Files
*----------------------------------------------------------------------
*/
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "bst.h"
#include "queue.h"
#include "debug.h"

/*
*----------------------------------------------------------------------
*   Private Defines
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Macros
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Data Types
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Public Variables
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Variables (static)
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Public Constants (const)
*----------------------------------------------------------------------
*/


/*
*----------------------------------------------------------------------
*   Private Constants (static)
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Function Prototypes (static)
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Externs
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Functions Definitions
*----------------------------------------------------------------------
*/



/*
*----------------------------------------------------------------------
*   Exported Functions Definitions
*----------------------------------------------------------------------
*/
/** Initialize your data structure here. Set the size of the queue to be k. */
mcq_t * CreateQueue(int k) {
  mcq_t *obj = (mcq_t *)malloc (sizeof(mcq_t));
  assert(obj);
  obj->data = (treeNodePtr_t *)calloc(k, sizeof(treeNodePtr_t));
  assert(obj->data);

  obj->head = -1;
  obj->tail = -1;
  obj->size = k;
}

void DestroyQueue(mcq_t *q) {
  if (!q) return;
  free(q->data);
  free(q);
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool EnQueue(mcq_t *q, treeNode_t *value) {
  if (!q || IsFull(q)) {
    return false;
  }

  if (IsEmpty(q)) {
    q->head = 0;
  }
  q->tail = (q->tail + 1) % q->size;
  q->data[q->tail] = value;
  return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool DeQueue(mcq_t *q) {
  if (IsEmpty(q)) {
    return false;
  }
  if (q->head == q->tail) {
    q->head = -1;
    q->tail = -1;
    return true;
  }
  q->head = (q->head + 1) % q->size;
  return true;
}

/** Get the front item from the queue. */
treeNode_t * Front(mcq_t *q) {
  if (IsEmpty(q)) {
    return NULL;
  }
  return q->data[q->head];
}

/** Get the last item from the queue. */
treeNode_t * Rear(mcq_t *q) {
  if (IsEmpty(q)) {
    return NULL;
  }
  return q->data[q->tail];
}

/** Checks whether the circular queue is empty or not. */
bool IsEmpty(mcq_t *q) {
  return q->head == -1;
}

/** Checks whether the circular queue is full or not. */
bool IsFull(mcq_t *q) {
  return ((q->tail + 1) % q->size) == q->head;
}


