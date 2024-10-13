#ifndef FILEREADER_H
#define FILEREADER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QTimer>

class FileReader : public QObject {
    Q_OBJECT

public:
    explicit FileReader(QObject *parent = nullptr);
    void startReading();
    void stopReading();

signals:
    void newLine(const QString &line);

private:
    void readLine();

    QFile file;
    QTimer *timer;
};

#endif // FILEREADER_H
