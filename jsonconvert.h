#ifndef JSONCONVERT_H
#define JSONCONVERT_H

#include <QString>
#include <QJsonObject>
#include "media.h"
#include "libro.h"
#include "film.h"
#include "rivistearticoli.h"


class JsonConvert
{
public:
    JsonConvert();
    static QJsonObject toJson(const Media& media);


    static Media* fromJson(const QJsonObject& json);
};

#endif
