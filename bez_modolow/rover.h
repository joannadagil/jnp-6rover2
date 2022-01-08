#ifndef ROVER_H
#define ROVER_H
#include "operation.h"
#include <vector>

using coordinate_t = uint32_t;

namespace Direction {
    std::pair<coordinate_t, coordinate_t> WEST = std::make_pair(-1,0);
    std::pair<coordinate_t, coordinate_t> EAST = std::make_pair(1,0);
    std::pair<coordinate_t, coordinate_t> NORTH = std::make_pair(0,1);
    std::pair<coordinate_t, coordinate_t> SOUTH = std::make_pair(0,-1);
}

struct Sensor {
    virtual bool is_safe([[maybe_unused]] coordinate_t x,
                 [[maybe_unused]] coordinate_t y);
};

class RoverBuilder {

    coordinate_t x,y;

    public:
        RoverBuilder& program_command(std::string name,) {
            return *this;
        }

        RoverBuilder& build() {
            return *this;
        }

};


#endif