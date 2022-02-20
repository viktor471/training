#include <iostream>

class container
{
    std::string data;
    container *prev;
    container *next;
public:
    container(std::string _data = ""){
       data = _data;
    }

    void add_next(std::string _data = ""){
        next = new container(_data);
        next->prev = this;
    }
    container* get_next(){ return next; }
    container* get_prev(){ return prev; }
    std::string getData(){ return data; }

};

int main()
{
    using namespace std;
    container ex;
    ex.add_next("hello");
    ex.get_next()->add_next("world");

    container &ref = ex;

    ref.get_next()->get_next()->add_next(" !!!!");

    cout << ref.getData()                                     << " " <<
            ref.get_next()->getData()                         << " " <<
            ref.get_next()->get_next()->getData()             << " " <<
            ref.get_next()->get_next()->get_next()->getData() << " " <<
            endl;

    cout << "sizeof(ref) " << sizeof(ref) << endl;
}
