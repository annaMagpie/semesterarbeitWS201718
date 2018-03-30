#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include "token.h"

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
       if (zustand==istStartTag)
          {
          att.getAttList(puffer);
          strcpy(tokenName,puffer);
          }
       /*if (zustand==istEndTag)
       {

       }*/
       zaehler=0;
       break;
    case '\n':
       break;
   //Fehlerbehebung: (Fall Tab) funktioniert:
    case '\t':
        break;

    default:
       puffer[zaehler]=zeichen;
       zaehler++;
       break;
       }
    }
}

int ClToken::fillToken(int mode)
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

void ClToken::druckeToken(ClText ObText) //ClText ObText ebene raus
{
    //#################in datei drucken:
   // ofstream fileout;
   // fileout.open("NEWwriteBSP.txt"); //geöffnet bzw. angelegt falls noch nicht vorhanden
    //(couts in fileout ändern)
//#################


//ClToken *child;

    //###########ebene ausgetauscht durch Objekt deklariert in token.h damit über dieses XML Obj. Zugriff auf
    // Text Inhalt ########

//druckeTokenEbene(ebene); //rein
/* TEST:
 * cout << "Printfunc.: " << endl;
   cout << "ID: " << ObText.getMovieId(1) << endl;
   cout << "Medium: " << ObText.getMediumKind(1) << endl;
   cout << "Price: " << ObText.getPrice(1) << endl;
   cout << "Stock: " << ObText.getStock(1) << endl;*/

//cout << "<" << name() << "> " << inhalt();

    cout << "<" << name(); //z.B.: <movie


//attribute einfügen bevor Tag schließt:
if (att.zahlAtt() > 0)
   {
//druckeTokenEbene(ebene); //raus

   for (int i=0;i<att.zahlAtt();i++) {
       cout << " " << att.zeigeAttName(i) << "="
            << '"' << att.zeigeAttWert(i) << '"';



 /*// 2. Versuch: später einfügen!!!! (funktioniert)
       for(int j=0;j<7;j++) //j<13
           if (!strcmp(att.zeigeAttWert(i),ObText.getMovieId(j)))
       {
               //cout << "<ID: " << ObText.getMovieId(j) << ">" << endl;
               cout << "<meta>" << endl;
               cout << "<medium>" << ObText.getMediumKind(j) << "</medium>" << endl;
               cout << "<price>" << ObText.getPrice(j) << "</price>" << endl;
               cout << "<stock>" << ObText.getStock(j) << "</stock>" << endl;

               //hier nächstes Medium, Preis, Stock der gleichen ID einfügen (?)

               cout << "</meta>" << endl;
       }*/


//Test:
   //cout << "Id: " << ObText.getMovieId(j) << endl;
/*1. Versuch: (gescheitert, neuer Versuch s.o.^)

if (j == ObText.getMovieId(j))
{
cout << "ID: " << ObText.getMovieId(j) << endl;
cout << "Medium: " << ObText.getMediumKind(j) << endl;
cout << "Price: " << ObText.getPrice(i) << endl;
cout << "Stock: " << ObText.getStock(i) << endl;
}*/

} //for loop (att) closed

cout << ">";
   }

if (att.zahlAtt()==0) // > bereits oben bei att drin, hier (damit nicht bei att doppelt) so gelöst
    cout << ">";

cout << tokenInhalt; //inhalt()


//cout  <<"</" << tokenName << ">" <<  endl;


cout << "</" << tokenName << ">" <<  endl; // ebene




if (tokenChild!=NULL) tokenChild->druckeToken(ObText);

if (tokenSibling!=NULL) tokenSibling->druckeToken(ObText);



//Druckfunktion in neue Datei:

//########### in neue Datei drucken:
//fileout.close();
//return 0;
//###########

}

/*)
void ClToken::druckeTokenEbene(int ebene) //ebene =0
{
while (ebene > 0)
      {

    if (name()=="movie")
    {
        continue;
    }
    else{
      cout << "| ";
      ebene = ebene - 1;
}
      }

}

void ClToken::druckeTokenEbene(
int                            ebene)
{
while (ebene > 0)
      {
      cout << "| ";
      ebene = ebene - 1;
      }
}
*/


