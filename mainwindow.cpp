#include "mainwindow.h"
//#include "ui_mainwindow.h"


MainWindow::MainWindow(const QString& jsonFilePath,QWidget *parent)
    : QMainWindow(parent),filePath(jsonFilePath)

{
    QWidget *centralWidget = view.createCentralWidget(this);
    setCentralWidget(centralWidget);


   QToolBar *mainToolbar = toolbar.creazioneToolbar(this);
    addToolBar(mainToolbar);

   loadMedia();

    view.aggiornaMediaList(_mediaModel.getTitoliMedia());
    setupConnections();
    resize(800, 500);

}

MainWindow::~MainWindow()
{

};

void MainWindow::setupConnections()
{
    connect(view.getMediaList(), &QListWidget::itemClicked, this, &MainWindow::onMediaSelezionato);
    connect(view.getAggiungiPulsante(), &QPushButton::clicked, this, &MainWindow::onAggiungiMedia);
    connect(view.getbarraRicerca(), &QLineEdit::textChanged, this, &MainWindow::onRicercaChanged);
    connect(view.getModificaPulsante(), &QPushButton::clicked, this, &MainWindow::onModificaMedia);
    connect(view.getRimuoviPulsante(), &QPushButton::clicked, this, &MainWindow::onRimuoviMedia);
    connect(view.getFiltraLibroPulsante(),&QPushButton::clicked, this,[this]() { onFiltroMedia("libro"); });
    connect(view.getFiltraFilmPulsante(),&QPushButton::clicked,this,[this]() { onFiltroMedia("film"); });
    connect(view.getFiltraArticoloPulsante(),&QPushButton::clicked, this, [this]() { onFiltroMedia("articolo"); });
    connect(view.getTogliFiltroPulsante(),&QPushButton::clicked, this, [this]() { onFiltroMedia("togli"); });
    connect(toolbar.getSalvaAction(), &QAction::triggered, this, &MainWindow::onSalvaCliccato);
    connect(toolbar.getSalvaAltroAction(), &QAction::triggered, this, &MainWindow::onSalvaAltroCliccato);
    connect(toolbar.getApriAction(), &QAction::triggered, this, &MainWindow::onApriCliccato);
    }

void MainWindow::onMediaSelezionato(QListWidgetItem* item) {
   QString titoloSelezionato = item->text();
   Media* mediaSelezionato = nullptr;
   for (Media* media : _mediaModel.getMediaCollezione()) {
       if (QString::fromStdString(media->getTitolo()) == titoloSelezionato) {
           mediaSelezionato = media;
           break;
       }
   }
   if (mediaSelezionato) {
       QString dettagli = QString::fromStdString(_mediaModel.getDettagliMedia(mediaSelezionato->getCodiceUnivoco()));
///UBUNTU NON SERVE
       QDir dir(QDir::currentPath());
       dir.cdUp();
       dir.cdUp();
       QString percorsoCompleto = dir.absoluteFilePath(QString::fromStdString(mediaSelezionato->getPercorsoImmagine()));

       view.mostraDettagliMedia(dettagli, percorsoCompleto);
   } else {
       view.mostraDettagliMedia("Media non trovato nella collezione.", "");
   }

}

void MainWindow::loadMedia() {
    _mediaModel.caricaFile(filePath.toStdString());
}


