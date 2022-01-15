#pragma once
#include <iostream>
#include "Actions.h"
#include <memory>
#include <vector>
#include <unordered_map>

std::string get_name_dir(position_t dir);

struct Sensor {
    virtual bool is_safe([[maybe_unused]] coordinate_t x,
                         [[maybe_unused]] coordinate_t y) {return false;}
};

class RoverBuilder;

class Rover {
private:
    position_t pos;
    position_t dir;
    std::unordered_map<char,std::shared_ptr<Action>> actions_map;
    bool landed;

public:
    Rover() : landed(false) {}
    friend class RoverBuilder;
    friend std::ostream& operator<<(std::ostream&  os, const Rover& obj);
    void execute(std::string command);
    void land(position_t land_pos, position_t direction);
};

class RoverBuilder {
    Rover rover;
public:
    RoverBuilder() = default;

    operator Rover() const { return std::move(rover); }

    RoverBuilder& program_command(const char& id,const std::shared_ptr<Action> action);

    RoverBuilder& add_sensor(std::unique_ptr<Sensor> ptr);

    Rover& build();


};
