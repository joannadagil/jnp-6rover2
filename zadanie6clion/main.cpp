#include <iostream>
#include "Rover.h"
#include "RoverBuilder.h"
using namespace std;
int main() {
    Rover p = Rover::create().program_command('a');
    Rover q = RoverBuilder().program_command('a');
    return 0;
}
