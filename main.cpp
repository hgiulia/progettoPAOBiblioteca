#include "mainwindow.h"

#include <QApplication>
#include <QDir>



int main(int argc, char *argv[])
{


     //in ubuntu non serve CDUP
    QString appDirPath = QDir::currentPath();
    QDir projectDir(appDirPath);
    //in ubuntu non serve CDUP
    projectDir.cdUp();
    projectDir.cdUp();

    QString filePath = projectDir.absoluteFilePath("database/database.json");

   // QString filePath="database/database.json";
    QApplication a(argc, argv);
    MainWindow mainWindow(filePath);
    mainWindow.show();
    return a.exec();

}
