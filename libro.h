#ifndef LIBRO_H
#define LIBRO_H
#include "media.h"
#include<string>

class Libro : public Media
{

private:
    const std::string ISBN;
    std::string autore;
    int numeroPagine;
    std::string genere;
    std::string editore;

public:
    Libro(const unsigned int code, const std::string& title, int year, const std::string& description, const std::string& imageUrl,
          const std::string& ISBN, const std::string& autore, int numeroPagine, const std::string& genere, const std::string& editore);


    const std::string& getISBN() const;

    const std::string& getAutore() const;
    void setAutore(const std::string& autore);

    int getNumeroPagine() const;
    void setNumeroPagine(int pagine);

    const std::string& getGenere() const;
    void setGenere(const std::string& genere);

    const std::string& getEditore() const;
    void setEditore(const std::string& editore);

    std::string visualizzaDettagli() const override;

    void aggiornaDati(const Media& mediaAggiornare) override;
};

#endif
