#pragma once
#include <initializer_list>
using coordinate_t = uint32_t;
using position_t = std::pair<coordinate_t, coordinate_t>;

class Action {
public:
    virtual void execute(position_t &pos, position_t &dir) = 0;
    virtual ~Action() = default;
};

class MoveForwardAction : public Action {
private:
    MoveForwardAction() {}
public:
    void execute(position_t &pos, position_t &dir) override {
        pos.first += dir.first;
        pos.second += pos.second;
    }

    static MoveForwardAction& get_singleton() {
        static MoveForwardAction singleton;
        return singleton;
    }

     ~MoveForwardAction() override = default;
};

static MoveForwardAction* move_forward() {
    return &MoveForwardAction::get_singleton();
}

class MoveBackwardAction : public Action {
private:
    MoveBackwardAction() {}
public:
    void execute(position_t &pos, position_t &dir) override {
        pos.first -= dir.first;
        pos.second -= pos.second;
    }

    static MoveBackwardAction& get_singleton() {
        static MoveBackwardAction singleton;
        return singleton;
    }

    ~MoveBackwardAction() override = default;
};

static MoveBackwardAction* move_backward() {
    return &MoveBackwardAction::get_singleton();
}

class RotateLeftAction : public Action {
private:
    RotateLeftAction() {}
public:
    void execute(position_t &pos, position_t &dir) override {
    }

    static RotateLeftAction& get_singleton() {
        static RotateLeftAction singleton;
        return singleton;
    }

    ~RotateLeftAction() override = default;
};

static RotateLeftAction* rotate_left() {
    return &RotateLeftAction::get_singleton();
}

class RotateRightAction : public Action {
private:
    RotateRightAction() {}
public:
    void execute(position_t &pos, position_t &dir) override {
    }

    static RotateRightAction& get_singleton() {
        static RotateRightAction singleton;
        return singleton;
    }

    ~RotateRightAction() override = default;
};

static RotateRightAction* rotate_right() {
    return &RotateRightAction::get_singleton();
}

class ComposeAction : public Action {
private:

public:
    ComposeAction(std::initializer_list<Action*> list) {}
    void execute(position_t &pos, position_t &dir) override {}

    ~ComposeAction() override = default;
};

ComposeAction compose(std::initializer_list<Action*> list) {
    return ComposeAction(list);
}
