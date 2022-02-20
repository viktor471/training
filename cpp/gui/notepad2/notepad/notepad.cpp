#include "notepad.h"
#include "ui_notepad.h"

notepad::notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::notepad)
{
    ui->setupUi(this);
}

notepad::~notepad()
{
    connect(ui->actionNew, &QAction::triggered, this, &notepad::newDocument);
    delete ui;
}

void notepad::newDocument()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}

/*void notepad::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile File(fileName);
    currentFile = fi
}*/
