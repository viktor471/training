#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class notepad; }
QT_END_NAMESPACE

class notepad : public QMainWindow
{
    Q_OBJECT

public:
    notepad(QWidget *parent = nullptr);
    ~notepad();

private:
    Ui::notepad *ui;
    QString currentFile;
private slots:
    void newDocument();
};
#endif // NOTEPAD_H
