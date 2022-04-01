#include "ValueQueue.h"

/**
 * ValueQueue constructor makes a queue to store sensor values with default values of 0
 */
ValueQueue::ValueQueue() {
  for (int i = 0; i < 5; i++) {
    values.push_back(0);
  }
}

/**
 * ValueQueue constructor makes a queue to store sensor values with default values of 0
 * 
 * @param size initial size of the queue
 */
ValueQueue::ValueQueue(int size) {
  for (int i = 0; i < size; i++) {
    values.push_back(0);
  }
}

/**
 * The add method adds a value to the queue
 * 
 * @param value sensor value to be added to the queue
 */
void ValueQueue::add(uint8_t value) {
  push(value);
  pop();
}

/**
 * The push method pushes a value to the end of the queue
 * 
 * @param value sensor value to be added to the queue
 */
inline void ValueQueue::push(uint8_t value) { values.push_back(value); }

/**
 * The pop method removes the first value from the queue
 */
inline void ValueQueue::pop() { values.pop_front(); }

/**
 * The contains method checks if a value if in the queue
 * 
 * @param i value to be checked if in the queue
 */
bool ValueQueue::contains(uint8_t i) {
  return std::find(values.begin(), values.end(), i) != values.end();
}

/**
 * The average method returns the average value of the queue
 */
uint8_t ValueQueue::average() {
  int sum = 0;
  for (auto val : values) {
    sum += val;
  }
  return sum / size();
}

/**
 * The median method returns the median value of the queue
 */
uint8_t ValueQueue::median() {
  std::list<uint8_t> temp(values);
  temp.sort();
  std::list<uint8_t>::iterator it = temp.begin();
  for (int i = 0; i < temp.size() / 2; i++) {
    it++;
  }
  return *it;
}

/**
 * The size method returns the size of the queue
 * 
 * @return the current size of the queue
 */
inline size_t ValueQueue::size() { return values.size(); }