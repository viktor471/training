#include <iostream>

using namespace std;

class Machine
{
    class State *current;
public:
    Machine();
    void setCurrent(State *s)
    {
        current = s;
    }
    void on();
    void off();
};

class State
{
public:
    virtual void on(Machine *m)
    {
        cout << "   already ON" << endl;
    }

    virtual void off(Machine *m)
    {
        cout << "   already OFF" << endl;
    }
};

void Machine::on()
{
    current->on(this);
}

void Machine::off()
{
    current->off(this);
}

class ON : public State
{
public:
    ON()
    {
        cout << "     ON-ctor" << endl;
    }
    ~ON()
    {
        cout << "     dtor-ON" << endl;
    }
    void off(Machine *m);
};

class OFF: public State
{
public:
    OFF()
    {
        cout << "    OFF-ctor" << endl;
    }
    ~OFF()
    {
        cout << "    dtor-OFF" << endl;
    }
    void on(Machine *m)
    {
        cout << "   going from OFF to ON";
        m->setCurrent(new ON());
        delete this;
    }
};

void ON::off(Machine *m)
{
    cout << "    going from ON to OFF";
    m->setCurrent(new OFF());
    cout << '\n';
}

Machine::Machine()
{
    current = new OFF();
    cout << '\n';
}

int main()
{
    void(Machine::*ptrs[2])();
    ptrs[0] = &Machine::off;
    ptrs[1] = &Machine::on;
    Machine fsm;
    int num;
    while (1)
    {
        cout << "Enter 0/1: ";
        cin >> num;
        (fsm.*ptrs[num])();
        if(num == 2) break;
    }

    return 0;
}
