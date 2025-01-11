#include "jsonconvert.h"
//PARTE CHE SI OCCUPA DELLA CONVERSIONE DI DATI JSON IN MEDIA(LIBRI, FILM E ARTICOLI)

JsonConvert::JsonConvert() {}

QJsonObject JsonConvert::toJson(const Media& media) {
    QJsonObject json;
    json["codice"] =  static_cast<int>(media.getCodiceUnivoco());
    json["anno"] = media.getAnnoPubblicazione();
    json["descrizione"] = QString::fromStdString(media.getDescrizione());
    json["percorsoImmagine"] = QString::fromStdString(media.getPercorsoImmagine());

    if (const Libro* libro = dynamic_cast<const Libro*>(&media)) {
        json["tipo"] = "libro";
        json["isbn"] = QString::fromStdString(libro->getISBN());
        json["autore"] = QString::fromStdString(libro->getAutore());
        json["numeroPagine"] = libro->getNumeroPagine();
        json["genere"] = QString::fromStdString(libro->getGenere());
        json["editore"] = QString::fromStdString(libro->getEditore());
    } else if (const Film* film = dynamic_cast<const Film*>(&media)) {
        json["tipo"] = "film";
        json["durata"] = film->getDurata();
        json["regista"] = QString::fromStdString(film->getRegista());
        json["produzione"] = QString::fromStdString(film->getProduzioneCinematografica());
        json["genere"] = QString::fromStdString(film->getGenere());
        json["lingua"] = QString::fromStdString(film->getLingua());
    } else if (const RivisteArticoli* articolo = dynamic_cast<const RivisteArticoli*>(&media)) {
        json["tipo"] = "rivista";
        json["autore"] = QString::fromStdString(articolo->getAutore());
        json["rivista"] = QString::fromStdString(articolo->getRivista());
        json["numeroRivista"] = articolo->getNumeroRivista();
        json["dataPubblicazione"] = QString::fromStdString(articolo->getDataPubblicazione());
    }

    return json;
}


Media* JsonConvert::fromJson(const QJsonObject& json) {


    QString tipo = json["tipo"].toString();


    if (tipo == "libro") {

        unsigned int codice = json["codice"].toInt();
        std::string titolo = json["titolo"].toString().toStdString();
        int anno = json["anno"].toInt();
        std::string descrizione = json["descrizione"].toString().toStdString();
        std::string immagine = json["percorsoImmagine"].toString().toStdString();
        std::string isbn = json["isbn"].toString().toStdString();
        std::string autore = json["autore"].toString().toStdString();
        int numeroPagine = json["numeroPagine"].toInt();
        std::string genere = json["genere"].toString().toStdString();
        std::string editore = json["editore"].toString().toStdString();

        return new Libro(codice, titolo, anno, descrizione, immagine, isbn, autore, numeroPagine, genere, editore);

    } else if (tipo == "film") {

        unsigned int codice = json["codice"].toInt();
        std::string titolo = json["titolo"].toString().toStdString();
        int anno = json["anno"].toInt();
        std::string descrizione = json["descrizione"].toString().toStdString();
        std::string immagine = json["percorsoImmagine"].toString().toStdString();
        int durata = json["durata"].toInt();
        std::string regista = json["regista"].toString().toStdString();
        std::string produzione = json["produzione"].toString().toStdString();
        std::string genere = json["genere"].toString().toStdString();
        std::string lingua = json["lingua"].toString().toStdString();

        return new Film(codice, titolo, anno, descrizione, immagine, durata, regista, produzione, genere, lingua);

    } else if (tipo == "rivista") {

        unsigned int codice = json["codice"].toInt();
        std::string titolo = json["titolo"].toString().toStdString();
        int anno = json["anno"].toInt();
        std::string descrizione = json["descrizione"].toString().toStdString();
        std::string immagine = json["percorsoImmagine"].toString().toStdString();
        std::string autore = json["autore"].toString().toStdString();
        std::string rivista = json["rivista"].toString().toStdString();
        int numeroRivista = json["numeroRivista"].toInt();
        std::string dataPubblicazione = json["dataPubblicazione"].toString().toStdString();

        return new RivisteArticoli(codice, titolo, anno, descrizione, immagine, autore, rivista, numeroRivista, dataPubblicazione);

    } else {

        return nullptr;
    }
}


