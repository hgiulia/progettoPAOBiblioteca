#include "jsonfile.h"
#include <iostream>

//PARTE CHE SI OCCUPA DEL LOAD E SAVE FILE

JsonFile::JsonFile(const std::string& path, const JsonConvert& converter)
    : filePath(path), converter(converter) {
    }
const std::string& JsonFile::getPath() const {
    return filePath;
}

void JsonFile::setPath(const std::string& path) {
    filePath = path;
}


QJsonDocument JsonFile::load() const {
    QFile file(QString::fromStdString(filePath));


    if (!file.open(QFile::ReadOnly)) {
    //std::cerr << "Errore nell'aprire il file per la lettura!" << std::endl;
        return QJsonDocument();
    }


    QByteArray fileData = file.readAll();
    file.close();


    QJsonDocument document = QJsonDocument::fromJson(fileData);

    return document;
}

void JsonFile::store(const QJsonDocument& document) const {
    QFile file(QString::fromStdString(filePath));


    if (!file.open(QFile::WriteOnly)) {
       // std::cerr << "Errore nell'aprire il file per la scrittura!" << std::endl;
        return;
    }

    file.resize(0);
    file.write(document.toJson());
    file.close();
}
