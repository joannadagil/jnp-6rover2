#pragma once
#include <initializer_list>
#include <vector>

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
    std::vector<Action> actions;
    ComposeAction(std::initializer_list<Action> list) : actions(list) {}
    void execute() {
        for(Action action : actions)
            action.execute(); // hmmm, jakoś inaczej
    }
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

