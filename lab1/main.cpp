#include "widget.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QLabel label("TEXT");
    QPushButton newbutton("MyButton"); // Об’явлення кнопки
    QLineEdit textedit; // Поле для введення тексту
    QHBoxLayout layout(&w); // Об’явлення контейнеру
    layout.addWidget(&label); // Додавання вiджетiв у контейнер
    layout.addWidget(&newbutton);
    layout.addWidget(&textedit);
    w.resize(600, 350);
    w.show();
    QPushButton *button = new QPushButton("Press me", &w);
    button->move(100, 250);
    button->show();
    w.setWindowTitle("MyWindow");
    return a.exec();
}
