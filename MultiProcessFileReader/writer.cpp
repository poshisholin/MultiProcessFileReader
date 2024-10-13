#include "writer.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QTimer>

Writer::Writer(QObject *parent)
    : QObject(parent), counter(0) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Writer::writeLine);

    file.setFileName("output.txt"); // Указываем имя файла
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) { // Проверяем, удалось ли открыть файл
        qDebug() << "Failed to open file for writing.";
        return; // Если файл не открыт, выходим из конструктора
    }
}

void Writer::startWriting() {
    timer->start(3000); // Запуск таймера с интервалом 3 сек
}

void Writer::stopWriting() {
    timer->stop();
    file.close(); // Закрываем файл при остановке
}

void Writer::writeLine() {
    if (!file.isOpen()) { // Проверяем, открыт ли файл
        qDebug() << "File is not open for writing.";
        return;
    }

    QString line = QString("String %1").arg(counter++);
    QTextStream out(&file); // Инициализация QTextStream должна происходить после проверки
    out << line << Qt::endl; // Используем Qt::endl для новой строки
    qDebug() << "Written:" << line;
}
