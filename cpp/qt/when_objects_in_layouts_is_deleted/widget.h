#ifndef WIDGET_H
#define WIDGET_H

#include <iostream>
#include <QHBoxLayout>
#include <string>
#include <QLabel>

#include <QWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class My_layout : public QHBoxLayout
{
    std::string _msg;
public:

    My_layout( const std::string &msg ) : QHBoxLayout(), _msg(msg)
    {

        std::cout << "My layout constructor " << _msg << std::endl;
    }

    My_layout( QWidget *ptr, const std::string &msg ) : QHBoxLayout(ptr),
                                                        _msg(msg)
    {
        std::cout << "My layout constructor " << _msg << std::endl;
    }

    ~My_layout()
    {
        std::cout << "My layout destructor " << _msg << std::endl;
    }

};

class My_label : public QLabel
{
public:
    std::string _msg;

    My_label( const std::string &msg ) : QLabel(), _msg(msg)
    {
       std::cout << "My label constructor " << _msg << std::endl;
    }

    My_label( QWidget *ptr, const std::string &msg ) : QLabel(ptr), _msg(msg)
    {
        std::cout << "My label constructor " << _msg << std::endl;
    }

    ~My_label()
    {
        std::cout << "My label destructor " << _msg << std::endl;
    }
};


class Widget : public QWidget
{
    Q_OBJECT

    Ui::Widget *ui;

    My_label  *_my_label;
    My_layout *_my_layout;
    My_layout *_test_layout;

public:
    Widget( QWidget *parent = nullptr );
    ~Widget();

};




#endif // WIDGET_H
