#pragma once
#include <iostream>
#include "Actions.h"
#include <memory>
#include <vector>
#include <unordered_map>

std::string get_name_dir(position_t dir);

class RoverBuilder;

class Rover {
private:
    position_t pos;
    position_t dir;
    bool isStopped;
    std::unordered_map<char,std::shared_ptr<Action>> actions_map;
    std::vector<std::unique_ptr<Sensor>> sensors;
    bool landed;

public:
    Rover(std::unordered_map<char,std::shared_ptr<Action>> actions_map,
          std::vector<std::unique_ptr<Sensor>> sensors) : 
          actions_map(actions_map), sensors(sensors), landed(false), isStopped(false) {}
    friend class RoverBuilder;
    friend std::ostream& operator<<(std::ostream&  os, const Rover& obj);
    void execute(std::string command);
    void land(position_t land_pos, position_t direction);
};

class RoverBuilder {
    std::unordered_map<char,std::shared_ptr<Action>> actions_map;
    std::vector<std::unique_ptr<Sensor>> sensors;
public:
    RoverBuilder() = default;

    RoverBuilder& program_command(const char& id, const std::shared_ptr<Action> action);

    RoverBuilder& add_sensor(std::unique_ptr<Sensor> ptr);

    Rover build();

};
