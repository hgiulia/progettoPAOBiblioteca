#ifndef CREATOOLBAR_H
#define CREATOOLBAR_H

#include <QToolBar>
#include <QObject>
#include <QFileDialog>


class CreaToolBar
{
public:
    CreaToolBar();
    QToolBar* creazioneToolbar(QObject *parent);

    QAction* getSalvaAction() const;
    QAction* getApriAction() const;
    QAction* getSalvaAltroAction () const;

private:
    QAction* salvaAction;
    QAction* apriAction;
    QAction* salvaAltroAction;
};

#endif
