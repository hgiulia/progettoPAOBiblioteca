#ifndef RIVISTEARTICOLI_H
#define RIVISTEARTICOLI_H
#include "media.h"
#include <string>

class RivisteArticoli: public Media
{

private:
    std::string autore;
    std::string rivista;
    int numeroRivista;
    std::string dataPubblicazione;



public:
    RivisteArticoli(const unsigned int code, const std::string& title, int year, const std::string& description, const std::string& imageUrl,
             const std::string& autore, const std::string& rivista, int numeroRivista, const std::string& dataPubblicazione);

    const std::string& getAutore() const;
    void setAutore(const std::string& autore);

    const std::string& getRivista() const;
    void setRivista(const std::string& rivista);

    int getNumeroRivista() const;
    void setNumeroRivista(int numero);

    const std::string& getDataPubblicazione() const;
    void setDataPubblicazione(const std::string& data);

    std::string visualizzaDettagli() const override;
    
    void aggiornaDati(const Media& mediaAggiornare) override;
};

#endif
