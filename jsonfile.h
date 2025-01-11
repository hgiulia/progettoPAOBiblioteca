#ifndef JSONFILE_H
#define JSONFILE_H
#include "string"
#include "jsonconvert.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QString>

class JsonFile
{
private:
    std::string filePath;
    const JsonConvert& converter;

public:
    explicit JsonFile(const std::string& path, const JsonConvert& converter);
    QJsonDocument load() const;
    void store(const QJsonDocument& document) const;

    const std::string& getPath() const;
    void setPath(const std::string& path);
};

#endif
