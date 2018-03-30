#include <iostream>
using namespace std;
#include <fstream>
#include "token.h"

#include <string.h>

enum zustandText zustand;

char name[20];


int main()
{


ifstream eingabe;
ClToken *token;


ClText object;


//char name[20]; //doppelt?
char again = 'y';
char input; // [20] wegen input o / open


while (again == 'y'){


cout << "### Menu ###" << endl;
cout << "------------" << endl;
cout << "-> (o)pen file" << endl;
cout << "-> (e)xport new file" << endl;
cout << "-> (s)earch" << endl;
cout << "-> (h)elp" << endl;
cout << "\nChoose option: " << endl;

cin >> input;
/* 1.schritt dateien parsen:
//######################
//******open file*******
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
    //ifstream datei;

    eingabe.open("list.txt");
    object.verarbeiteText(eingabe);
    }

else
        cout << "This file does not exist! Please check name." << endl;
}
//*****open file ENDE*****
//########################
//*****export new file****
*/

if (input=='e')
{
cout << "--- export new file ---" << endl;
    eingabe.open("pricelist.txt");
    object.verarbeiteText(eingabe);
    eingabe.close();
    //(öffne TXT)


    eingabe.open("mediacenter.xml");
    token=new ClToken;
   token->getToken(eingabe);
           token->druckeToken(object);


           cout << "3. Test -- (von der main aus)" << endl;//1 //object = Textobjekt, das übergeben wird

    eingabe.close();
    //(öffne XML)



    //Test:

//cout << "Id: " << object.getMovieId(6) << endl;


   }


cout << "Back to menu? (y/n)" << endl;
cin >> again;
} // while loop closed


} //main closed
