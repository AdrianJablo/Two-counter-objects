#include <QCoreApplication>
#include <iostream>
#include "Counter.h"

using namespace std;

void printValues(const Counter &c1, const Counter &c2) {
    cout << "Counter1: " << c1.value() << ", Counter2: " << c2.value() << endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Counter firstCounter(5);
    Counter secondCounter(10);

    QObject::connect(&firstCounter, &Counter::changedValue, &secondCounter, &Counter::setValue);
    QObject::connect(&secondCounter, &Counter::changedValue, &firstCounter, &Counter::setValue);

    cout << "Initial values: ";
    printValues(firstCounter, secondCounter);

    firstCounter.Increment();
    cout << "After Incrementing first counter: ";
    printValues(firstCounter, secondCounter);

    secondCounter.Increment();
    cout << "After Incrementing second counter: ";
    printValues(firstCounter, secondCounter);

    firstCounter.Decrement();
    cout << "After Decrementing first counter: ";
    printValues(firstCounter, secondCounter);

    secondCounter.Decrement();
    cout << "After Decrementing second counter: ";
    printValues(firstCounter, secondCounter);

    return a.exec();
}
