#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , _my_label   ( new My_label ( this, ""            ) )
    , _my_layout  ( new My_layout( this, "main_layout" ) )
    , _test_layout( new My_layout(       "test_layout" ) )
{
    _my_label->setText("hello");

    _test_layout -> addWidget( _my_label    );
    _my_layout   -> addLayout( _test_layout );

    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

