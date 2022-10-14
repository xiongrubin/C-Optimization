#include "List.h"
#include <iostream>
#include <algorithm>
//using namespace std; //whether need to used ?

<<<<<<< HEAD
List::List(){
    head = nullptr;
    num = 0;
}

List::List(const List& other) {
    for(Node* list = other.head; list; list = list->next){
        head = list;
        head = head->next;
    }
=======
const size_t Min = 0;

List::List(){
    head = nullptr;
}

List::List(const List& other) {
    Node** temp = &head;

    for(Node* list = other.head; list; list = list->next)
    {
        (*temp) = new Node(*list);
        temp = &((*temp)->next);
    }
    temp = nullptr;
>>>>>>> fe68cb192c03ab143e20a0b1e91d014c1b4915cd
}

List::List(List&& other){
    for(Node* list = other.head; list; list = list->next){
        head->data = list->data;
        head = head->next;
    }
}

List::~List(){
<<<<<<< HEAD
    /*Node* current = head;
    while(current != nullptr) {
        Node* temp = current;
        current = current -> next;
        delete temp;
    }
    head = nullptr;*/
}

size_t List::count() const{
    return num;
}

void List::insert(const std::string& value){ // higher piority
    num ++;
    
=======
    Node* current = head;
    Node* temp = nullptr;
    while(current != nullptr) {
        temp = current;
        current = current -> next;
        temp = nullptr;
    }
    head = nullptr;
}

size_t List::count() const{
    Node* temp = head;
    size_t count = 0;
    
    while(temp) { //!   !
        count ++;
        temp = temp->next;
    }
    return count;
}

void List::insert(const std::string& value){ // higher piority
>>>>>>> fe68cb192c03ab143e20a0b1e91d014c1b4915cd
    Node* test = new Node;
    test->data = value;
    test->next = nullptr;
    
<<<<<<< HEAD
    if(head == nullptr){
        head = test;
        std::cout << "insert() executed!" << " " << head->data << " " << "inserted" << std::endl;
=======
    if(!head) { //!   !
        head = test;
        //std::cout << "insert() executed!" << " " << head->data << " " << "inserted" << std::endl;
>>>>>>> fe68cb192c03ab143e20a0b1e91d014c1b4915cd
        return;
    }
    
    Node* current = head;
    Node* pre = nullptr;
    std::string str;
    while(current != nullptr && value.compare((current->data)) > 0){
        pre = current;
        current = current->next;
        if(current != nullptr){
            str = current->data;
        }
    }
    
    if(pre == nullptr){
        pre = head;
        head = test;
        head->next = pre;
        return;
    }
    
    pre->next = test;
    test->next = current;
<<<<<<< HEAD
    std::cout << (pre->next)->data << " " << std::endl;
    
    std::cout << "insert() executed!" << " " << (head->next)->data << " " << "inserted" << std::endl;
=======
    //std::cout << (pre->next)->data << " " << std::endl;
    
    //std::cout << "insert() executed!" << " " << (head->next)->data << " " << "inserted" << std::endl;
>>>>>>> fe68cb192c03ab143e20a0b1e91d014c1b4915cd
}


const std::string& List::lookup(size_t index) const{
    if(index >= this->count() || index < Min){
        throw std::out_of_range("Out of Range");
    }
    Node* current = head;
    std::string *str;
    while(index > 0){
        current = current->next;
        index --;
    }
    str = &(current->data);
    return *str;
}

void List::print(bool reverse) const{ // higher piority
    size_t index = count();
    std::cout << "[";
    Node* temp;
    
<<<<<<< HEAD
    if(count() > Min){
        
            if(reverse){
            Node* temp = nullptr;
            Node* prev = nullptr;
            Node* current = head;
            while(current != nullptr){
                temp = current ->next;
                current -> next = prev;
                prev = current;
                current = temp;
            }
            temp = prev;
=======
    if(index > Min){
        
            if(reverse){
            while(index > 1){
                index --;
                std::cout << lookup(index) << ", ";
            }
            std::cout << lookup(0);
        }
        
            else {
            temp = head;
>>>>>>> fe68cb192c03ab143e20a0b1e91d014c1b4915cd
            while(index > 1){
                std::cout << temp->data << ", ";
                temp = temp->next;
                index --;
            }
            std::cout << temp->data;
        }
<<<<<<< HEAD
        
        temp = head;
        while(index > 1){
            std::cout << temp->data << ", ";
            temp = temp->next;
            index --;
        }
        std::cout << temp->data;
        
    }
    
    std::cout << "]";
=======
    }
    
    std::cout << "]" << std::endl;
>>>>>>> fe68cb192c03ab143e20a0b1e91d014c1b4915cd
}

std::string List::remove(size_t index){
    if(index >= this->count() || index < Min){
        throw std::out_of_range("Out of Range");
    }
<<<<<<< HEAD
    num --;
    Node* current = head;
    std::string str;
    
    if(count() == Min){
        str = head->data;
        free(current->next);
        current = nullptr;
        return str;
=======
    Node* current = head;
    std::string str;
    
    if(count() == Min + 1 || index == Min){
        Node* temp = head;
        head = head->next;
        return temp->data;
>>>>>>> fe68cb192c03ab143e20a0b1e91d014c1b4915cd
    }

    while(index > 1){
        current = current->next;
        index --;
    }
    
<<<<<<< HEAD
    Node* temp = current->next->next;
    str = (temp->next)->data;
    free(current->next);
    current = temp;
=======
    Node* temp = current->next;
    current = temp->next;
    str = temp->data;
>>>>>>> fe68cb192c03ab143e20a0b1e91d014c1b4915cd
    
    return str;
}

size_t List::remove(const std::string& value){
    size_t count = 0;
    size_t index = 0;
    Node* temp = head;
    while (temp) {
        if(value.compare(temp->data)){
            count ++;
            remove(index);
        }
        temp = temp->next;
        index ++;
    }
    return count;
}
