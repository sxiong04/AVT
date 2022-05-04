#ifndef CELEBRATION_DECORATOR_H_
#define CELEBRATION_DECORATOR_H_

#include <vector>
#include "IStrategy.h"

class CelebrationDecorator: public IStrategy {
    public:
        CelebrationDecorator(IStrategy *strategy_, int time_) {strategy = strategy_; time = 0; stop = time_;}
        void Move(IEntity* entity, double dt);
        bool IsCompleted();
    protected:
        IStrategy *strategy;
        float time;
        int stop;
}; //close class 

#endif // CELEBRATION_DECORATOR_H_