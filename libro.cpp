#include "libro.h"
#include<string>
#include <iostream>

Libro::Libro(const unsigned int code, const std::string& title, int year, const std::string& description, const std::string& imageUrl,
             const std::string& ISBN, const std::string& autore, int numeroPagine, const std::string& genere, const std::string& editore)
    : Media(code, title, year, description, imageUrl), ISBN(ISBN), autore(autore), numeroPagine(numeroPagine), genere(genere), editore(editore) {}



const std::string& Libro::getISBN() const {
    return ISBN;
}

const std::string& Libro::getAutore() const {
    return autore;
}

void Libro::setAutore(const std::string& autore) {
    this->autore = autore;
}

int Libro::getNumeroPagine() const {
    return numeroPagine;
}

void Libro::setNumeroPagine(int pagine) {
    numeroPagine = pagine;
}

const std::string& Libro::getGenere() const {
    return genere;
}

void Libro::setGenere(const std::string& genere) {
    this->genere = genere;
}

const std::string& Libro::getEditore() const {
    return editore;
}

void Libro::setEditore(const std::string& editore) {
    this->editore = editore;
}

// Metodi sovrascritti
std::string Libro::visualizzaDettagli() const {
    return "Titolo: " + getTitolo() + "\n" +
           "Anno: " + std::to_string(getAnnoPubblicazione()) + "\n" +
           "Descrizione: " + getDescrizione() + "\n" +
           "ISBN: " + ISBN + "\n" +
           "Autore: " + autore + "\n" +
           "Pagine: " + std::to_string(numeroPagine) + "\n" +
           "Genere: " + genere + "\n" +
           "Editore: " + editore;
}

void Libro::aggiornaDati(const Media& mediaAggiornare){
    const Libro& l=dynamic_cast<const Libro&>(mediaAggiornare);
    if (!l.getTitolo().empty()) {
        setTitolo(l.getTitolo());
    }
    if (l.getAnnoPubblicazione() != 0) {
        setAnnoPubblicazione(l.getAnnoPubblicazione());
    }
    if (!l.getAutore().empty()) {
        setAutore(l.getAutore());
    }
    if (!l.getGenere().empty()) {
        setGenere(l.getGenere());
    }
    if (l.getNumeroPagine() != 0) {
        setNumeroPagine(l.getNumeroPagine());
    }
    if (!l.getEditore().empty()) {
        setEditore(l.getEditore());
    }
}





