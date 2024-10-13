#ifndef WRITER_H
#define WRITER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QTimer>

class Writer : public QObject {
    Q_OBJECT

public:
    explicit Writer(const QString &filePath, QObject *parent = nullptr); // Добавьте новый конструктор
    void startWriting();
    void stopWriting();

private slots:
    void writeLine();
    void openFile(); // Объявите метод openFile

private:
    QFile file;
    QTextStream *out; // Убедитесь, что out объявлен как указатель на QTextStream
    QTimer *timer;
    int counter;
    QString filePath; // Добавьте переменную для хранения пути к файлу
};

#endif // WRITER_H
