#include "../include/list.h"
#include <stdlib.h>
#include <stdio.h>


void processError(const char* szFile, const int line)
{
  fprintf(stderr, "ERROR: %s: %d\n", szFile, line);
  fflush(NULL);
  exit(EXIT_FAILURE);
}

void lstCreate(ListPtr psList, size_t itemSize)
{
}

void lstTerminate(ListPtr psList)
{
}

int lstSize(const ListPtr psList)
{
  return 0;
}


bool lstIsEmpty(const ListPtr psList)
{
  bool bIsEmpty = true;

 
  return bIsEmpty;
}

bool lstHasCurrent(const ListPtr psList)
{
  bool bHasCurrent = true;
 
  return bHasCurrent;
}

bool lstPeek(const ListPtr psList, void *pBuffer)
{

  return false;
}

bool lstFirst(ListPtr psList)
{
  return false;
}

bool lstLast(ListPtr psList)
{
  return false;
}


bool lstNext(ListPtr psList)
{
  return false;
}

bool lstInsertAfter(ListPtr psList, const void *pBuffer)
{
  return false;
}

bool lstInsertBefore(ListPtr psList, const void *pBuffer)
{
  return false;
}

bool lstDeleteCurrent (ListPtr psList, void *pBuffer)
{

  return false;
}

bool lstUpdateCurrent (ListPtr psList, const void *pBuffer)
{
  return false;
}

// BONUS
bool lstReverse(ListPtr psList)
{
  return false;
}
