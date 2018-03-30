
#include <iostream>
#include <fstream>
using namespace std;
#include "txt.h"
#include "string.h"
void ClText::verarbeiteText(ifstream &datei)
{

    enum zustandText zustand;
    for (zaehler=0,zustand=inId, anzahlFilm=0;;)
    {
    datei.get(zeichen);
    if (datei.eof()) break;
  switch(zeichen)
     {
     case ' ':
         if (zustand==inId)
         {
             //cout << "ich glaube ich lese di ID ein. dies ist die " << anzahlFilm << ". Leseiteration" << endl;
           zustand=inMedium;
           puffer[zaehler]='\0';
           movieId[anzahlFilm] = new char[zaehler+1];
           strcpy(movieId[anzahlFilm], puffer);
           cout << " Id: " << movieId[anzahlFilm];
           //a[anzahlAtt] = new char[zaehler+1];
           //strcpy(attName[anzahlAtt],puffer);
           //cout << "Id: " << puffer;

           zaehler=0;
         }
         else if (zustand == inMedium)
         {
             //cout << "ich glaube ich lese ein Medium ein. dies ist die " << anzahlFilm << ". Leseiteration" << endl;

             zustand=inPrice;
             puffer[zaehler]='\0';
             mediumKind[anzahlFilm] = new char[zaehler+1];
             strcpy(mediumKind[anzahlFilm], puffer);
             cout << " Medium: " << mediumKind[anzahlFilm] ;

             //cout << " Medium: " << puffer;

             zaehler=0;
         }
         else if (zustand == inPrice)
         {
             //cout << "ich glaube ich lese den Preis ein. dies ist die " << anzahlFilm << ". Leseiteration" << endl;
             zustand=inStock;
             puffer[zaehler]='\0';
             price[anzahlFilm] = new char[zaehler+1];
             strcpy(price[anzahlFilm], puffer);
             cout << " Price: " << price[anzahlFilm] ;
             //cout << " Preis: " << puffer;
             zaehler=0;
         }
           break;
    case '\n':
      //cout << "ich glaube ich lese den Bestand ein. dies ist die " << anzahlFilm << ". Leseiteration" << endl;

        puffer[zaehler]='\0';
        //cout << " Stock puffer: " << puffer << endl;
        stock[anzahlFilm] = new char[zaehler+1];
        strcpy(stock[anzahlFilm], puffer);
        cout << " Stock: " << stock[anzahlFilm] << endl;


        zaehler=0;
        anzahlFilm++;
zustand=inId;
        break;

        default:
            puffer[zaehler]=zeichen;
            zaehler++;
           // cout << zeichen << endl;
           break;
    }



}
/*
cout << "TESTAUSGABE:" << endl;
        cout << "ID: " << getMovieId(3) << endl;
        cout << "Medium: " << getMediumKind(3) << endl;
        cout << "Price: " << getPrice(3) S<< endl;
        cout << "Stock: " << getStock(3) << endl;
      //Test:
      //cout << "ANZAHL: " << stock[5] << endl;
    //cout << "ID: " << movieId[3] << endl;*/
}


// Druckfunktion zum Schluß
