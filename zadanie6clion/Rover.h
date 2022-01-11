#pragma once
#include <iostream>
#include "Actions.h"
#include <memory>
#include <vector>

using coordinate_t = uint32_t;

namespace Direction {
    std::pair<coordinate_t, coordinate_t> WEST;
    std::pair<coordinate_t, coordinate_t> NORTH;
    std::pair<coordinate_t, coordinate_t> EAST;
    std::pair<coordinate_t, coordinate_t> SOUTH;
}

class Sensor {
    virtual bool is_safe([[maybe_unused]] coordinate_t x,
                 [[maybe_unused]] coordinate_t y);
};

class RoverBuilder;

class Rover {
    Rover() = default;

public:
    friend class RoverBuilder;
    static RoverBuilder create();
};

class RoverBuilder {
    Rover rover;
public:
    RoverBuilder() = default;

    operator Rover() const { return std::move(rover); }
    friend std::ostream& operator<<(std::ostream&  os, const Rover& obj);

    RoverBuilder& program_command(const char& id, Action action);

    RoverBuilder& add_sensor(std::unique_ptr<Sensor> ptr);

    RoverBuilder& build();

    void execute(std::string command);
};
