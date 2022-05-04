#ifndef DISAPPEARSTRATEGY_H_
#define DISAPPEARSTRATEGY_H_

/**
 * include
 */
#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "entity.h"


class DisappearStrategy : public IStrategy {
public:
    DisappearStrategy(Vector3 pos_, Vector3 des_, int wait);
    ~DisappearStrategy();
    void Move(IEntity* entity, double dt);
    bool IsCompleted();

protected:
    Vector3 des;
    Vector3 pos;
    int wait;
    float time;
}; //end class


#endif