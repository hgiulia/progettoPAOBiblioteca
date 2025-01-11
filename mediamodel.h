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
public:
    mediaModel();
    ~mediaModel();

    void aggiungiMedia(Media *media);
    void eliminaMedia(unsigned int codiceMedia);
    void modificaMedia(unsigned int codiceMedia, const Media &media);
    Media* cercaMedia(unsigned int codiceMedia)const;

    void getDettagliMedia(unsigned int codiceMedia) const;

    void salvaFile(const std::string & filePath)const;
    void caricaFile(const std::string & filePath);


    std::vector<Media*> getMediaCollezione() const;




};

#endif // MEDIAMODEL_H
