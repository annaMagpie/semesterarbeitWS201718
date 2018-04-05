class ClText {
private:

    char *movieId[50];
    char *mediumKind[50];
    char *price[50];
    char *stock[50];
    int zaehler;
    char zeichen;
    char puffer[50];
    int anzahlFilm;

public:

    void verarbeiteText(ifstream &datei, char befehl);
    char *getMovieId(int line) {return movieId[line];}
    char *getMediumKind(int line) {return mediumKind[line];}
    char *getPrice(int line) {return price[line];}
    char *getStock(int line) {return stock[line];}
    int getAnzahlFilm() {return anzahlFilm;}

};

enum zustandText {inId, inMedium, inPrice, inStock};

