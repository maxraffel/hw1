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
std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc < 0 || loc >= size_) {
    return NULL;
  }

  size_t counter = loc;
  // we should never worry about this being null
  // since we already ensured it was a valid input
  Item* current = head_;

  while (counter >= 0) {
    size_t currentLength = current->last - current->first;
    if (current->last - current->first > counter) {
      return &current->val[current->first + counter];
    } else {
      counter -= currentLength;
      current = current->next;
    }
  }
}

void ULListStr::startList(const std::string val) {
  Item* newItem = new Item();
  newItem->last = 1;
  newItem->val[0] = val;
  head_ = newItem;
  tail_ = newItem;
}

void ULListStr::push_back(const std::string& val) {
  if (empty()) {
    startList(val);
  } else if (tail_->last == ARRSIZE) {
    Item* newItem = new Item();
    newItem->last = 1;
    newItem->val[0] = val;
    tail_->next = newItem;
    newItem->prev = tail_;
    tail_ = newItem;
  } else {
    tail_->val[tail_->last] = val;
    tail_->last += 1;
  }
  size_ += 1;
}

void ULListStr::push_front(const std::string& val) {
  if (empty()) {
    startList(val);
  } else if (head_->first == 0) {
    Item* newItem = new Item();
    newItem->last = ARRSIZE;
    newItem->first = ARRSIZE - 1;
    newItem->val[ARRSIZE - 1] = val;
    newItem->next = head_;
    head_->prev = newItem;
    head_ = newItem;
  } else {
    head_->first -= 1;
    head_->val[head_->first] = val;
  }
  size_ += 1;
}

void ULListStr::pop_back() {
  if (empty()) {
    return;
  }

  if (size_ == 1) {
    delete tail_;
    tail_ = NULL;
    head_ = NULL;
    size_ = 0;
    return;
  }

  if (tail_->last - tail_->first == 1) {
    Item* temp = tail_->prev;
    delete tail_;
    tail_ = temp;

    if (tail_ != NULL) {
      tail_->next = NULL;
    }
  } else {
    tail_->last -= 1;
  }
  size_ -= 1;
}

void ULListStr::pop_front() {
  if (empty()) {
    return;
  }

  if (size_ == 1) {
    delete tail_;
    tail_ = NULL;
    head_ = NULL;
    size_ = 0;
    return;
  }
  
  if (head_->last - head_->first == 1) {
    Item* temp = head_->next;
    delete head_;
    head_ = temp;

    if (head_ != NULL) {
      head_->prev = NULL;
    }
  } else {
    head_->first += 1;
  }
  size_ -= 1;
}

std::string const & ULListStr::back() const {
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const {
  return head_->val[head_->first];
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
