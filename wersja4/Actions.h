#pragma once
#include <initializer_list>
#include <memory>
#include <vector>
using coordinate_t = uint32_t;
using position_t = std::pair<coordinate_t, coordinate_t>;

namespace Direction {
    constexpr position_t EAST = std::make_pair(1,0);
    constexpr position_t WEST = std::make_pair(-1,0);
    constexpr position_t NORTH = std::make_pair(0,1);
    constexpr position_t SOUTH = std::make_pair(0,-1);

}

struct Sensor {
    virtual bool is_safe([[maybe_unused]] coordinate_t x,
                         [[maybe_unused]] coordinate_t y) {return false;}
};

class DangerDetected : public std::exception {
    const char* what() const throw() {
        return "One of the sensors detected danger";
    }
};

class Action {
public:
    virtual void execute(position_t &pos, position_t &dir, const std::vector<std::unique_ptr<Sensor>> &sensors) = 0;
    virtual ~Action() = default;
};

class MoveForwardAction : public Action {
private:
    
public:
    MoveForwardAction() {}
    void execute(position_t &pos, position_t &dir, const std::vector<std::unique_ptr<Sensor>> &sensors) override {
        for(auto &sensor : sensors) {
            if(!sensor->is_safe(pos.first + dir.first, pos.second + dir.second)) 
                throw DangerDetected();
        }
        pos.first += dir.first;
        pos.second += dir.second;
    }

     ~MoveForwardAction() override = default;
};

static std::shared_ptr<MoveForwardAction> move_forward() {
    static std::shared_ptr<MoveForwardAction> singleton = std::make_shared<MoveForwardAction>();
    std::shared_ptr<MoveForwardAction> pointer(singleton);
    return pointer;
}

class MoveBackwardAction : public Action {
private:
    
public:
    MoveBackwardAction() {}
    void execute(position_t &pos, position_t &dir, const std::vector<std::unique_ptr<Sensor>> &sensors) override {
        for(auto &sensor : sensors) {
            if(!sensor->is_safe(pos.first + dir.first, pos.second + dir.second)) 
                throw DangerDetected();
        }
        pos.first -= dir.first;
        pos.second -= dir.second;
    }

    ~MoveBackwardAction() override = default;
};

static std::shared_ptr<MoveBackwardAction> move_backward() {
    static std::shared_ptr<MoveBackwardAction> singleton = std::make_shared<MoveBackwardAction>();
    std::shared_ptr<MoveBackwardAction> pointer(singleton);
    return pointer;
}


class RotateLeftAction : public Action {
private:
    
public:
    RotateLeftAction() {}
    void execute(position_t &pos, position_t &dir, const std::vector<std::unique_ptr<Sensor>> &sensors) override {
        if(dir == Direction::EAST) dir = Direction::NORTH;
        else if(dir == Direction::NORTH) dir = Direction::WEST;
        else if(dir == Direction::WEST) dir = Direction::SOUTH;
        else if(dir == Direction::SOUTH) dir = Direction::EAST;
    }

    ~RotateLeftAction() override = default;
};

static std::shared_ptr<RotateLeftAction> rotate_left() {
    static std::shared_ptr<RotateLeftAction> singleton = std::make_shared<RotateLeftAction>();
    std::shared_ptr<RotateLeftAction> pointer(singleton);
    return pointer;
}

class RotateRightAction : public Action {
private:

public:
    RotateRightAction() {}
    void execute(position_t &pos, position_t &dir, const std::vector<std::unique_ptr<Sensor>> &sensors) override {
        if(dir == Direction::EAST) dir = Direction::SOUTH;
        else if(dir == Direction::NORTH) dir = Direction::EAST;
        else if(dir == Direction::WEST) dir = Direction::NORTH;
        else if(dir == Direction::SOUTH) dir = Direction::WEST;
    }

    ~RotateRightAction() override = default;
};

static std::shared_ptr<RotateRightAction> rotate_right() {
    static std::shared_ptr<RotateRightAction> singleton = std::make_shared<RotateRightAction>();
    std::shared_ptr<RotateRightAction> pointer(singleton);
    return pointer;
    // no idea if it'll work
}

class ComposeAction : public Action {
private:
    std::vector<std::shared_ptr<Action>> components;
public:
    ComposeAction(std::initializer_list<std::shared_ptr<Action>> list) : components(list) {}
    void execute(position_t &pos, position_t &dir, const std::vector<std::unique_ptr<Sensor>> &sensors) override {
        for(auto action : components)
            action->execute(pos, dir, sensors);
    }

    ~ComposeAction() override = default;
};

inline std::shared_ptr<ComposeAction> compose(std::initializer_list<std::shared_ptr<Action>> list) {
    return std::make_shared<ComposeAction>(list);
}
