#ifndef NODE_H
#define NODE_H
#include <string>
#include <cstddef>
#include <iostream>


// Use this file to declare your Node type.
// Implement Node member functions and helper functions in Node.cpp.
struct Node{
    std::string data;
    size_t count;
    Node* left;
    Node* right;
    
    Node(std::string str = "");
    ~Node();
    
    size_t Count(struct Node* node);
    Node* Insert(struct Node* node, std::string str);
    Node* Remove(struct Node* node, std::string str); //
    Node* Check(struct Node* node, std::string str); // used in contains()
    void Traversal(Node* node); //used in debug()
    void Traversal_Reverse(Node* node); //used in debug()
    void Clear(Node* node); // used in clear()
    void Search(Node* node, int n); //used in lookup()
};

#endif
