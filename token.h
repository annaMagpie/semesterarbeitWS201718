#include "att.h"
#include "txt.h"

class ClToken
   {
public:
   ClToken();
   char *name() { return tokenName; }
   ClToken *child() { return tokenChild; }
   char *inhalt() { return tokenInhalt; }
   void druckeToken(ClText ObText); //int ebene
   int getToken(ifstream &datei);
   ClattToken att;

private:
   void cleanToken();
   //void druckeTokenEbene(int ebene); //raus
   int fillToken(int mode);
   char tokenName[64];
   ClToken *tokenChild;
   ClToken *tokenSibling;
   char *tokenInhalt;


   } ;

enum zustand { istStartTag, istEndTag } ;