void MainWindow::onAggiungiMedia() {

    AggiungiMediaDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString tipoMedia = dialog.getTipoMedia();
        QString titolo = dialog.getTitolo();
        int anno = dialog.getAnno();
        QString descrizione = dialog.getDescrizione();
        QString immagine = dialog.getPercorsoImmagine();

        Media* nuovoMedia = nullptr;
        if (tipoMedia == "libro") {
            nuovoMedia = new Libro(_mediaModel.getNuovoCodiceUnivoco(), titolo.toStdString(), anno, descrizione.toStdString(), immagine.toStdString(),
                                   dialog.getISBN().toStdString(), dialog.getAutore().toStdString(), dialog.getNumeroPagine(), dialog.getGenere().toStdString(), dialog.getEditore().toStdString());
        }
        else if (tipoMedia == "film") {
            nuovoMedia = new Film(_mediaModel.getNuovoCodiceUnivoco(), titolo.toStdString(), anno, descrizione.toStdString(), immagine.toStdString(),
                                  dialog.getDurata(), dialog.getRegista().toStdString(), dialog.getProduzione().toStdString(), dialog.getGenere().toStdString(), dialog.getLingua().toStdString());
        }
        else if (tipoMedia == "articolo") {
            nuovoMedia = new RivisteArticoli(_mediaModel.getNuovoCodiceUnivoco(),titolo.toStdString(),anno,descrizione.toStdString(),immagine.toStdString(),
                                             dialog.getAutore().toStdString(),dialog.getRivista().toStdString(),dialog.getNumeroRivista(),dialog.getDataPubblicazione().toStdString() );   }

        if (nuovoMedia) {
            _mediaModel.aggiungiMedia(nuovoMedia);
            view.aggiornaMediaList(_mediaModel.getTitoliMedia());
        }
    }
}



void MainWindow::onModificaMedia()
{
    QListWidgetItem* itemSelezionato = view.getMediaList()->currentItem();
    if(itemSelezionato!=nullptr){
        QString titoloSelezionato = itemSelezionato->text();
        unsigned int codiceUnivoco = _mediaModel.getCodicePerTitolo(titoloSelezionato.toStdString());
        Media* mediaDaModificare = _mediaModel.cercaMedia(codiceUnivoco);
        std::string tipo;
        if (dynamic_cast<Libro*>(mediaDaModificare)) {
            tipo="libro";
        } else if (dynamic_cast<Film*>(mediaDaModificare)) {
            tipo="film";
        } else if (dynamic_cast<RivisteArticoli*>(mediaDaModificare)){
            tipo="articolo";
        }

        ModificaMediaDialog dialog(tipo, this);

        dialog.setTitolo(QString::fromStdString(mediaDaModificare->getTitolo()));
        dialog.setAnno(mediaDaModificare->getAnnoPubblicazione());
        dialog.setDescrizione(QString::fromStdString(mediaDaModificare->getDescrizione()));
        if (auto* libro = dynamic_cast<Libro*>(mediaDaModificare)) {
            dialog.setAutore(QString::fromStdString(libro->getAutore()));
            dialog.setNumeroPagine(libro->getNumeroPagine());
            dialog.setGenere(QString::fromStdString(libro->getGenere()));
            dialog.setEditore(QString::fromStdString(libro->getEditore()));

        } else if (auto* film = dynamic_cast<Film*>(mediaDaModificare)) {
            dialog.setDurata(film->getDurata());
            dialog.setLingua(QString::fromStdString(film->getLingua()));
            dialog.setGenere(QString::fromStdString(film->getGenere()));
            dialog.setRegista(QString::fromStdString(film->getRegista()));
            dialog.setProduzione(QString::fromStdString(film->getProduzioneCinematografica()));

        } else if (auto* articolo = dynamic_cast<RivisteArticoli*>(mediaDaModificare)){
            dialog.setAutore(QString::fromStdString(articolo->getAutore()));
            dialog.setRivista(QString::fromStdString(articolo->getRivista()));
            dialog.setNumeroRivista((articolo->getNumeroRivista()));
            dialog.setDataPubblicazione(QString::fromStdString(articolo->getDataPubblicazione()));

        }

        if (dialog.exec() == QDialog::Accepted) {
            mediaDaModificare->setTitolo(dialog.getTitolo().toStdString());
            mediaDaModificare->setAnnoPubblicazione(dialog.getAnno());
            mediaDaModificare->setDescrizione(dialog.getDescrizione().toStdString());
            if (auto* libro = dynamic_cast<Libro*>(mediaDaModificare)) {
                libro->setAutore(dialog.getAutore().toStdString());
                libro->setNumeroPagine(dialog.getNumeroPagine());
                libro->setGenere(dialog.getGenere().toStdString());
                libro->setEditore(dialog.getEditore().toStdString());
            } else if (auto* film = dynamic_cast<Film*>(mediaDaModificare)) {
                film->setRegista(dialog.getRegista().toStdString());
                film->setProduzioneCinematografica(dialog.getProduzione().toStdString());
                film->setLingua(dialog.getLingua().toStdString());
                film->setGenere(dialog.getGenere().toStdString());
                film->setDurata(dialog.getDurata());
            } else if (auto* articolo = dynamic_cast<RivisteArticoli*>(mediaDaModificare)) {
                articolo->setAutore(dialog.getAutore().toStdString());
                articolo->setRivista(dialog.getRivista().toStdString());
                articolo->setNumeroRivista(dialog.getNumeroRivista());
                articolo->setDataPubblicazione(dialog.getDataPubblicazione().toStdString());
            }
        }
        view.aggiornaMediaList(_mediaModel.getTitoliMedia());

    }else{
        view.mostraDettagliMedia("Modifica non eseguito, seleziona un media.");
    }

}

