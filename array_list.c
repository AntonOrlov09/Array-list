#include "list.h"
#include <stdlib.h>

// Пользовательская структура, которая скрывает механизм хранения данных.
struct List {
  int* array; // динамический массив, в котором будут раниться все данные
  int length; // размер списка: последний занятый индекс в array
  int capacity; // ёмкость списка: реальный размер массива array
  int size; // кол-во элементов в списке
  // если нужно, то добавьте дополнительные поля
};

List *NewList() {
    List* list = malloc(sizeof(List));
    list -> length=-1;
    list -> capacity=0;
    list -> size=0;
}

void DestroyList(List* this) {
    this -> length=-1;
    this -> capacity=0;
    this -> size=0;
    free(this -> array);
    free(this);
}

void big_memory(List* this) {   // функция для увеличения объема памяти
    this->capacity*=2;
    int* arr=malloc(sizeof(int)*this->capacity);
    for (int i=0;i< this->size; i++) {
        arr[i]=this -> array[i];
    }
    free(this -> array);
    this ->array=arr;
}

void small_memory(List* this) {  // функция для уменьшения объема памяти
    this->capacity/=2;
    int* arr=malloc(sizeof(int)*this->capacity);
    for (int i=0;i<this->size+1;i++) {
        arr[i]=this -> array[i];
    }
    free(this -> array);
    this ->array=arr;
}

void Append(List *this, int value) {
    this->length++;
    this ->size++;
    if (this-> capacity==0) {
        this ->capacity=2;
        this -> array=malloc(sizeof(int)*this->capacity);
        this ->array[this -> length]=value;
    }
    if (this->size==this->capacity) {
        big_memory(this);
    }
    this ->array[this -> length]=value;
}
void Prepend(List *this, int value) {
    this->length++;
    this ->size++;
    if (this-> capacity==0) {
        this ->capacity=2;
        this -> array=malloc(sizeof(int)*this->capacity);
        this ->array[this -> length]=value;
    }
    if (this->size==this->capacity) {
        big_memory(this);
    }
    for (int i=this->length-1;i<0;i--) {
        this->array[i+1]=this->array[i];
    }
    this->array[0]=value;
}
void AppendAll(List *this, const List *that) {

}
void InsertAt(List *this, int index, int value) {
    this->length++;
    this ->size++;
    if (this->size==this->capacity) {
        big_memory(this);
    }
    for (int i=this->length-1;i<index+1;i--) {
        this->array[i+1]=this->array[i];
    }
    this->array[index+1]=value;
}

void RemoveAt(List *this, int index) {
    this->length--;
    this ->size--;
    if (this->capacity/this->size==4) {
        small_memory(this);
    }
   for (int i=index;i<this->size+1;i++)  {
       this->array[i]=this->array[i+1];
   }
}
void RemoveAll(List *this) {
    this -> length=-1;
    this -> capacity=0;
    this -> size=0;
    free(this -> array);
}

int Pop(List *this) {
    this->length--;
    this ->size--;
    if (this->capacity/this->size==4) {
        small_memory(this);
    }
    int t=this->array[this->length+1];
    this->array[this->length+1]=0;
    return t;
}
int Dequeue(List *this) {
    this->length--;
    this ->size--;
    if (this->capacity/this->size==4) {
        small_memory(this);
    }
    int t=this->array[0];
    for (int i=0;i<this->length+1;i++) {
        this->array[i]=this->array[i+1];
    }
    return t;
}

int Length(const List *this) {
    return this-> size;
}
int GetAt(const List *this, int index) {
    return this->array[index];
}
