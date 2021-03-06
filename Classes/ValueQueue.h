#ifndef __VALUE_QUEUE_H__
#define __VALUE_QUEUE_H__

#include <algorithm>
#include <cstdlib>
#include <list>
#include <stdint.h>

/**
 * The ValueQueue class creates a queue of sensor values
 * 
 * @author Sedona Thomas
 * @version 1.0.0
 */
class ValueQueue {
private:
  std::list<uint8_t> values;

public:
  ValueQueue();
  ValueQueue(int);
  void add(uint8_t);
  inline void push(uint8_t);
  inline void pop();
  bool contains(uint8_t);
  uint8_t average();
  uint8_t median();
  inline size_t size();
};

#endif