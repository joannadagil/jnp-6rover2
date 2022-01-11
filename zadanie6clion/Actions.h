#pragma once
#include <initializer_list>

class Action {
    virtual void execute();
};

class MoveForwardAction : public Action{
    void execute() {}
};

class MoveBackWardAction : public Action{
    void execute() {}
};

class RotateLeftAction : public Action{
    void execute() {}
};

class RotateRightAction : public Action{
    void execute() {}
};

class ComposeAction : public Action{
    ComposeAction(std::initializer_list<Action> list) {

    }
    void execute() {}
};

MoveForwardAction move_forward() {
    return MoveForwardAction();
}

MoveBackWardAction move_backward() {
    return MoveBackWardAction();
}

RotateLeftAction rotate_left() {
    return RotateLeftAction();
}

RotateRightAction rotate_right() {
    return RotateRightAction();
}

ComposeAction compose(std::initializer_list<Action> list) {
    return ComposeAction(list);
}

