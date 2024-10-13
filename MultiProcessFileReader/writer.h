#ifndef WRITER_H
#define WRITER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QTimer>

class Writer : public QObject {
    Q_OBJECT

public:
    explicit Writer(const QString &filePath, QObject *parent = nullptr);
    void startWriting();
    void stopWriting();

private:
    void openFile();
    void writeLine();

    QFile file;
    QTextStream *out;
    QTimer *timer;
    int counter;
    QString filePath;
};

#endif // WRITER_H
