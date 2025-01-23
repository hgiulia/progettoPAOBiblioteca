#include "aggiungimediadialog.h"


AggiungiMediaDialog::AggiungiMediaDialog(QWidget* parent)
    : QDialog(parent)
{

    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    tipoMediaComboBox = new QComboBox(this);
    tipoMediaComboBox->addItem("libro");
    tipoMediaComboBox->addItem("film");
    tipoMediaComboBox->addItem("articolo");
    mainLayout->addWidget(tipoMediaComboBox);

    formLayout = new QFormLayout();
    mainLayout->addLayout(formLayout);

    onTipoMediaChanged("libro");
    aggiungiButton = new QPushButton("Aggiungi", this);
    mainLayout->addWidget(aggiungiButton);

    connect(tipoMediaComboBox, &QComboBox::currentTextChanged, this, &AggiungiMediaDialog::onTipoMediaChanged);
    connect(aggiungiButton, &QPushButton::clicked, this, &QDialog::accept);

    setLayout(mainLayout);
    resize(300,400);
}

void AggiungiMediaDialog::onTipoMediaChanged(const QString& tipoMedia)
{
    while (QLayoutItem* item = formLayout->takeAt(0)) {
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }

    titoloLineEdit = new QLineEdit(this);
    formLayout->addRow("Titolo:", titoloLineEdit);

    annoLineEdit = new QLineEdit(this);
    formLayout->addRow("Anno di pubblicazione:", annoLineEdit);

    descrizioneLineEdit = new QLineEdit(this);
    formLayout->addRow("Descrizione:", descrizioneLineEdit);

    immagineLineEdit = new QLineEdit(this);
    formLayout->addRow("Percorso Immagine:", immagineLineEdit);

    if (tipoMedia == "libro") {
        IsbnLineEdit = new QLineEdit(this);
        formLayout->addRow("ISBN:", IsbnLineEdit);
        autoreLineEdit = new QLineEdit(this);
        formLayout->addRow("Autore:", autoreLineEdit);
        numeroPagineLineEdit = new QLineEdit(this);
        formLayout->addRow("Numero di Pagine:", numeroPagineLineEdit);
        genereLineEdit = new QLineEdit(this);
        formLayout->addRow("Genere:", genereLineEdit);
        editoreLineEdit = new QLineEdit(this);
        formLayout->addRow("Editore:", editoreLineEdit);
    }
    else if (tipoMedia == "film") {
        durataLineEdit = new QLineEdit(this);
        formLayout->addRow("Durata:", durataLineEdit);
        genereLineEdit = new QLineEdit(this);
        formLayout->addRow("Genere:", genereLineEdit);
        registaLineEdit = new QLineEdit(this);
        formLayout->addRow("Regista:", registaLineEdit);
        produzioneLineEdit = new QLineEdit(this);
        formLayout->addRow("Produzione:", produzioneLineEdit);
        linguaLineEdit = new QLineEdit(this);
        formLayout->addRow("Lingua:", linguaLineEdit);
    }
    else if (tipoMedia == "articolo") {
        autoreLineEdit = new QLineEdit(this);
        formLayout->addRow("Autore:", autoreLineEdit);
        rivistaLineEdit = new QLineEdit(this);
        formLayout->addRow("Rivista:", rivistaLineEdit);
        numeroRivistaLineEdit = new QLineEdit(this);
        formLayout->addRow("Numero Rivista:", numeroRivistaLineEdit);
        dataPubblicazioneLineEdit = new QLineEdit(this);
        formLayout->addRow("Data Pubblicazione:", dataPubblicazioneLineEdit);
    }
}

QString AggiungiMediaDialog::getTipoMedia() const{return tipoMediaComboBox->currentText();}

QString AggiungiMediaDialog::getTitolo() const{return titoloLineEdit->text();}

int AggiungiMediaDialog::getAnno() const{return annoLineEdit->text().toInt();}

QString AggiungiMediaDialog::getDescrizione() const{return descrizioneLineEdit->text();}

QString AggiungiMediaDialog::getPercorsoImmagine() const{return immagineLineEdit->text();}

QString AggiungiMediaDialog::getISBN() const{return IsbnLineEdit->text();}

QString AggiungiMediaDialog::getAutore() const{return autoreLineEdit->text();}

QString AggiungiMediaDialog::getGenere() const{return genereLineEdit->text();}

int AggiungiMediaDialog::getNumeroPagine() const{return numeroPagineLineEdit->text().toInt();}

QString AggiungiMediaDialog::getRegista() const{return registaLineEdit->text();}

QString AggiungiMediaDialog::getProduzione() const{return produzioneLineEdit->text();}

QString AggiungiMediaDialog::getLingua() const{return linguaLineEdit->text();}

QString AggiungiMediaDialog:: getEditore() const{return editoreLineEdit->text();}

QString AggiungiMediaDialog::getRivista() const{return rivistaLineEdit->text();}

QString AggiungiMediaDialog::getDataPubblicazione() const{return dataPubblicazioneLineEdit->text();}
int AggiungiMediaDialog::getDurata() const{return durataLineEdit->text().toInt();}
int AggiungiMediaDialog::getNumeroRivista() const{return numeroRivistaLineEdit->text().toInt();}
