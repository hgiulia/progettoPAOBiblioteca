#ifndef MODIFICAMEDIADIALOG_H
#define MODIFICAMEDIADIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include <QLabel>


class ModificaMediaDialog: public QDialog
{
    Q_OBJECT
public:
    explicit ModificaMediaDialog(std::string tipo, QWidget* parent = nullptr);

    QString getTipoMedia() const;
    QString getTitolo() const;
    int getAnno() const;
    QString getDescrizione() const;
    QString getAutore() const;
    QString getGenere() const;
    int getNumeroPagine() const;
    QString getRegista() const;
    QString getProduzione() const;
    QString getLingua() const;

    QString getEditore() const;

    QString getRivista() const;

    QString getDataPubblicazione() const;
    int getDurata() const;
    int getNumeroRivista() const;

    void setTitolo(const QString& titolo);
    void setAnno(int anno);
    void setDescrizione(const QString& descrizione);
    void setAutore(const QString& autore);
    void setGenere(const QString& genere);
    void setNumeroPagine(int numeroPagine);
    void setRegista(const QString& regista);
    void setProduzione(const QString& produzione);
    void setLingua(const QString& lingua);
    void setRivista(const QString& rivista);
    void setNumeroRivista(int numeroRivista);
    void setDataPubblicazione(const QString& dataPubblicazione);
    void setDurata(int durata);
    void setEditore(const QString& editore);

private:
    QFormLayout* formLayout;

    QLineEdit* titoloLineEdit;
    QLineEdit* annoLineEdit;
    QLineEdit* descrizioneLineEdit;
    QLineEdit* autoreLineEdit;
    QLineEdit* numeroPagineLineEdit;
    QLineEdit* genereLineEdit;
    QLineEdit* registaLineEdit;
    QLineEdit* produzioneLineEdit;
    QLineEdit* linguaLineEdit;
    QLineEdit* editoreLineEdit;
    QLineEdit* rivistaLineEdit;
    QLineEdit* dataPubblicazioneLineEdit;
    QLineEdit* durataLineEdit;
    QLineEdit* numeroRivistaLineEdit;


};

#endif
