export module rover;

import <string>;

export class RoverBuilder {
    RoverBuilder& program_command(std::string name,int a) {
       return *this;
    }

    RoverBuilder& build() {
        return *this;
    }

};