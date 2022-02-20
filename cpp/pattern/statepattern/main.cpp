#include <iostream>
#include <typeinfo>

using namespace std;

class Context;

class State {

protected:
    Context *context_;

public:
    virtual ~State(){
    }

    void set_context(Context *context){
        this->context_ = context;
    }

    virtual void Handle1() = 0;
    virtual void Handle2() = 0;
};


class Context {

private:
    State *state_;

public:
    Context(State *state) : state_(nullptr) {
        this->TransitionTo(state);
    }

    ~Context() {
        delete state_;
    }

    void TransitionTo(State *state) {
        std::cout << "Context: Transition to " << typeid (*state).name() << "." << endl;

        if (this->state_ != nullptr)
            delete this->state_;
        this->state_ = state;
        this->state_->set_context(this);
    }

    void Request1(){
        this->state_->Handle1();
    }

    void Request2(){
        this->state_->Handle2();
    }

};

class ConcreteStateA : public State {
public:
    void Handle1() override;

};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
