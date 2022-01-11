#include "Rover.h"


RoverBuilder Rover::create() { return RoverBuilder{}; }

RoverBuilder& RoverBuilder::program_command(const char &id, Action action) {
    // TODO
    // rover.commands.insert(std::pair<std::string, Action>(id, action));
    return *this;
}

