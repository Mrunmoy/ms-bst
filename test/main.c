/**
 *  @file test.c
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
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "bst.h"
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
typedef struct testInput_t {
  bst_t *bst;
  int *array;
  int size;
  int min;
  int max;
  int *preorder;
  int *postorder;
  int *inorder;
  int *breadthFirst;
}testInput_t;

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

bool operateOnInput(testInput_t *tstInp, int tc) {
  if ( !tstInp || !tstInp->bst ) return false;

  bool result = true;
  do
  {
    // insert test, hasItem test
    for (int i = 0; i < tstInp->size; i++) {
      if (!insertTreeNode(tstInp->bst, tstInp->array[i])) {
        result =  false;
        break;
      }
      if (!hasItem(tstInp->bst, tstInp->array[i])) {
        result = false;
        break;
      }
    }

    // preorder, postOrder, inOrder, breadthfirst tests
    int *r = preOrder(tstInp->bst);
    assert(r);
    for (int i = 0;i < tstInp->bst->count; i++) {
      if (r[i] != tstInp->preorder[i]) {
        result = false;
        free(r);
        break;
      }
    }
    free(r);

    r = postOrder(tstInp->bst);
    assert(r);
    for (int i = 0;i < tstInp->bst->count; i++) {
      if (r[i] != tstInp->postorder[i]) {
        result = false;
        free(r);
        break;
      }
    }
    free(r);

    r = inOrder(tstInp->bst);
    assert(r);
    for (int i = 0;i < tstInp->bst->count; i++) {
      if (r[i] != tstInp->inorder[i]) {
        result = false;
        free(r);
        break;
      }
    }
    free(r);

    r = breadthFirst(tstInp->bst);
    assert(r);
    for (int i = 0;i < tstInp->bst->count; i++) {
      if (r[i] != tstInp->breadthFirst[i]) {
        result = false;
        free(r);
        break;
      }
    }
    free(r);

    // remove then check for existence
    for (int i = 0; i < tstInp->size; i++) {
      if (!removeItem(tstInp->bst, tstInp->array[i])) {
        result = false;
        break;
      }
      if (hasItem(tstInp->bst, tstInp->array[i])) {
        result = false;
        break;
      }
    }
  } while(0);

  destroyBST(tstInp->bst);

  printf("Test case %d %s\n", tc, result? "passed": "failed");

  return result;
}

int main(void) {

  int a0[] = { 1 };
  int a0_pre[] = { 1 };
  int a0_post[] = { 1 };
  int a0_in[] = { 1 };
  int a0_bfs[] = { 1 };

  int a11[] = { 1, 2 };
  int a11_pre[] = { 1, 2 };
  int a11_post[] = { 2, 1 };
  int a11_in[] = { 1, 2 };
  int a11_bfs[] = { 1, 2 };

  int a12[] = { 2, 1 };
  int a12_pre[] = { 2, 1 };
  int a12_post[] = { 1, 2 };
  int a12_in[] = { 1, 2 };
  int a12_bfs[] = { 2, 1 };

  int a21[] = { 1, 2, 3 };
  int a21_pre[] = { 1, 2, 3 };
  int a21_post[] = { 3, 2, 1 };
  int a21_in[] = { 1, 2, 2 };
  int a21_bfs[] = { 1, 2, 3 };

  int a22[] = { 3, 2, 1 };
  int a22_pre[] = { 3, 1, 2 };
  int a22_post[] = { 1, 2, 3 };
  int a22_in[] = { 1, 2, 2 };
  int a22_bfs[] = {3, 2, 1};

  int a23[] = { 3, 1, 2 };
  int a23_pre[] = { 3, 1, 2 };
  int a23_post[] = { 2, 1, 3 };
  int a23_in[] = { 1, 2, 3 };
  int a23_bfs[] = { 3, 1, 2 };

  int a24[] = { 2, 1, 3 };
  int a24_pre[] = { 2, 1, 4};
  int a24_post[] = { 1, 3, 2 };
  int a24_in[] = { 1, 2, 3 };
  int a24_bfs[] = { 2, 1, 3 };

  int a3[] = { 31, 2, 3 };
  int a3_pre[] = { 31, 2, 3 };
  int a3_post[] = { 3, 2, 31 };
  int a3_in[] = { 2, 3, 31 };
  int a3_bfs[] = { 31, 2, 3 };

  int a4[] = { 11, 2, 23, 14, 5 };
  int a4_pre[] = { 11, 2, 5, 23, 14 };
  int a4_post[] = { 5, 2, 14,  23, 11 };
  int a4_in[] = { 2, 5, 11, 14, 23 };
  int a4_bfs[] = { 11,  2, 23, 5, 14 };

  int a5[] = { 21, 12, 13, 4, 15, 16 };
  int a5_pre[] = { 21, 12, 4, 13, 15, 16 };
  int a5_post[] = { 4, 16, 15, 13, 12, 21 };
  int a5_in[] = { 4, 12, 13, 15, 16, 21 };
  int a5_bfs[] = { 21, 12, 4, 13, 15, 26 };

  testInput_t t0 = {
    .bst = createNewBST(),
    .array = a0,
    .size = sizeof (a0)/sizeof(a0[0]),
    .min = 1,
    .max = 1,
    .preorder     = a0_pre,
    .postorder    = a0_post,
    .inorder      = a0_in,
    .breadthFirst = a0_bfs
  };

  Trace();

  testInput_t t1 = {
    .bst = createNewBST(),
    .array = a11,
    .size = sizeof (a11)/sizeof(a11[0]),
    .min = 1,
    .max = 2,
    .preorder     = a11_pre,
    .postorder    = a11_post,
    .inorder      = a11_in,
    .breadthFirst = a11_bfs
  };

  testInput_t t2 = {
    .bst = createNewBST(),
    .array = a12,
    .size = sizeof (a12)/sizeof(a12[0]),
    .min = 1,
    .max = 2,
    .preorder     = a12_pre,
    .postorder    = a12_post,
    .inorder      = a12_in,
    .breadthFirst = a12_bfs
  };

  testInput_t t3 = {
    .bst = createNewBST(),
    .array = a21,
    .size = sizeof (a21)/sizeof(a21[0]),
    .min = 1,
    .max = 3,
    .preorder     = a21_pre,
    .postorder    = a21_post,
    .inorder      = a21_in,
    .breadthFirst = a21_bfs
  };

  testInput_t t4 = {
    .bst = createNewBST(),
    .array = a22,
    .size = sizeof (a22)/sizeof(a22[0]),
    .min = 1,
    .max = 3,
    .preorder     = a22_pre,
    .postorder    = a22_post,
    .inorder      = a22_in,
    .breadthFirst = a22_bfs
  };

  testInput_t t5 = {
    .bst = createNewBST(),
    .array = a23,
    .size = sizeof (a23)/sizeof(a23[0]),
    .min = 1,
    .max = 3,
    .preorder     = a23_pre,
    .postorder    = a23_post,
    .inorder      = a23_in,
    .breadthFirst = a23_bfs
  };

  testInput_t t6 = {
    .bst = createNewBST(),
    .array = a24,
    .size = sizeof (a24)/sizeof(a24[0]),
    .min = 1,
    .max = 3,
    .preorder     = a24_pre,
    .postorder    = a24_post,
    .inorder      = a24_in,
    .breadthFirst = a24_bfs
  };

  testInput_t t7 = {
    .bst = createNewBST(),
    .array = a3,
    .size = sizeof (a3)/sizeof(a3[0]),
    .min = 2,
    .max = 31,
    .preorder     = a3_pre,
    .postorder    = a3_post,
    .inorder      = a3_in,
    .breadthFirst = a3_bfs
  };

  testInput_t t8 = {
    .bst = createNewBST(),
    .array = a4,
    .size = sizeof (a4)/sizeof(a4[0]),
    .min = 2,
    .max = 23,
    .preorder     = a4_pre,
    .postorder    = a4_post,
    .inorder      = a4_in,
    .breadthFirst = a4_bfs
  };

  testInput_t t9 = {
    .bst = createNewBST(),
    .array = a5,
    .size = sizeof (a5)/sizeof(a5[0]),
    .min = 4,
    .max = 21,
    .preorder     = a5_pre,
    .postorder    = a5_post,
    .inorder      = a5_in,
    .breadthFirst = a5_bfs
  };

  operateOnInput(&t0, 1);
  operateOnInput(&t1, 2);
  operateOnInput(&t2, 3);
  operateOnInput(&t3, 4);
  operateOnInput(&t4, 5);
  operateOnInput(&t5, 6);
  operateOnInput(&t6, 7);
  operateOnInput(&t7, 8);
  operateOnInput(&t8, 9);
  operateOnInput(&t9, 10);

  return 0;
}

