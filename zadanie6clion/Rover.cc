#include "Rover.h"

RoverBuilder Rover::create() { return RoverBuilder{}; }

RoverBuilder& RoverBuilder::program_command(const char &id, Action action) {
    return *this;
}