void MainWindow::onRicercaChanged(const QString& text){
    std::vector<std::string>  ricercafiltroMedia;
     std::string ricercaTesto = text.toStdString();
    for (char &c : ricercaTesto) {
        c = std::tolower(c);
    }
    for (Media* media : _mediaModel.getMediaCollezione()) {

        std::string titolo = media->getTitolo();
        for (char &c : titolo) {
            c = std::tolower(c);
        }
        if (titolo.find(ricercaTesto) != std::string::npos ) {
            ricercafiltroMedia.push_back(titolo);
        }
    }
    view.aggiornaMediaList(ricercafiltroMedia);
}


void MainWindow::onFiltroMedia(const QString& tipo) {
    std::string tipoStr = tipo.toStdString();
    if(tipoStr!="togli"){
        std::vector<std::string> titoliFiltrati = _mediaModel.filtraMedia(tipoStr);
        view.aggiornaMediaList(titoliFiltrati);
    }else{
        view.aggiornaMediaList(_mediaModel.getTitoliMedia());
    }

}



void MainWindow::onRimuoviMedia()
{
     QListWidgetItem* itemSelezionato = view.getMediaList()->currentItem();
    if(itemSelezionato!=nullptr){
         QString titoloSelezionato = itemSelezionato->text();
         _mediaModel.eliminaMedia(_mediaModel.getCodicePerTitolo(titoloSelezionato.toStdString()));
         view.aggiornaMediaList(_mediaModel.getTitoliMedia());
    }else{
        view.mostraDettagliMedia("Rimuovi non eseguito, seleziona un media.");
    }


}

void MainWindow::onSalvaCliccato(){
     _mediaModel.salvaFile(filePath.toStdString());
}

void MainWindow::onSalvaAltroCliccato(){
    QDir directory(QDir::currentPath());
      //in ubuntu non serve CDUP
    directory.cdUp();
    directory.cdUp();
    directory.cd("database");


    filePath = QFileDialog::getSaveFileName(this, "Salva File",  directory.absolutePath(), "JSON Files (*.json);;All Files (*)");
    if (!filePath.isEmpty()) {
        _mediaModel.salvaFile(filePath.toStdString());
    }
}

void MainWindow::onApriCliccato(){
    QDir directory(QDir::currentPath());
      //in ubuntu non serve CDUP
    directory.cdUp();
    directory.cdUp();
    directory.cd("database");


    QString fileName = QFileDialog::getOpenFileName(this, "Seleziona un file JSON",  directory.absolutePath(), "File JSON (*.json)");
    if (!fileName.isEmpty()) {
        filePath = fileName;
        _mediaModel.caricaFile(filePath.toStdString());
        view.aggiornaMediaList(_mediaModel.getTitoliMedia());
    }
}

