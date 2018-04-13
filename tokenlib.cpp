/*

 #######################
  Parser aus Vorlesung:
  (12.12.2017 - BSP 9)
  --------------------
  Druckfunktion
  (ab line 145):
 #######################

*/
#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include "token.h"
#include <string>

ClToken::ClToken()
{
*tokenName='\0';
tokenChild=NULL;
tokenSibling=NULL;
tokenInhalt=new char[1];
*tokenInhalt='\0';
}

int  ClToken::getToken(
ifstream              &datei)
{
int zaehler;
enum zustand zustand;
char zeichen;
char puffer[100];
ClToken *child;

cleanToken();

for (zaehler=0;;)
    {
    datei.get(zeichen);
    if (datei.eof())
       {
       if (*tokenName == '\0' && tokenChild == NULL && tokenInhalt == NULL)
          return fillToken(0);
       return fillToken(1);
       }
    switch(zeichen)
       {
    case '<':
       datei.get(zeichen);
       if (zeichen=='/')
          {
          zustand = istEndTag;
          if (zaehler!=0)
             {
             puffer[zaehler]='\0';
             tokenInhalt = new char[zaehler+1];
             strcpy(tokenInhalt,puffer);
             }
          }
       else
          {
          datei.putback(zeichen);
          if (*tokenName!='\0')
             {
                datei.putback('<');
                if (tokenChild==NULL)
                    {
                        tokenChild=new ClToken;
                        tokenChild->getToken(datei);
                    }
                //Fall: tokenSibling hinzugefügt:
                else
                    {
                    for (child=tokenChild;;child=child->tokenSibling)
                        {
                        if (child->tokenSibling==NULL)
                            {
                                child->tokenSibling=new ClToken;
                                child->tokenSibling->getToken(datei);
                                break;
                            }
                        }
                    }
             }
          else zustand=istStartTag;
          }
       zaehler=0;
       break;
    case '>':
       puffer[zaehler]='\0';
       if (zustand==istEndTag) return fillToken(1);
       if (zustand==istStartTag)
          {
          att.getAttList(puffer);
          strcpy(tokenName,puffer);
          }
       zaehler=0;
       break;
    case '\n':
            break;
    case '\t':
        if(zeichen=='\t') break;
            break;

    default:
       puffer[zaehler]=zeichen;
       zaehler++;
       break;
       }
    }
}

int ClToken::fillToken(
int                    mode)
{
if (*tokenName=='\0')
   strcpy(tokenName,"Unbekanntes Element");
if (tokenInhalt==NULL)
   {
   tokenInhalt=new char[1];
   *tokenInhalt='\0';
   }

return mode;
}

void ClToken::cleanToken(void)
{
*tokenName='\0';
if (tokenChild!=NULL)
   {
   delete tokenChild;
   tokenChild=NULL;
   }
if (tokenInhalt!=NULL)
   {
   delete tokenInhalt;
   tokenInhalt=NULL;
   }
}

/*
 ######################
  Druckfunktion:
 ######################
*/

void ClToken::druckeToken(ClText ObText, string datna) //ClText ObText ebene raus
{
/*
 ######################
  Versuche:
 ######################

    Test: Dateiname wird vorgegeben:
    newFile.open("newDATA.xml", ios::app);
    -->funktioniert !

    ---------------------------

    char neueDatei[30];
    ofstream fout;
    cout << "Name new file:" << endl;
    cin >> neueDatei;
    fout.open(neueDatei, ofstream::app);

    ----------------------------

    fout.open(dateiname);
    getline (cin, dateiname);
    dateiname += ".xml";
    schreibt nur erste Zeile in neue Datei

     ----------------------------

  -->durch Wiederholung wird Dateiname immer wieder abgefragt und nur eine Zeile gedruckt /überschrieben.
  Daher: Dateiname muss aus main-Fubktion übergeben werden.
 */

ofstream newFile;



string fullName;

fullName = datna + ".xml"; // Damit immer eine XML-Datei erstellt wird.
newFile.open(fullName.c_str(), ios::out | ios::app); //geöffnet bzw. angelegt falls noch nicht vorhanden
//nach jedem Durchlauf der Funktion soll der Inhalt hinzugefügt werden und die Dati nicht überschreiben.

//Fehlermeldeung, falls keine Datei erstellt wurde. (Dieser Falls sollte aber nicht eintreffen.):
if (!newFile)
    {
     cerr << "can't open output file" << endl;
    }

//Statt durch cout wird durch den Befehl des ofstreams (in dem Falle "newFile") der Inhalt in die Datei gedruckt:

newFile << "<" << name();

//Wenn Attribute vorhanden sind, werden sie gedruckt:
if (att.zahlAtt() > 0)
   {
     for (int i=0;i<att.zahlAtt();i++)
     {
       newFile << " " << att.zeigeAttName(i) << "="
            << '"' << att.zeigeAttWert(i) << '"' << '>';

//Metadaten aus TXT hinzufügen (Das Textobjekt wurde zuvor der Drukfunktion als Parameter übergeben):
       for(int j=0;j<=11;j++)
           {
           if (!strcmp(att.zeigeAttWert(i),ObText.getMovieId(j)))
               //IDs werden aus XML & TXT abgeglichen und somit an die richtige Stelle innerhalb der neuen Datei gedruckt.
               {
               newFile << "<meta>" << endl;
               newFile << "<medium>" << ObText.getMediumKind(j) << "</medium>" << endl;
               newFile << "<price>" << ObText.getPrice(j) << "</price>" << endl;
               newFile << "<stock>" << ObText.getStock(j) << "</stock>" << endl;
               newFile << "</meta>" << endl;
               }
           }
     }

   }

//neue Datei zunächst fehlerhaft, da:
//Starttags mit Attributen wurden doppelt geschlossen (">>") &
//Elternelement wurde erst am Ende geöffnet
//Fehlerbehebung:

else if (att.zahlAtt()==0)
{
newFile << ">";
    if (tokenChild!=NULL)
    {
       newFile << endl;
    }
}

newFile << tokenInhalt;


if (tokenChild!=NULL) tokenChild->druckeToken(ObText, datna);

newFile << "</" << name() << ">" << endl;

if (tokenSibling!=NULL) tokenSibling->druckeToken(ObText, datna);

//Wenn Kind- oder Geschwisterelemente vorhanden sind, beginnt der nächste Durchlauf der Druckfunktion.
//Wenn nicht, wird die Datei geschlossen:

newFile.close();


}

/*
 ####################
  Versuch (Suche):
 ####################
 */


void ClToken::search(string searchCat, string searchCon){


    cout << name() << ": " << inhalt() << endl;
    if (tokenSibling!=NULL) tokenSibling->search(searchCat, searchCon);

/*
//ifstream newFile;
//newFile.open(fullName.c_str(), ios::in);

if (searchCat==name() && searchCon==inhalt()){



        cout << name() << ": " << inhalt() << endl;

        for (int s=0;tokenSibling!=NULL;s++){

            cout << tokenSibling->tokenName[s] << ": " << tokenSibling->tokenInhalt[s] << endl;
        }



}
           //     else {cout << "not found" << endl;}
*/
}










