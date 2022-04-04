#include <iostream>

template <typename T>
class Vector{
    int count;
    T* elements;
    int index;
    Vector();
    void push(T element);
    void pop (T element);
    void remove (T index);   
    void insert (T index);
};
 
template <typename T>
void Vector<T>::push(T element) {
  this->count++;
  this->elements = static_cast<T>(realloc(this->elements, this->count * sizeof(T)));
    this -> elements [this->count - 1] = element;
}
 
template <typename T>
void Vector<T>::pop(T element){
    this->count--;
    this->elements = static_cast<T>(realloc(this->elements, this->count * sizeof(T)));
}

template <typename T>
void Vector<T>::remove (T index){
    for (int i = index; i < count; i++)
        this -> elements[i] = this->elements[i + 1];
    this->count--;
    this->elements = static_cast<T>(realloc(this->elements, this->count * sizeof(T)));
}

template <typename T>
void Vector<T>::insert (T index){
    count++;
}

int main (void){

}