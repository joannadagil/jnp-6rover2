#ifndef ACTION_H
#define ACTION_H
#include <vector>
#include <initializer_list>

class Action {
    public:
        virtual void execute();

};

class move_forward : Action {

    void execute() {}
};

class move_backward : Action {

    void execute() {}
};

class move_left : Action {

    void execute() {}
};

class move_right : Action {

    void execute() {}
};

class compose : Action {
    private:
        std::vector<Action> actions;
    public:
        compose(std::initializer_list<Action> list) {
            actions.insert(actions.end(),list.begin(),list.end());
        }
    void execute() {
        for (Action action : actions)
    }
};

#endif