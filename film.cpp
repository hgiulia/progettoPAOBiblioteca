#include "film.h"
#include<iostream>
Film::Film(const unsigned int code, const std::string& title, int year, const std::string& description, const std::string& imageUrl,
           int durata, const std::string& regista, const std::string& produzione, const std::string& genere, const std::string& lingua)
    : Media(code, title, year, description, imageUrl),
    durata(durata),
    regista(regista),
    produzioneCinematografica(produzione),
    genere(genere),
    lingua(lingua) {}



int Film::getDurata() const {
    return durata;
}

void Film::setDurata(int durata) {
    this->durata = durata;
}

const std::string& Film::getRegista() const {
    return regista;
}

void Film::setRegista(const std::string& regista) {
    this->regista = regista;
}

const std::string& Film::getProduzioneCinematografica() const {
    return produzioneCinematografica;
}

void Film::setProduzioneCinematografica(const std::string& produzione) {
    this->produzioneCinematografica = produzione;
}

const std::string& Film::getGenere() const {
    return genere;
}

void Film::setGenere(const std::string& genere) {
    this->genere = genere;
}

const std::string& Film::getLingua() const {
    return lingua;
}

void Film::setLingua(const std::string& lingua) {
    this->lingua = lingua;
}

// Metodi sovrascritti
std::string Film::visualizzaDettagli() const {
    std::cout << "-------------FFFIIILMMM-------------\n";

    std::cout << "--------------------------\n";
    return "Titolo: " + getTitolo() + "\n" +
           "Anno: " + std::to_string(getAnnoPubblicazione()) + "\n" +
           "Descrizione: " + getDescrizione() + "\n" +
           "Durata: " + std::to_string(durata) + " minuti\n" +
           "Regista: " + regista + "\n" +
           "Produzione: " + produzioneCinematografica + "\n" +
           "Genere: " + genere + "\n" +
           "Lingua: " + lingua;
}

void Film::aggiornaDati(const Media& mediaAggiornare){
const Film& f=dynamic_cast<const Film&>(mediaAggiornare);
    if (!f.getTitolo().empty()) {
        setTitolo(f.getTitolo());
    }
    if (f.getAnnoPubblicazione() != 0) {
        setAnnoPubblicazione(f.getAnnoPubblicazione());
    }
    if (!f.getRegista().empty()) {
        setRegista(f.getRegista());
    }
    if (!f.getGenere().empty()) {
        setGenere(f.getGenere());
    }
    if (f.getDurata() != 0) {
        setDurata(f.getDurata());
    }


}

