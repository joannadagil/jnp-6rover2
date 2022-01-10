#pragma once
#include <iostream>
using namespace std;

class RoverBuilder;

class Rover
{

    Rover() {}

public:
    friend class RoverBuilder;
    static RoverBuilder create();
};