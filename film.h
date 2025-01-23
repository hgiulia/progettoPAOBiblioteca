#ifndef FILM_H
#define FILM_H
#include "media.h"
#include<string>

class Film : public Media
{

private:
    int durata;
    std::string regista;
    std::string produzioneCinematografica;
    std::string genere;
    std::string lingua;

public:
    Film(const unsigned int code, const std::string& title, int year, const std::string& description, const std::string& imageUrl,
         int durata, const std::string& regista, const std::string& produzione, const std::string& genere, const std::string& lingua);


    int getDurata() const;
    void setDurata(int durata);

    const std::string& getRegista() const;
    void setRegista(const std::string& regista);

    const std::string& getProduzioneCinematografica() const;
    void setProduzioneCinematografica(const std::string& produzione);

    const std::string& getGenere() const;
    void setGenere(const std::string& genere);

    const std::string& getLingua() const;
    void setLingua(const std::string& lingua);

    
    std::string visualizzaDettagli() const override;


};

#endif
