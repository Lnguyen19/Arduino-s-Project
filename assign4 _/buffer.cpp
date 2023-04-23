
/**
* Assignment 4: Producer Consumer Problem
 * @file buffer.cpp
 * @author Eric Escareno, Lam Nguyen (TODO: your name)
 * @brief Implementation file for the buffer class
 * @version 0.1
 */

//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
#include "buffer.h"
#include <iostream>

Buffer::Buffer(int size) {
  this->size = size;
  current = 0;
  front = 0;
  back = -1;
}

Buffer::~Buffer() {
}

bool Buffer::insert_item(buffer_item item) {
  if (is_full()) {
    return false;
  } else {
    back++;
    container.push(item);
    current++;
    return true;
  }
}

bool Buffer::remove_item(buffer_item *item) {
  if (is_empty()) {
    return false;
  } else {
    *item = container.front();
    container.pop();
    current--;
    front++;
    return true;
  }
}

int Buffer::get_size() {
  return size;
}

int Buffer::get_count() {
  return current;
}

bool Buffer::is_empty() {
  return container.empty();
}

bool Buffer::is_full() {
  return current == size;
}

void Buffer::print_buffer() {
 std::cout << "Buffer: [";
  if (is_empty()) {
    //std::cout << "[]" << std::endl;
  } else {
    string coma = ",";
    std::queue<buffer_item> other(container);
    while (!other.empty()) {
      std::cout << other.front() << " ";
     if(other.size()>1){
        std::cout<< coma;
      }
      else {
        coma = "";
        std::cout<<coma;
      }
      other.pop();
    }
   
  }
   std::cout << "]" << std::endl;
}

