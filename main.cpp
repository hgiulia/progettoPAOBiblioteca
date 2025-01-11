#include "mainwindow.h"

#include <QApplication>

#include "mediamodel.h"
#include "libro.h"
#include "film.h"
#include "rivistearticoli.h"
#include <iostream>
#include <QDir>

void stampaCollezione(const mediaModel& model) {
    const auto& collezione = model.getMediaCollezione();
    for (const auto* media : collezione) {

        std::cout << media->visualizzaDettagli();
    }
}



int main(int argc, char *argv[])
{
//PROVA
    mediaModel model;

/*

   // Creazione di alcuni oggetti
    Libro* libro1= new Libro(1, "Il Signore degli Anelli", 1954, "Un classico della letteratura fantasy.", "path/to/image.jpg", "123456789", "J.R.R. Tolkien", 1178, "Fantasy", "HarperCollins");
    Film* film1= new Film(2, "Inception", 2010, "Un thriller psicologico di Christopher Nolan.", "path/to/image.jpg", 148, "Christopher Nolan", "Warner Bros.", "Sci-Fi", "Inglese");
    RivisteArticoli* articolo1 = new RivisteArticoli(3, "Quantum Computing", 2021, "Un articolo sul futuro del calcolo quantistico.", "path/to/image.jpg", "Dr. Smith", "Science Weekly", 42, "2021-10-15");


    // Aggiunta alla collezione
    model.aggiungiMedia(libro1);
    model.aggiungiMedia(film1);
    model.aggiungiMedia(articolo1);
   // stampaCollezione(model);

    Film* filmModificato = new Film(2, "Film Modificato", 2024, "","",123,"Nuovo Regista", "Nuova Produzione", "Nuovo Genere", "Nuova Lingua");
    model.modificaMedia(2, *filmModificato);
    Libro* libroModificato = new Libro(1, "Libro Modificato", 2022,"","", "ISBN67890", "Nuovo Autore", 350, "Nuovo Editore", "Nuovo Genere");
    model.modificaMedia(1, *libroModificato);
    stampaCollezione(model);


*/
    QString appDirPath = QDir::currentPath();

    QDir projectDir(appDirPath);
    projectDir.cdUp();
    projectDir.cdUp();

    QString filePath = projectDir.absoluteFilePath("database/database.json");

    model.caricaFile(filePath.toStdString()); //carica il file correttamente
    std::vector<Media*> mediaCollection = model.getMediaCollezione();
    for (const Media* media : mediaCollection) {
        std::cout << media->visualizzaDettagli() << std::endl;
    }
    Libro* libroModificato = new Libro(1, "Libro Modificato", 2022,"","", "ISBN67890", "Nuovo Autore", 350, "Nuovo Editore", "Nuovo Genere");
    model.modificaMedia(1, *libroModificato);
    model.salvaFile(filePath.toStdString());//funziona la modifica e salvataggio

    for (const Media* media : mediaCollection) {
        std::cout << media->visualizzaDettagli() << std::endl;
    }
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
