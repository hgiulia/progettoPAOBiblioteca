#ifndef MEDIA_H
#define MEDIA_H

#include<string>


class Media
{

private:
    const unsigned int codiceUnivoco;
    std::string titolo;
    int annoPubblicazione;
    std::string descrizione;
    std::string percorsoImmagine; 


public:
    Media(const unsigned int code, const std::string& title, int year, const std::string& description, const std::string& imageUrl );
    virtual ~Media();

    void setTitolo(const std::string &t);
    void setAnnoPubblicazione(const int t);
    void setDescrizione(const std::string &t);
    unsigned int getCodiceUnivoco() const;
    const std::string& getTitolo() const;
    int getAnnoPubblicazione() const;
    const std::string& getDescrizione() const;
    const std::string& getPercorsoImmagine() const;

    virtual std::string visualizzaDettagli() const =0;





};

#endif // MEDIA_H
