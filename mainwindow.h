#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include "creaview.h"
#include "mediamodel.h"
#include "creatoolbar.h"
#include "modificamediadialog.h"
#include "aggiungimediadialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QString& jsonFilePath,QWidget *parent = nullptr);
    ~MainWindow();

private:

    void setupConnections();

    CreaView view;
    CreaToolBar toolbar;
    mediaModel _mediaModel;
    QString filePath;



private slots:

    void onAggiungiMedia();
    void loadMedia();
    void onRimuoviMedia();
    void onModificaMedia();
    void onMediaSelezionato(QListWidgetItem* item);
    void onFiltroMedia(const QString& tipo);

    void onApriCliccato();
    void onSalvaCliccato();
    void onSalvaAltroCliccato();

    void onRicercaChanged(const QString& text);


};
#endif
