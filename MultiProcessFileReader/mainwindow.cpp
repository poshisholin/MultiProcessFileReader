#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    // Создаем виджеты
    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true); // Поле только для чтения

    startButton = new QPushButton("Запустить запись", this);
    stopButton = new QPushButton("Остановить запись", this);
    startReadButton = new QPushButton("Запустить чтение", this); // Кнопка запуска
    stopReadButton = new QPushButton("Остановить чтение", this); // Кнопка остановки

    // Устанавливаем начальные состояния кнопок
    stopButton->setEnabled(false); // Дизаблим кнопку остановки записи
    stopReadButton->setEnabled(false); // Дизаблим кнопку остановки чтения

    // Создаем компоновку
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(textEdit);
    layout->addWidget(startButton);
    layout->addWidget(stopButton);
    layout->addWidget(startReadButton); // Добавляем кнопку
    layout->addWidget(stopReadButton); // Добавляем кнопку

    // Устанавливаем центральный виджет
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Инициализируем компоненты
    writer = new Writer(); // Процесс записи
    fileReader = new FileReader(); // Процесс чтения

    // Подключаем сигналы и слоты
    connect(fileReader, &FileReader::newLine, this, &MainWindow::appendNewLine);
    connect(startButton, &QPushButton::clicked, this, &MainWindow::startWriter);
    connect(stopButton, &QPushButton::clicked, this, &MainWindow::stopWriter);
    connect(startReadButton, &QPushButton::clicked, this, &MainWindow::startReader); // Подключаем слот запуска чтения
    connect(stopReadButton, &QPushButton::clicked, this, &MainWindow::stopReader); // Подключаем слот остановки чтения
}


MainWindow::~MainWindow() {
    stopWriter();
    stopReader(); // Останавливаем чтение
    delete writer;
    delete fileReader; // Удаляем объект чтения
}

void MainWindow::startWriter() {
    writer->startWriting(); // Запуск записи
    startButton->setEnabled(false); // Дизаблим кнопку запуска записи
    stopButton->setEnabled(true); // Включаем кнопку остановки записи
    startReadButton->setEnabled(false); // Дизаблим кнопку запуска чтения
    stopReadButton->setEnabled(true); // Включаем кнопку остановки чтения
    fileReader->startReading(); // Запуск чтения
}

void MainWindow::stopWriter() {
    writer->stopWriting(); // Остановка записи
    startButton->setEnabled(true); // Включаем кнопку запуска записи
    stopButton->setEnabled(false); // Дизаблим кнопку остановки записи
    startReadButton->setEnabled(true); // Включаем кнопку запуска чтения
    stopReadButton->setEnabled(false); // Дизаблим кнопку остановки чтения
}

void MainWindow::startReader() {
    fileReader->startReading(); // Запуск чтения
    startReadButton->setEnabled(false); // Дизаблим кнопку запуска чтения
    stopReadButton->setEnabled(true); // Включаем кнопку остановки чтения
    startButton->setEnabled(false); // Дизаблим кнопку запуска записи
    stopButton->setEnabled(true); // Включаем кнопку остановки записи
}

void MainWindow::stopReader() {
    fileReader->stopReading(); // Остановка чтения
    startReadButton->setEnabled(true); // Включаем кнопку запуска чтения
    stopReadButton->setEnabled(false); // Дизаблим кнопку остановки чтения
    startButton->setEnabled(false); // Дизаблим кнопку запуска записи
    stopButton->setEnabled(true); // Включаем кнопку остановки записи
}

void MainWindow::appendNewLine(const QString &line) {
    textEdit->append(line); // Добавляем новую строку в QTextEdit
}
