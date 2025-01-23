#ifndef CREAVIEW_H
#define CREAVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSplitter>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QLabel>



class CreaView
{
private:


    QVBoxLayout *layoutPrincipale;
    QHBoxLayout *barraRicercaLayout;
    QSplitter *splitter;
    QVBoxLayout *leftPanel;
    QVBoxLayout *rightPanel;

    QLineEdit *barraRicerca;
    QPushButton *aggiungiPulsante;
    QListWidget *mediaList;
    QLabel *mediaDetails;
    QPushButton *modificaPulsante;
    QPushButton *rimuoviPulsante;

    QLabel *immagineLabel;

    QHBoxLayout *filtriMediaLayout;
    QLabel *filtroLabel;
    QPushButton *filtraLibroButton;
    QPushButton *filtraFilmButton;
    QPushButton *filtraArticoloButton;
    QPushButton *togliFiltroPulsante;



public:
    CreaView();
    ~CreaView();

    QWidget* createCentralWidget(QWidget *parent = nullptr);


    QLineEdit* getbarraRicerca() const;
    QPushButton* getAggiungiPulsante() const;
    QListWidget* getMediaList() const;
    QPushButton* getModificaPulsante() const;
    QPushButton* getRimuoviPulsante() const;
    QLabel* getMediaDetails() const;


    QPushButton* getFiltraLibroPulsante() const;

    QPushButton* getFiltraFilmPulsante() const;
    QPushButton* getFiltraArticoloPulsante() const;
    QPushButton* getTogliFiltroPulsante() const;

    void aggiornaMediaList(const std::vector<std::string>& titoli);
    void mostraDettagliMedia(const QString& dettagli, const QString & percorsoImmagine=nullptr);

};

#endif
