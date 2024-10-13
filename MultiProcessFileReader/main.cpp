#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.setWindowTitle("Пошишолин Владимир Андреевич");
    window.show();

    return app.exec();
}
