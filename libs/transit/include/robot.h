#ifndef ROBOT_H
#define ROBOT_H

#include "util/json.h"
#include "entity.h"
#include "math/vector3.h"
#include "IStrategy.h"
#include "DisappearStrategy.h"

#include <vector>

class Robot : public IEntity {
public:
    Robot(JsonObject& obj);

    ~Robot() override = default;

    Vector3 GetPosition() const { return position; }

    Vector3 GetDirection() const { return direction; }

    Vector3 GetDestination() const { return destination; }
    
    Vector3 GetDestinations() const { return destinations.front(); }

    int GetWaittime() const { return waitTimes.front(); }

    bool isEmpty() const {return destinations.empty(); }

    bool isWaittimeEmpty() const {return waitTimes.empty(); }

    bool GetAvailability() const {return available;}

    JsonObject GetDetails() const override;

    float GetSpeed() const {return speed;}

    std::string GetStrategyName() const {return strategyName;}

    void SetAvailability(bool choice);

    //void Update(double dt, std::vector<IEntity*> scheduler);

    void popDestinations() {destinations.pop();}

    void SetPosition(Vector3 pos_) { position = pos_; }

    void popWait() {waitTimes.pop();}

    void SetDirection(Vector3 dir_) { direction = dir_; }

    void SetDestination(Vector3 des_) { destination = des_;}

    void SetDestinations(Vector3 des_) { destinations.push(des_); }

    void SetWaittime(int time_) { waitTimes.push(time_);}

    void SetStrategyName(std::string strategyName_) { strategyName = strategyName_;}

    void SetStrategy(Vector3 pos_, Vector3 des_, int wait_) { strategy = new DisappearStrategy(pos_, des_, wait_);}

    void Rotate(double angle);

protected:
    JsonObject details;
    Vector3 position;
    Vector3 direction;
    Vector3 destination;
    Vector3 original;
    float speed;
    bool available=true;
    IStrategy* strategy = NULL;
    std::string strategyName;
};

#endif //ROBOT_H
