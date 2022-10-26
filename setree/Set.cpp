#include "Set.h"

Set::Set(){
    mRoot = new Node();
}

Set::Set(const Set& other){
    Node* temp = mRoot->Copy(other.mRoot);
    mRoot = temp;
}

Set::Set(Set&& other){
    mRoot = other.mRoot;
    other.mRoot = nullptr;
}

Set::~Set(){
    delete mRoot;
}

size_t Set::clear(){
    mRoot->Clear(mRoot);
    return mRoot->Count(mRoot);
}

bool Set::contains(const std::string& value) const{
    if(mRoot->Check(mRoot, value) != nullptr){
        return true;
    }
    return false;
}

size_t Set::count() const{
    return (mRoot->Count(mRoot) - 1);
}

void Set::debug(){
    mRoot->Traversal(mRoot);
}

size_t Set::insert(const std::string& value){
    if(mRoot->Check(mRoot, value) != nullptr) {
        return 0;
    }
    else {
        mRoot->Insert(mRoot, value);
    }
    return 1;
}

const std::string& Set::lookup(size_t n) const{
    if(n > this->count()){
        throw std::out_of_range("Out of Range");
    }
    size_t location = this->count() - n;
    return (mRoot->nthLargest(mRoot, location))->data;
}

void Set::print() const{
    mRoot->Traversal_Reverse(mRoot);
}

size_t Set::remove(const std::string& value){
    if(mRoot->Check(mRoot, value) != nullptr) { //already exist
        mRoot->Remove(mRoot, value);
        return 1;
    }
    return 0;
}
