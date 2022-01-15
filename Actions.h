#pragma once
#include <initializer_list>
#include <memory>
using coordinate_t = uint32_t;
using position_t = std::pair<coordinate_t, coordinate_t>;

class Action {
public:
    virtual void execute(position_t &pos, position_t &dir) = 0;
    virtual ~Action() = default;
};

class MoveForwardAction : public Action {
private:
    
public:
    MoveForwardAction() {}
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

static std::shared_ptr<MoveForwardAction> move_forward() {
    static std::shared_ptr<MoveForwardAction> singleton = std::make_shared<MoveForwardAction>();
    std::shared_ptr<MoveForwardAction> pointer(singleton);
    return pointer;
}

class MoveBackwardAction : public Action {
private:
    
public:
    MoveBackwardAction() {}
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

static std::shared_ptr<MoveBackwardAction> move_backward() {
    static std::shared_ptr<MoveBackwardAction> singleton = std::make_shared<MoveBackwardAction>();
    std::shared_ptr<MoveBackwardAction> pointer(singleton);
    return pointer;
}


class RotateLeftAction : public Action {
private:
    
public:
    RotateLeftAction() {}
    void execute(position_t &pos, position_t &dir) override {
    }

    static RotateLeftAction& get_singleton() {
        static RotateLeftAction singleton;
        return singleton;
    }

    ~RotateLeftAction() override = default;
};

static std::shared_ptr<RotateLeftAction> rotate_left() {
    static std::shared_ptr<RotateLeftAction> singleton = std::make_shared<RotateLeftAction>();
    std::shared_ptr<RotateLeftAction> pointer(singleton);
    return pointer;
}

class RotateRightAction : public Action {
private:

public:
    RotateRightAction() {}
    void execute(position_t &pos, position_t &dir) override {
    }

    static RotateRightAction& get_singleton() {
        static RotateRightAction singleton;
        return singleton;
    }

    ~RotateRightAction() override = default;
};

static std::shared_ptr<RotateRightAction> rotate_right() {
    static std::shared_ptr<RotateRightAction> singleton = std::make_shared<RotateRightAction>();
    std::shared_ptr<RotateRightAction> pointer(singleton);
    return pointer;
    // no idea if it'll work
}

class ComposeAction : public Action {
private:

public:
    ComposeAction(std::initializer_list<std::shared_ptr<Action>> list) {}
    void execute(position_t &pos, position_t &dir) override {}

    ~ComposeAction() override = default;
};

inline std::shared_ptr<ComposeAction> compose(std::initializer_list<std::shared_ptr<Action>> list) {
    return std::make_shared<ComposeAction>(list);
}
