#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

    Ui::Widget  *ui;

    QHBoxLayout *_main_layout;
    QHBoxLayout *_left_layout;
    QHBoxLayout *_right_layout;
    QLabel      *_test_label;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

};
#endif // WIDGET_H
