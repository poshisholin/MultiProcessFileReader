#include "filereader.h"
#include <QDebug>

FileReader::FileReader(QObject *parent) : QObject(parent) {
    file.setFileName("output.txt"); // Указываем имя файла
    file.open(QIODevice::ReadOnly | QIODevice::Text); // Открываем файл на чтение
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &FileReader::readLine);
}

void FileReader::startReading() {
    timer->start(1000); // Запускаем чтение каждые 1 сек
}

void FileReader::stopReading() {
    timer->stop();
}

void FileReader::readLine() {
    if (file.isOpen() && !file.atEnd()) {
        QTextStream in(&file);
        QString line = in.readLine();
        emit newLine(line); // Генерируем сигнал с новой строкой
        qDebug() << "Read:" << line;
    }
}
