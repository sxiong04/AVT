#include "robot.h"
#include "DisappearStrategy.h"

Robot::Robot(JsonObject &obj) : details(obj) {
    JsonArray pos(obj["position"]);
    position = {pos[0], pos[1], pos[2]};
    original = {pos[0], pos[1], pos[2]};

    JsonArray dir(obj["direction"]);
    direction = {dir[0], dir[1], dir[2]};

    speed = obj["speed"];
    available = true;
}

JsonObject Robot::GetDetails() const {
    return details;
}

// void Robot::Update(double dt, std::vector<IEntity*> scheduler) {
//     std::cout << "Hello" << std::endl;
//     if(available) {
//         std::cout << "Hello2" << std::endl;
//         strategy->Move(this, dt);
//         if(strategy->IsCompleted()){
//             this->SetPosition(original);
//             delete strategy;
//         }
//         available = false;
//     }
// }

void Robot::SetAvailability(bool choice) {
    available = choice;
}

void Robot::Rotate(double angle){
    direction.x = direction.x*std::cos(angle) - direction.z*std::sin(angle);
    direction.z = direction.x*std::sin(angle) + direction.z*std::cos(angle);
}