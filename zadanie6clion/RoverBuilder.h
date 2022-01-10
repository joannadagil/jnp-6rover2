#pragma once
#include "Rover.h"

class RoverBuilder
{
    Rover rover;

public:
    RoverBuilder() {
        rover = Rover();
    }

    operator Rover() const { return move(rover); }

    RoverBuilder& program_command(const char& id);

};