#include <iostream>
using namespace std;
#include <fstream>
#include "token.h"
#include <string.h>

enum zustandText zustand;

int main()
{

ifstream eingabe;
ClToken *token;
ClText object;

char again = 'b';
char input;

/*
 #####################################
  1.Schritt: Versuch
  -----------------------------------
  Dateien parsen:
  Open files
  (ÜBERARBEITUNG S. UNTEN)
 #####################################

if (input=='o') // oder open file funktioniert nicht??! Input muss array aber auch nicht
{
cout << "--- open file ---" << endl;
cout << "Welche Datei soll geöffnet werden?" << endl;
cin >> name;

if (!strcmp(name, "daten2.xml")) {

eingabe.open("daten2.xml");
token=new ClToken;
if (token->getToken(eingabe)!=0) token->druckeToken(1);
eingabe.close();
}

else if (!strcmp(name, "list.txt"))
    {
    eingabe.open("list.txt");
    object.verarbeiteText(eingabe);
    }

else
        cout << "This file does not exist! Please check name." << endl;
}
*/




/*
 ######################################
  finale Version:
 --------------------------------------

 ######################################
  Daten werden direkt eingelesen:
 ######################################
*/
cout << "\t--- data read ---" << endl;
    eingabe.open("pricelist.txt");
    object.verarbeiteText(eingabe, input);
    //char input kann hier natürlich noch nicht übergeben werden,
    //da noch nicht relevant.
    eingabe.close();
    //(TXT)

    eingabe.open("mediacenter.xml");
    token=new ClToken;
    token->getToken(eingabe);
    eingabe.close();
   //(XML)

   //Inhalte werden noch nicht gedruckt.

while (again == 'b'){
    //Programm wird nicht beendet, solange der User ins Menü zurückkehren möchte.

/*
 ######################
  Menüaufbau:
 ######################
*/

cout << "### Menu ###" << endl;
cout << "------------" << endl;
cout << "(o)pen txt-file" << endl;
cout << "(e)xport new file" << endl;
cout << "(s)earch" << endl;
cout << "(h)elp" << endl;
cout << "\nChoose option: " << endl;

cin >> input;

/*
 ######################
  Export new file:
 ######################
*/

if (input=='e')
{
    string dateiname;

    cout << "\t--- export data ---" << endl;
    cout << "Please name your new xml-file: ";
    cin >> dateiname;




   token->druckeToken(object, dateiname);
   //Weiterleitung an Druckfunktion in tokenlib. Datei wird dort mit Inhalt befüllt.



//Test:
//cout << "Id: " << object.getMovieId(6) << endl;


}//if 'e' closed

/*
 ######################
  Open txt-file:
 ######################
*/

if (input=='o'){
    cout << "\t--- open txt-file ---" << endl;
    object.verarbeiteText(eingabe, input);
    //Input wird hier relevant.
}


/*
 ######################
  Search content:
  (in progress)
 ######################
if (input=='s')
{
char category[50];
char content[50];

cout << "Type category: " << endl;
cin >> category;

cout << "Type search word: " << endl;
cin >> content;

token->druckeToken(object, dateiname, category, content);



}
*/

cout << "(b)ack to menu?: " << endl;
cin >> again;
} // while loop closed


} //main closed
