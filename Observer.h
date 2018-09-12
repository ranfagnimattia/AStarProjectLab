//
// Created by matti on 11/09/18.
//

#ifndef ASTARLABSDL_OBSERVER_H
#define ASTARLABSDL_OBSERVER_H

class Observer {
public:
    virtual ~Observer() {}
    virtual void Update() = 0;
};
#endif //ASTARLABSDL_OBSERVER_H
