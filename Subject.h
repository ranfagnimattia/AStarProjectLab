//
// Created by matti on 11/09/18.
//

#ifndef ASTARLABSDL_SUBJECT_H
#define ASTARLABSDL_SUBJECT_H

#include "Observer.h"
#include "GameObject.h"

class Subject {
public:
    virtual ~Subject() {}
    virtual void registerObserver(Observer* o) = 0;
    virtual void unregisterObserver(Observer* o) = 0;
    virtual void notify() = 0;
};
#endif //ASTARLABSDL_SUBJECT_H
