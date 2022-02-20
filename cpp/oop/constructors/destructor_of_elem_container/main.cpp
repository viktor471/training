#include <QCoreApplication>
#include <QHash>
#include <iostream>
class inCl{
public:
    inCl() { std::cout << " inCl constructor" << std::endl; }
    ~inCl(){ std::cout << " inCl destructor"  << std::endl; }
};

class cl{
    int i;
    int b;
    inCl c;
public:
    void setI(int _i){ i = _i; }
    void setB(int _b){ b = _b; }
    cl() {
        std::cout <<  "cl constructor"<< std::endl;
    }

    ~cl(){
        std::cout << "cl destructor" << std::endl;
    }
};

void func(QHash<int, cl> &qh){
   cl a;
   a.setB(2);
   a.setI(55);

   qh.insert(1, a);
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHash<int, cl> qh;
    func(qh);
    std::cout << "qh.clear() " << std::endl;

    return a.exec();
}
