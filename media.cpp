#include "media.h"
#include "string"



Media::Media(const unsigned int code,const std::string& title, int year, const std::string& description, const std::string& imageUrl)
    : codiceUnivoco(code), titolo(title), annoPubblicazione(year), descrizione(description), percorsoImmagine(imageUrl) {}


Media::~Media()=default;


void Media::setTitolo(const std::string& t) {
    titolo = t;
}
void Media::setAnnoPubblicazione(int year) {
    annoPubblicazione = year;
}

unsigned int Media::getCodiceUnivoco() const {
    return codiceUnivoco;
}

const std::string& Media::getTitolo() const {
    return titolo;
}

int Media::getAnnoPubblicazione() const {
    return annoPubblicazione;
}

const std::string& Media::getDescrizione() const {
    return descrizione;
}

const std::string& Media::getPercorsoImmagine() const {
    return percorsoImmagine;
}


