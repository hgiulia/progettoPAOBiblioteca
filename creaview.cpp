#include "creaview.h"


CreaView::CreaView() : layoutPrincipale(nullptr), splitter(nullptr), leftPanel(nullptr), rightPanel(nullptr) {}

CreaView::~CreaView() {}

QWidget* CreaView::createCentralWidget(QWidget *parent)
{
    QWidget *centralWidget = new QWidget(parent);
    layoutPrincipale = new QVBoxLayout();

    barraRicercaLayout = new QHBoxLayout();
    barraRicerca = new QLineEdit();
    barraRicercaLayout->addWidget(new QLabel("Ricerca media: "));
    barraRicerca->setPlaceholderText("Ricerca media per titolo, inserisci il titolo");
    barraRicercaLayout->addWidget(barraRicerca);
    layoutPrincipale->addLayout(barraRicercaLayout);

    splitter = new QSplitter(Qt::Horizontal);

    leftPanel = new QVBoxLayout();
    aggiungiPulsante = new QPushButton("Aggiungi un media");
    leftPanel->addWidget(aggiungiPulsante);
    mediaList = new QListWidget();
    leftPanel->addWidget(mediaList);

    filtriMediaLayout = new QHBoxLayout();
    filtroLabel = new QLabel("Filtra per:");
    filtriMediaLayout->addWidget(filtroLabel);
    filtraLibroButton = new QPushButton("Libro");
    filtriMediaLayout->addWidget(filtraLibroButton);
    filtraFilmButton = new QPushButton("Film");
    filtriMediaLayout->addWidget(filtraFilmButton);
    filtraArticoloButton = new QPushButton("Articolo");
    filtriMediaLayout->addWidget(filtraArticoloButton);
    leftPanel->addLayout(filtriMediaLayout);

    togliFiltroPulsante = new QPushButton("Togli Filtro");
    filtriMediaLayout ->addWidget(togliFiltroPulsante);

    QWidget *leftWidget = new QWidget();
    leftWidget->setLayout(leftPanel);
    splitter->addWidget(leftWidget);

    //parte destra per descrizione libro
    rightPanel = new QVBoxLayout();

    immagineLabel = new QLabel();
    immagineLabel->setAlignment(Qt::AlignCenter);
    immagineLabel->setFixedSize(300, 200);
    rightPanel->addWidget(immagineLabel);

    mediaDetails = new QLabel("Selezione una media per visualizzare i dettagli.");
    mediaDetails->setWordWrap(true);
    rightPanel->addWidget(mediaDetails);

    modificaPulsante = new QPushButton("Modifica");
    rightPanel->addWidget(modificaPulsante);
    rimuoviPulsante = new QPushButton("Rimuovi");
    rightPanel->addWidget(rimuoviPulsante);

    QWidget *rightWidget = new QWidget();
    rightWidget->setLayout(rightPanel);
    splitter->addWidget(rightWidget);

    leftWidget->setMinimumWidth(300);
    rightWidget->setMinimumWidth(400);



    layoutPrincipale->addWidget(splitter);
    centralWidget->setLayout(layoutPrincipale);



    return centralWidget;
}



void CreaView::mostraDettagliMedia(const QString& dettagli,  const QString& percorsoImmagine) {
    if(dettagli ==""){
        immagineLabel->clear();
    }else{
        if (!percorsoImmagine.isEmpty()) {
            QPixmap immagine(percorsoImmagine);
            if (!immagine.isNull()) {
                immagine = immagine.scaled(120, 180, Qt::KeepAspectRatio);
                immagineLabel->setPixmap(immagine);
            } else {
                immagineLabel->clear();
                immagineLabel->setText("Immagine non trovata o non valida");
            }
        }
    }
     mediaDetails->setText(dettagli);
}

void CreaView::aggiornaMediaList(const std::vector<std::string>& titoli) {
    mediaList->clear();
    for (const auto& titolo : titoli) {
        mediaList->addItem(QString::fromStdString(titolo));
    }
    mediaList->clearSelection();
    mostraDettagliMedia("");
}


QLineEdit* CreaView::getbarraRicerca() const { return barraRicerca; }
QPushButton* CreaView::getAggiungiPulsante() const { return aggiungiPulsante; }
QListWidget* CreaView::getMediaList() const { return mediaList; }
QPushButton* CreaView::getModificaPulsante() const { return modificaPulsante; }
QPushButton* CreaView::getRimuoviPulsante() const { return rimuoviPulsante; }
QLabel* CreaView::getMediaDetails() const { return mediaDetails; }
QPushButton* CreaView::getFiltraLibroPulsante() const{return filtraLibroButton;}
QPushButton* CreaView::getFiltraFilmPulsante() const{return filtraFilmButton;}
QPushButton* CreaView::getFiltraArticoloPulsante() const{return filtraArticoloButton;}
QPushButton* CreaView::getTogliFiltroPulsante()const { return togliFiltroPulsante;}
