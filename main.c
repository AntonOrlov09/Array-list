#include "list.h"
#include <stdio.h>
#include <stdlib.h>

static void AssertEq(int expected, int actual, const char* msg) {
  if (expected != actual) {
    printf("Test failed: %s\n expected %d but got %d\n", msg, expected, actual);
    exit(-1);
  }
}

int main(void) {
  List* list = NewList();
  AssertEq(0, Length(list), "empty list length should be zero");
  Append(list, 42);
  AssertEq(1, Length(list), "Length([42]) should be 1");
  AssertEq(42, GetAt(list, 0), "GetAt([42], 0) should be 42");
  Prepend(list,1);
  AssertEq(1, GetAt(list, 0), "GetAt([42], 0) should be 42");
  InsertAt(list,0,7);
  AssertEq(7, GetAt(list, 1), "GetAt([42], 0) should be 42");
  RemoveAt(list,2);
  AssertEq(0, GetAt(list, 2), "GetAt([42], 0) should be 42");
  AssertEq(7, Pop(list), "GetAt([42], 0) should be 42");
  Append(list,100);
  AssertEq(1, Dequeue(list), "GetAt([42], 0) should be 42");
  DestroyList(list);
  
  //TODO: Здесь куча разных ваших тестов!!!
}   