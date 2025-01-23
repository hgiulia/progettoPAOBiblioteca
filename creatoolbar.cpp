#include "creatoolbar.h"

CreaToolBar::CreaToolBar() : salvaAction(nullptr), apriAction(nullptr) {}

QToolBar* CreaToolBar::creazioneToolbar(QObject *parent) {
    QToolBar *toolbar = new QToolBar("Toolbar", static_cast<QWidget*>(parent));

    salvaAction = new QAction("Salva File", toolbar);
    toolbar->addAction(salvaAction);
    apriAction = new QAction("Apri File", toolbar);
    toolbar->addAction(apriAction);

    salvaAltroAction = new QAction("Salva come File", toolbar);
    toolbar->addAction(salvaAltroAction);

    return toolbar;
}

QAction* CreaToolBar::getSalvaAction() const {return salvaAction;}

QAction* CreaToolBar::getApriAction() const {return apriAction;}

QAction* CreaToolBar::getSalvaAltroAction() const {return salvaAltroAction;}
