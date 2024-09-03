#include "Counter.h"
#include <iostream>

Counter::Counter(int startValue) : m_count(startValue) {}

int Counter::Increment() {
    m_count++;
    //std::cout << "Counter incremented to " << m_count << std::endl;
    emit changedValue(m_count);
    return m_count;
}

int Counter::Decrement() {
    m_count--;
    //std::cout << "Counter decremented to " << m_count << std::endl;
    emit changedValue(m_count);
    return m_count;
}

int Counter::value() const {
    return m_count;
}

void Counter::setValue(int newValue) {
    m_count = newValue;
    //std::cout << "Counter value set to " << m_count << std::endl;
}
