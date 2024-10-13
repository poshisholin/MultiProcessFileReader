#ifndef FILEREADER_H
#define FILEREADER_H

#include <QObject>
#include <QFile>
#include <QTimer>
#include <QTextStream>

class FileReader : public QObject {
    Q_OBJECT

public:
    explicit FileReader(QObject *parent = nullptr);
    void startReading();
    void stopReading();

signals:
    void newLine(const QString &line);

private slots:
    void readLine();

private:
    QFile file; // Файл для чтения
    QTimer *timer;
};

#endif // FILEREADER_H
