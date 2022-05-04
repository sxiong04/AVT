#include "DisappearStrategy.h"

DisappearStrategy::DisappearStrategy(Vector3 pos_, Vector3 des_, int wait_) {
    pos = pos_;
    des = des_;
    wait = wait_;
    time = 0.25;
}

bool DisappearStrategy::IsCompleted(){
    return (time >= wait);
}

void DisappearStrategy::Move(IEntity* entity,double dt){
    time += dt;
    entity->SetPosition(des);
}