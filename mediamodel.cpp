#include "mediamodel.h"

unsigned int mediaModel::ultimoCodiceUnivoco = 0;
unsigned int mediaModel::getNuovoCodiceUnivoco() {
    ultimoCodiceUnivoco= (mediaCollezione.back())->getCodiceUnivoco();
    return ++ultimoCodiceUnivoco;  // Incrementa e restituisce il nuovo codice univoco
}



mediaModel::mediaModel() {}
mediaModel::~mediaModel() {
    for (auto media : mediaCollezione) {
        delete media;
    }
}

void mediaModel::aggiungiMedia(Media *media){
    if (media) {
        mediaCollezione.push_back(media);
    }
}

void mediaModel::eliminaMedia(unsigned int codiceMedia){
    for (auto it = mediaCollezione.begin(); it != mediaCollezione.end(); ++it) {
        if ((*it)->getCodiceUnivoco() == codiceMedia) {
            delete *it;
            mediaCollezione.erase(it);
            return;
        }
    }
}


Media * mediaModel::cercaMedia(unsigned int codiceMedia) const{
    for (auto it = mediaCollezione.begin(); it != mediaCollezione.end(); ++it) {
        if ((*it)->getCodiceUnivoco() == codiceMedia) {
            return *it;
        }
    }
    return nullptr;
}


std::string mediaModel::getDettagliMedia(unsigned int codiceMedia) const {
    Media* media = cercaMedia(codiceMedia);
    if (media) {
        return media->visualizzaDettagli();
    }
    return NULL;
}

std::vector<Media*> mediaModel::getMediaCollezione() const {
    return  mediaCollezione;
}



void mediaModel::salvaFile(const std::string& filePath) const {
    JsonFile jsonFile(filePath, converter);
    
    QJsonArray jsonArray;

    for (const Media* media : mediaCollezione) {
        QJsonObject jsonObject = converter.toJson(*media);
        jsonArray.append(jsonObject);
    }

    QJsonDocument document(jsonArray);
    jsonFile.store(document);
}


void mediaModel::caricaFile(const std::string& filePath) {
    JsonFile jsonFile(filePath, converter);
    QJsonDocument document = jsonFile.load();
    if (!document.isArray()) {
        return;
    }

    QJsonArray jsonArray = document.array();

    for (Media* media : mediaCollezione) {
        delete media;
    }
    mediaCollezione.clear();

    for (const QJsonValue& value : jsonArray) {
        QJsonObject jsonObject = value.toObject();
        Media* media = converter.fromJson(jsonObject);
        if (media) {

            mediaCollezione.push_back(media);
            ++ultimoCodiceUnivoco;

        }
    }
}

std::vector<std::string> mediaModel::getTitoliMedia() const {
    std::vector<std::string> titoli;
    for (const auto& media : mediaCollezione) {

        titoli.push_back(media->getTitolo());

    }
    return titoli;
}

unsigned int mediaModel::getCodicePerTitolo(const std::string& titolo) const {
    for (const auto& media : mediaCollezione) {
        if (media->getTitolo() == titolo) {
            return media->getCodiceUnivoco();
        }
    }
    return 0;
}

std::vector<std::string> mediaModel::filtraMedia(const std::string& tipo) const {
    std::vector<std::string> titoli;

    for (const auto& media : mediaCollezione) {
        if (tipo == "libro" && dynamic_cast<const Libro*>(media)) {
            titoli.push_back(media->getTitolo());
        }
        else if (tipo == "film" && dynamic_cast<const Film*>(media)) {
            titoli.push_back(media->getTitolo());
        }
        else if (tipo == "articolo" && dynamic_cast<const RivisteArticoli*>(media)) {
            titoli.push_back(media->getTitolo());
        }
    }

    return titoli;
}
