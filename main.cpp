/*Orestes Bringas. 
Program to test a multiset/bag. The program uses a single main.cpp file and has hardcoded tests to
check functionality of each function and the interaction with the bag.
*/

#include <string>
#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//sets the template and defines the class ArrayBag
template <class T>
class ArrayBag{
    //class attributes
    private:
        T *arr;
        int size;
    //class functions
    public: 
        ArrayBag();
        ~ArrayBag();
        int getSize();
        bool isEmpty();
        bool isFull();
        bool add(T element);
        bool remove();
        bool contains(T element)const;
        void makeEmpty();
        void printElements();
};

//creates the ArrayBag
template <class T>
ArrayBag<T>::ArrayBag(){
    this->arr = new T[1000];
    this->size = 0;
}

//ArrayBag destructor
template <class T>
ArrayBag<T>::~ArrayBag(){
    delete[] arr;
}

//gets the size of the array
template <class T>
int ArrayBag<T>::getSize(){
    return size;
}

//checks if the bag is empty
template <class T>
bool ArrayBag<T>::isEmpty(){
    return (size == 0);
}

//checks if the bag is full
template <class T>
bool ArrayBag<T>::isFull(){
    return (size == 1000);
}

//adds an element to the bag
template <class T>
bool ArrayBag<T>::add(T element){
    if(isFull())
        return false;
    arr[size] = element;
    size++;
    return true;
}

//removes an element from the bag
template <class T>
bool ArrayBag<T>::remove(){
    if(isEmpty())
        return false;
    size--;
    return true;
}

//checks if the element is contained
template <class T>
bool ArrayBag<T>::contains(T element) const{
    for(int i = 0; i < size; i++){
        if(arr[i] == element)
            return true;
    }

    return false;
}

//empties the bag
template <class T>
void ArrayBag<T>::makeEmpty(){
    size = 0;
}

//prints bag elements
template <class T>
void ArrayBag<T>::printElements(){
    for(int i = 0; i <this->size; ++i)
        cout << this->arr[i] << endl;
}

//main function to test all aspects of the bag and the functions
int main(){
    ArrayBag<string> bag;
    cout << "Multiset/Bag Test" << endl << endl;

    //adds elements
    bag.add("John");
    bag.add("Joel");
    bag.add("Samantha");
    bag.add("John");
    
    //prints elements
    cout << "ELEMENTS\n" << endl;
    bag.printElements();

    //checks for empty and full
    cout << "\nisEmpty: ";
    bag.isEmpty() ? cout << "Yes\n" : cout << "No\n";
    cout << "isFull: ";
    bag.isFull() ? cout << "Yes\n" : cout << "No\n";

    //checks for contained element
    cout << "contains: 'John'? ";
    bag.contains("John") ? cout << "Yes\n" : cout << "No\n";

    //checks for element that is not contained
    cout << "contains: 'Bob'? ";
    bag.contains("Bob") ? cout << "Yes\n" : cout << "No\n";
    
    //removes an element
    bag.remove();
    
    //prints the new bag
    cout << "\nELEMENTS" << endl;
    bag.printElements();

    //fills bag for testing if full
    cout << "\nFilling bag: ";
    while(!bag.isFull()){
        bag.add("You");
    }
    bag.isFull() ? cout << "Done! Bag contains " << bag.getSize() << endl  : cout << "Failed!\n";

    //checks to add when bag is full
    cout << "Attempting to add more to full bag: ";
    bag.add("Me") ? cout << "Added\n" : cout << "Bag too full\n";

    //empties the bag and checks if empty
    cout << "\nEmptying bag now: ";
    bag.makeEmpty();
    bag.isEmpty() ? cout << "Done! Bag contains " << bag.getSize() << endl : cout << "Failed!\n";

    cout << "\nELEMENTS\n";
    bag.isEmpty() ? cout << "Bag is empty!\n" : cout << "Bag has Elements";

    return 0;
}