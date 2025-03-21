#include <QApplication>
#include <QIcon>
#include "DiffAlgoEval.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow mainWindow;
    Ui::MainWindow ui;

    ui.setupUi(&mainWindow);

    mainWindow.setWindowTitle("DiffAlgoEval");
    mainWindow.setStyleSheet("background-color: #f0f0f0;"); // Set a light background color
    mainWindow.setAttribute(Qt::WA_DeleteOnClose); // Ensure the window is deleted when closed
    mainWindow.show();

    return app.exec();
}