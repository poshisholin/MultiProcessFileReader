#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include "writer.h"

#include "filereader.h" // Добавляем новый заголовочный файл

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startWriter();
    void stopWriter();
    void startReader(); // Новый слот для запуска чтения
    void stopReader();  // Новый слот для остановки чтения
    void appendNewLine(const QString &line); // Слот для получения новых строк

private:
    Writer *writer; // Процесс записи
    FileReader *fileReader; // Новый класс для чтения из файла
    QTextEdit *textEdit;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *startReadButton; // Кнопка запуска чтения
    QPushButton *stopReadButton;   // Кнопка остановки чтения
};

#endif // MAINWINDOW_H
