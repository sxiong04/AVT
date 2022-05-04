#include "CelebrationDecorator.h"

void CelebrationDecorator::Move(IEntity* entity, double dt){
    this->strategy->Move(entity, dt);
}

bool CelebrationDecorator::IsCompleted(){
    return this->time >= stop;
}
