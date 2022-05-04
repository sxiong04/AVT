#ifndef WAIT_DECORATOR_H_
#define WAIT_DECORATOR_H_

#include <vector>
#include "CelebrationDecorator.h"
#include "IStrategy.h"
#include "entity.h"

class WaitDecorator: public CelebrationDecorator {
    public:
        WaitDecorator(IStrategy *strategy_, int time_) : CelebrationDecorator(strategy_, time_) {}
        bool IsCompleted();
        void Move(IEntity* entity, double dt);
}; //close class 

#endif // SPIN_DECORATOR_H_
