#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{
  // check if there are elements in the list
  if (empty()) {
    createList();
  }
  // check if tail has room at the back
  else if (tail_->last == ARRSIZE) {
    // allocate new tail
    tail_->next = new Item();
    tail_->next->prev = tail_;
    tail_ = tail_->next;
  }
  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++;
}

void ULListStr::pop_back() 
{
  if (empty())
    return;

  tail_->last--;
  size_--;

  // check if tail is empty 
  if (tail_->last == tail_->first) {
    // deallocate tail
    Item* temp = tail_->prev;
    delete tail_;

    tail_ = temp;
    if (tail_ != NULL)
      tail_->next = NULL;
    else
      head_ = NULL;
  }
}

void ULListStr::push_front(const std::string& val) 
{
  // check if there is an element in the list
  if (empty()) {
    createList();
    head_->first = head_->last = (ARRSIZE);
  }
  
  // check if head has room in the front
  else if (head_->first == 0) {
    // allocate new head
    head_->prev = new Item();
    head_->prev->next = head_;
    head_->prev->first = head_->prev->last = (ARRSIZE);
    head_ = head_->prev;
  }
  size_++;
  head_->first--;
  head_->val[head_->first] = val;
}

void ULListStr::pop_front() 
{
  if (empty())
    return;

  head_->first++;
  size_--;

  // check if head is empty
  if (head_->first == head_->last) {
    // deallocate head
    Item* temp = head_->next;
    delete head_;

    head_ = temp;
    if (head_ != NULL)
      head_->prev = NULL;
    else
      tail_ = NULL;
  }
}

std::string const & ULListStr::back() const 
{
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const 
{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_)
    return NULL;

  Item* temp = head_;
  size_t ptr = temp->first;
  while (loc >= 0) {
    // checking if still in bounds
    if (ptr == temp->last) {
      temp = temp->next;
      ptr = temp->first;
    }
    if (loc == 0) 
      return &(temp->val[ptr]);
    ptr++;
    loc--;
  }
  return NULL;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

void ULListStr::createList() 
{
  head_ = new Item();
  head_->prev = head_->next = NULL;
  tail_ = head_;
  size_ = 0;
}