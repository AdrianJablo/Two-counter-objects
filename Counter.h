#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT

public:
    Counter(int value = 0);

    int Increment();
    int Decrement();
    int value() const;

signals:
    void changedValue(int value);

public slots:
    void setValue(int value);

private:
    int m_count;
};

#endif // COUNTER_H
