#include "mediamodel.h"


mediaModel::mediaModel() {}
mediaModel::~mediaModel() {
    for (auto media : mediaCollezione) {
        delete media;
    }
}

void mediaModel::aggiungiMedia(Media *media){
    mediaCollezione.push_back(media);
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


void mediaModel::getDettagliMedia(unsigned int codiceMedia) const {
    Media* media = cercaMedia(codiceMedia);
    if (media) {
        media->visualizzaDettagli();
    }
}

void mediaModel::modificaMedia(unsigned int codiceUnivoco, const Media& mediaModificata) {
    for (auto& media : mediaCollezione) {
        if (media->getCodiceUnivoco() == codiceUnivoco) {

            if (dynamic_cast<Libro*>(media)) {
                const Libro& nuovoLibro = static_cast<const Libro&>(mediaModificata);
                (dynamic_cast<Libro*>(media))->aggiornaDati(nuovoLibro);
            }
            else if (dynamic_cast<Film*>(media)) {
                const Film& nuovoFilm = static_cast<const Film&>(mediaModificata);
                (dynamic_cast<Film*>(media))->aggiornaDati(nuovoFilm);
            } else if (dynamic_cast<RivisteArticoli*>(media)) {
                const RivisteArticoli & nuovoArticolo = static_cast<const RivisteArticoli&>(mediaModificata);
                (dynamic_cast<RivisteArticoli*>(media))->aggiornaDati(nuovoArticolo);
            }
            return;
        }
    }

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
        }
    }
}
