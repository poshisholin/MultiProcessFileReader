#include "writer.h"
#include <QDebug>

Writer::Writer(const QString &filePath, QObject *parent)
    : QObject(parent), counter(0), filePath(filePath) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Writer::writeLine);
    openFile(); // Открываем файл при инициализации
}

void Writer::openFile() {
    if (!file.isOpen()) {
        file.setFileName(filePath); // Указываем имя файла
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
            qDebug() << "Cannot open file for writing:" << file.errorString();
        } else {
            out = new QTextStream(&file);
        }
    }
}

void Writer::startWriting() {
    openFile(); // Убедитесь, что файл открыт перед записью
    timer->start(3000); // Запуск таймера с интервалом 3 сек
}

void Writer::stopWriting() {
    timer->stop();
    if (file.isOpen()) {
        file.close(); // Закрываем файл при остановке
    }
}

void Writer::writeLine() {
    QString line = QString("String %1").arg(counter++);
    *out << line << "\n";
    out->flush();
    qDebug() << "Written:" << line;
}
