#include "modificamediadialog.h"

ModificaMediaDialog::ModificaMediaDialog(std::string tipo, QWidget* parent)
    :  QDialog(parent)
{

    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QLabel* dialogTitle = new QLabel(QString("Modifica %1").arg(QString::fromStdString(tipo)), this);
    dialogTitle->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(dialogTitle);

    formLayout = new QFormLayout();
    mainLayout->addLayout(formLayout);



    titoloLineEdit = new QLineEdit(this);
    formLayout->addRow("Titolo:", titoloLineEdit);

    annoLineEdit = new QLineEdit(this);
    formLayout->addRow("Anno di pubblicazione:", annoLineEdit);

    descrizioneLineEdit = new QLineEdit(this);
    formLayout->addRow("Descrizione:", descrizioneLineEdit);
    if(tipo=="libro"){
        autoreLineEdit = new QLineEdit(this);
        formLayout->addRow("Autore:", autoreLineEdit);


        numeroPagineLineEdit = new QLineEdit(this);
        formLayout->addRow("Numero di Pagine:", numeroPagineLineEdit);


        genereLineEdit = new QLineEdit(this);
        formLayout->addRow("Genere:", genereLineEdit);

        editoreLineEdit = new QLineEdit(this);
        formLayout->addRow("Editore:", editoreLineEdit);

    }else if(tipo=="film"){
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
    }else if(tipo=="articolo"){
        autoreLineEdit = new QLineEdit(this);
        formLayout->addRow("Autore:", autoreLineEdit);
        rivistaLineEdit = new QLineEdit(this);
        formLayout->addRow("Rivista:", rivistaLineEdit);

        numeroRivistaLineEdit = new QLineEdit(this);
        formLayout->addRow("Numero Rivista:", numeroRivistaLineEdit);
        dataPubblicazioneLineEdit = new QLineEdit(this);
        formLayout->addRow("Data Pubblicazione:", dataPubblicazioneLineEdit);

    }
    mainLayout->addLayout(formLayout);

    QPushButton* confermaButton = new QPushButton("Conferma", this);
    connect(confermaButton, &QPushButton::clicked, this, &QDialog::accept);
    mainLayout->addWidget(confermaButton);

    setLayout(mainLayout);
    resize(300,400);

}



QString ModificaMediaDialog::getTitolo() const
{
    return titoloLineEdit->text();
}

int ModificaMediaDialog::getAnno() const
{
    return annoLineEdit->text().toInt();
}

QString ModificaMediaDialog::getDescrizione() const
{
    return descrizioneLineEdit->text();
}


QString ModificaMediaDialog::getAutore() const
{
    return autoreLineEdit->text();
}

QString ModificaMediaDialog::getGenere() const
{
    return genereLineEdit->text();
}

int ModificaMediaDialog::getNumeroPagine() const
{
    return numeroPagineLineEdit->text().toInt();
}

QString ModificaMediaDialog::getRegista() const
{
    return registaLineEdit->text();
}

QString ModificaMediaDialog::getProduzione() const
{
    return produzioneLineEdit->text();
}

QString ModificaMediaDialog::getLingua() const
{
    return linguaLineEdit->text();
}



QString ModificaMediaDialog:: getEditore() const{
    return editoreLineEdit->text();
}

QString ModificaMediaDialog::getRivista() const{
    return rivistaLineEdit->text();
}

QString ModificaMediaDialog::getDataPubblicazione() const{
    return dataPubblicazioneLineEdit->text();
}
int ModificaMediaDialog::getDurata() const{
    return durataLineEdit->text().toInt();
}
int ModificaMediaDialog::getNumeroRivista() const{
    return numeroRivistaLineEdit->text().toInt();
}

void ModificaMediaDialog::setTitolo(const QString& titolo) {
    if (titoloLineEdit) {
        titoloLineEdit->setText(titolo);
    }
}


void ModificaMediaDialog::setAnno(int anno) {
    if (annoLineEdit) {
        annoLineEdit->setText(QString::number(anno));
    }
}

void ModificaMediaDialog::setDescrizione(const QString& descrizione) {
    if (descrizioneLineEdit) {
        descrizioneLineEdit->setText(descrizione);
    }
}

void ModificaMediaDialog::setAutore(const QString& autore) {
    if (autoreLineEdit) {
        autoreLineEdit->setText(autore);
    }
}

void ModificaMediaDialog::setGenere(const QString& genere) {
    if (genereLineEdit) {
        genereLineEdit->setText(genere);
    }
}

void ModificaMediaDialog::setNumeroPagine(int numeroPagine) {
    if (numeroPagineLineEdit) {
        numeroPagineLineEdit->setText(QString::number(numeroPagine));
    }
}

void ModificaMediaDialog::setRegista(const QString& regista) {
    if (registaLineEdit) {
        registaLineEdit->setText(regista);
    }
}

void ModificaMediaDialog::setProduzione(const QString& produzione) {
    if (produzioneLineEdit) {
        produzioneLineEdit->setText(produzione);
    }
}

void ModificaMediaDialog::setLingua(const QString& lingua) {
    if (linguaLineEdit) {
        linguaLineEdit->setText(lingua);
    }
}

void ModificaMediaDialog::setRivista(const QString& rivista) {
    if (rivistaLineEdit) {
        rivistaLineEdit->setText(rivista);
    }
}

void ModificaMediaDialog::setNumeroRivista(int numeroRivista) {
    if (numeroRivistaLineEdit) {
        numeroRivistaLineEdit->setText(QString::number(numeroRivista));
    }
}

void ModificaMediaDialog::setDataPubblicazione(const QString& dataPubblicazione) {
    if (dataPubblicazioneLineEdit) {
        dataPubblicazioneLineEdit->setText(dataPubblicazione);
    }
}

void ModificaMediaDialog::setDurata(int durata) {
    if (durataLineEdit) {
        durataLineEdit->setText(QString::number(durata));
    }
}
void ModificaMediaDialog::setEditore(const QString& editore) {
    if (editoreLineEdit) {
        editoreLineEdit->setText(editore);
    }
}
