#ifndef MEDIAMODEL_H
#define MEDIAMODEL_H

#include "media.h"
#include <vector>

#include "libro.h"
#include "film.h"
#include "rivistearticoli.h"
#include "jsonfile.h"
#include <QJsonArray>
#include <QJsonDocument>

class mediaModel
{



private:
    std::vector<Media*> mediaCollezione;
    JsonConvert converter;

    static unsigned int ultimoCodiceUnivoco;



public:
    mediaModel();
    ~mediaModel();

    unsigned int getNuovoCodiceUnivoco();


    void aggiungiMedia(Media *media);
    void eliminaMedia(unsigned int codiceMedia);
     Media* cercaMedia(unsigned int codiceMedia)const;

    std::string getDettagliMedia(unsigned int codiceMedia) const;
    std::vector<std::string> getTitoliMedia() const;

    void salvaFile(const std::string & filePath)const;
    void caricaFile(const std::string & filePath);


    std::vector<Media*> getMediaCollezione() const;
    unsigned int getCodicePerTitolo(const std::string & titolo)const;

    std::vector<std::string> filtraMedia(const std::string& tipo) const;

};

#endif // MEDIAMODEL_H
