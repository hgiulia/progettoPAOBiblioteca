#include "rivistearticoli.h"


RivisteArticoli::RivisteArticoli(const unsigned int code, const std::string& title, int year, const std::string& description, const std::string& imageUrl,
                   const std::string& autore, const std::string& rivista, int numeroRivista, const std::string& dataPubblicazione)
    : Media(code, title, year, description, imageUrl),
    autore(autore),
    rivista(rivista),
    numeroRivista(numeroRivista),
    dataPubblicazione(dataPubblicazione) {}


const std::string& RivisteArticoli::getAutore() const {
    return autore;
}

void RivisteArticoli::setAutore(const std::string& autore) {
    this->autore = autore;
}

const std::string& RivisteArticoli::getRivista() const {
    return rivista;
}

void RivisteArticoli::setRivista(const std::string& rivista) {
    this->rivista = rivista;
}

int RivisteArticoli::getNumeroRivista() const {
    return numeroRivista;
}
void RivisteArticoli::setNumeroRivista(int numero) {
    numeroRivista = numero;
}

const std::string& RivisteArticoli::getDataPubblicazione() const {
    return dataPubblicazione;
}

void RivisteArticoli::setDataPubblicazione(const std::string& data) {
    dataPubblicazione = data;
}

std::string RivisteArticoli::visualizzaDettagli() const {
    return "Titolo: " + getTitolo() + "\n" +
           "Anno: " + std::to_string(getAnnoPubblicazione()) + "\n" +
           "Descrizione: " + getDescrizione() + "\n" +
           "Autore: " + autore + "\n" +
           "Rivista: " + rivista + "\n" +
           "Numero Rivista: " + std::to_string(numeroRivista) + "\n" +
           "Data Pubblicazione: " + dataPubblicazione;
}





