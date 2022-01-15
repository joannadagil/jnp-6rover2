#include "Rover.h"


RoverBuilder& RoverBuilder::program_command(const char &id, std::shared_ptr<Action> action) {
    rover.actions_map.insert(std::make_pair(std::move(id),action));
    return *this;
}

std::string get_name_dir(position_t dir) {
    if (dir == Direction::EAST)
        return "EAST";
    else if (dir == Direction::WEST)
        return "WEST";
    else if (dir == Direction::NORTH)
        return "NORTH";
    else
        return "SOUTH";
}
std::ostream& operator<<(std::ostream& os, const Rover& obj) {
    if (!obj.landed)
        return os << "unknown";
    return os << "(" << obj.pos.first << "," << obj.pos.second << ") "
              << get_name_dir(obj.dir) << ((obj.isStopped) ? " stopped" : "");
}

Rover& RoverBuilder::build() {
    return rover;
}

RoverBuilder& RoverBuilder::add_sensor(std::unique_ptr<Sensor> ptr) {
    rover.sensors.push_back(std::move(ptr));
    return *this;
}

void Rover::land(position_t land_pos, position_t direction) {
    pos = land_pos;
    dir = direction;
    landed = true;
}

class LandedExeption : public std::exception {
    const char* what() const throw () {
        return "Rover has not landed yet";
    }
};

class NoSuchAction : public std::exception {
    const char* what() const throw() {
        return "No such action";
    }
};

void Rover::execute(std::string commands) {
    if (!landed)
        throw LandedExeption();

    for (char command : commands) {
        auto res = actions_map.find(command);
        if (res == actions_map.end())
            throw NoSuchAction();
        try {
            res->second->execute(pos, dir, sensors);
            isStopped = false;
        } catch(DangerDetected const& e) {
            isStopped = true;
        }
    }
}

