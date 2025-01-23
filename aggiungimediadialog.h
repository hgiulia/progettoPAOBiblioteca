
#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>


class AggiungiMediaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AggiungiMediaDialog(QWidget* parent = nullptr);

    QString getTipoMedia() const;
    QString getTitolo() const;
    int getAnno() const;
    QString getDescrizione() const;
    QString getPercorsoImmagine() const;
    QString getISBN() const;
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

private slots:
    void onTipoMediaChanged(const QString& tipoMedia);

private:
    QFormLayout* formLayout;

    QComboBox* tipoMediaComboBox;
    QLineEdit* titoloLineEdit;
    QLineEdit* annoLineEdit;
    QLineEdit* descrizioneLineEdit;
    QLineEdit* immagineLineEdit;
    QPushButton* aggiungiButton;

    QLineEdit* IsbnLineEdit;
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

