#include "WaitDecorator.h"

void WaitDecorator::Move(IEntity* entity, double dt){
    if (strategy->IsCompleted() && !WaitDecorator::IsCompleted()){
        CelebrationDecorator::time += dt;
    } else {
        CelebrationDecorator::Move(entity, dt);
    }
}

bool WaitDecorator::IsCompleted(){
    return CelebrationDecorator::IsCompleted();
}
