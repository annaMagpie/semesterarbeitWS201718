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


char input;
string dateiname;
string category;
string content;


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

//1. Versuch, dass Programm am laufen zu halten:
//while (again == 'b'){
    //Programm wird nicht beendet, solange der User ins Menü zurückkehren möchte.

//Optimierung: While loop mit switch:
do
{

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
cout << "(x) - exit menu" << endl;
cout << "\nChoose option: " << endl;

cin >> input;

/*
 ######################
  Export new file:
 ######################
*/


switch(input){
    case 'e':
//if (input=='e')


    cout << "\t--- export data ---" << endl;
    cout << "Please name your new xml-file: ";
    cin >> dateiname;

   token->druckeToken(object, dateiname);
   //Weiterleitung an Druckfunktion in tokenlib. Datei wird dort mit Inhalt befüllt.
   cout << "Your file was created." << endl;

    break;


/*
 ######################
  Open txt-file:
 ######################
*/
case 'o':

//if (input=='o'){
    cout << "\t--- open txt-file ---" << endl;
    object.verarbeiteText(eingabe, input);
    //Input wird hier relevant.

    break;

case 'x':
    cout << "You want to leave? Please confirm: " << endl;

    break;



/*
 ######################
  Search content:
  (in progress)
 ######################
 */
case 's':

    cout << "Type category: " << endl;
    cin >> category;

    cout << "Type search word: " << endl;
    cin >> content;
/*
    if (child->tokenSibling()==category){
    token->search(category, content);
    }
    else {cout << "no" << endl;}

  */
    break;

default:
    cout << "False instruction. Please try again. " << endl;

}
cout << endl << "Close programm with 'x' or type any other character to go back to menu." << endl;
cin >> input;
}
while (input!='x');




//1. Versuch, dass Programm am laufen zu halten:
//cout << "(b)ack to menu?: " << endl;
//cin >> again;




//Test:
//cout << "Id: " << object.getMovieId(6) << endl;

} //main closed
