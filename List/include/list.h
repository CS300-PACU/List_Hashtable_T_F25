/**************************************************************************
 File name:		list.h
 Author:        CS, Pacific University
 Date:          09.19.2019
 Class:         CS300
 Assignment:    List Interface
 Purpose:       This file defines the constants, data structures, and
                function prototypes for implementing a list data structure.
                In essence, the list API is defined for other modules.
 *************************************************************************/

#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


//*************************************************************************
// User-defined types
//*************************************************************************
typedef struct ListElement *ListElementPtr;
typedef struct ListElement
{
	// Note: The memory allocated for data cannot contain any pointers to
	//		 additional data or terminate will not work correctly; therefore,
	//		 data must point to a contiguous block of data and contain no
	// 		 additional pointers.
	void *pData;
	ListElementPtr psNext;
} ListElement;


// A list is a dynamic data structure where the current pointer and number
// of elements are maintained at all times

typedef struct List *ListPtr;
typedef struct List
{
	ListElementPtr psFirst;
	ListElementPtr psLast;
	ListElementPtr psCurrent;
	int numElements;
	size_t itemSize;
} List;


//*************************************************************************
// Error reporting functions
//*************************************************************************
extern void processError(const char* szFile, const int line);
// helper function to report errors

// macro to report error
#define reportError   processError(__FILE__, __LINE__)



//*************************************************************************
// Allocation and Deallocation
//*************************************************************************
extern void lstCreate (ListPtr psList, size_t itemSize);
// results: If the list can be created, then the list exists and is empty;

extern void lstTerminate (ListPtr psList);
// results: If the list can be terminated, then the list no longer exists
//			and is empty;

//*************************************************************************
// Checking number of elements in list
//*************************************************************************
extern int lstSize (const ListPtr psList);
// results: Returns the number of elements in the list

extern bool lstIsEmpty (const ListPtr psList);
// results: If list is empty, return true; otherwise, return false

//*************************************************************************
//												List Testing
//*************************************************************************
extern bool lstHasCurrent (const ListPtr psList);
// results: Returns true if the current node pointed to by psCurrent is
//			not NULL; otherwise, false is returned

//*************************************************************************
//													Peek Operations
//*************************************************************************
extern bool lstPeek (const ListPtr psList, void *pBuffer);
// requires:  List is not empty
// results:   The value of the current element pointed to by psCurrent
//            is returned
// IMPORTANT: Do not change psCurrent


//*************************************************************************
//							Updating current
//*************************************************************************
extern bool  lstFirst (ListPtr psList);
// requires:  List is not empty
// results:   If the list is not empty, psCurrent is changed to
//            the first element

extern bool lstNext (ListPtr psList);
// requires:  List is not empty
// results:   If the list is not empty,
//			      psCurrent is changed to the successor of the current element
//            pointed to by psCurrent

extern bool lstLast (ListPtr psList);
// requires:  List is not empty
// results:   If the list is not empty,
//  		      psCurrent is changed to psLast

//*************************************************************************
//									Insertion, Deletion, and Updating
//*************************************************************************

extern bool lstInsertAfter (ListPtr psList, const void *pBuffer);
// requires: List is not full
// results:  If the list is not empty, insert the new element as the
//           successor of the current element pointed to by psCurrent
//           and make the inserted element the current element pointed to
//           by psCurrent;
//	    		 otherwise, insert element and make it current.

extern bool lstDeleteCurrent (ListPtr psList, void *pBuffer);
// requires: List is not empty
// results: The current element is deleted and its successor and
//			predecessor become each others successor and predecessor. If
//			the deleted element had a predecessor, then make it the new
// 			current element; otherwise, make the first element current if
// 			it exists. The value of the deleted element is returned.

extern bool lstInsertBefore (ListPtr psList, const void *pBuffer);
// requires: List is not full
// results:  If the list is not empty, insert the new element as the
//           predecessor of the current element and make the inserted
//           element the current element; otherwise, insert element
//           and make it current.

extern bool lstUpdateCurrent (ListPtr psList, const void *pBuffer);
// requires: List is not empty
// results:  The value of pBuffer is copied into the current element
// IMPORTANT: user could update with smaller, larger, or the same size data
//			  so free data, then reallocate based on size before updating

extern bool lstReverse(ListPtr psList); // optional. Reverses the List

#endif /* LIST_H_ */