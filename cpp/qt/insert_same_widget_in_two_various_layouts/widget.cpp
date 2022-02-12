#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , _main_layout ( new QHBoxLayout(this) )
    , _test_label  ( new QLabel      (this) )
    , _left_layout ( new QHBoxLayout )
    , _right_layout( new QHBoxLayout )
{

    _test_label->setText("hello");

    _left_layout->addWidget ( _test_label   );
    _right_layout->addWidget( _test_label   );
    _main_layout->addLayout ( _left_layout  );
    _main_layout->addLayout ( _right_layout );
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
    delete  _right_layout;
    delete  _left_layout;
}

