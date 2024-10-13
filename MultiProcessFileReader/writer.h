#ifndef WRITER_H
#define WRITER_H

#include <QObject>
#include <QTimer>
#include <QFile>
#include <QTextStream>

class Writer : public QObject {
    Q_OBJECT

public:
    Writer(QObject *parent = nullptr);
    void startWriting();
    void stopWriting();

private slots:
    void writeLine();

private:
    QTimer *timer;
    int counter;
    QFile file; // Файл для записи
};

#endif // WRITER_H
